/**
 * \defgroup Snake Snake, a casual game including a demo mode.
 *
 * @{
 */

/**
 * @file snake_game.c
 * @brief Implementation of the snake game.
 * @author Peter Fuhrmann, Martin Ongsiek, Daniel Otte, Christian Kroll
 */

#include <assert.h>
#include <stdint.h>
#include "../../config.h"
#include "../../compat/pgmspace.h"
#include "../../pixel.h"
#include "../../random/prng.h"
#include "../../util.h"
#include "../../joystick/joystick.h"
#include "../../menu/menu.h"
#include "snake_game.h"


#if defined MENU_SUPPORT && defined GAME_SNAKE
// snake icon (MSB is leftmost pixel)
static const uint8_t icon[8] PROGMEM =
	{0xff, 0x81, 0xbd, 0xa5, 0xa5, 0xad, 0xa1, 0xbf};

game_descriptor_t snake_game_descriptor __attribute__((section(".game_descriptors"))) =
{
	&snake_game,
	icon,
};
#endif


/**
 * If defined, joystick controls are NOT as "seen" by the snake but absolute,
 * that is, if pressing up, snake goes up, etc.
 */
#define SNAKE_NEWCONTROL

#if !defined USNAKE_MAX_LENGTH || defined DOXYGEN
	/** The maximum length of the snake. */
	#define USNAKE_MAX_LENGTH 64u
#endif

#if !defined SNAKE_MAX_APPLES || defined DOXYGEN
	/** The maximum number of apples lying on the playing field. */
	#define SNAKE_MAX_APPLES 10
#endif

#if !defined SNAKE_CYCLE_DELAY || defined DOXYGEN
	/** Delay (in ms) between every state change. */
	#define SNAKE_CYCLE_DELAY 100
#endif

#if !defined SNAKE_TERMINATION_DELAY || defined DOXYGEN
	/** Delay (in ms) between every disappearing pixel of a dying snake. */
	#define SNAKE_TERMINATION_DELAY 60
#endif

/** The color of the surrounding border. */
#define SNAKE_COLOR_BORDER 3
/** The color of the snake. */
#define SNAKE_COLOR_PROTAGONIST 3
/** The color of the apples. */
#define SNAKE_COLOR_APPLE 3


/**
 * Directions of the snake.
 */
enum snake_dir_e
{
	SNAKE_DIR_UP,   /**< Snake is heading up. */
	SNAKE_DIR_RIGHT,/**< Snake is heading right. */
	SNAKE_DIR_DOWN, /**< Snake is heading down. */
	SNAKE_DIR_LEFT, /**< Snake is heading left. */
	SNAKE_DIR_NONE  /**< Helper value for a "resting" joystick. */
};
#ifdef NDEBUG
	typedef uint8_t snake_dir_t;
#else
	typedef enum snake_dir_e snake_dir_t;
#endif

/**
 * This structure represents the snake character itself. It keeps track of the
 * snake's segments, its head and tail and the direction it is heading.
 */
typedef struct snake_protagonist_s
{
	pixel aSegments[USNAKE_MAX_LENGTH]; /**< All segments of the snake. */
	uint8_t nHeadIndex;                 /**< Index of the head segment. */
	uint8_t nTailIndex;                 /**< Index of the tail segment. */
	snake_dir_t dir;                    /**< Direction of the snake.    */
} snake_protagonist_t;


/**
 * This structure keeps track of all apples which are on the playing field.
 */
typedef struct snake_apples_s
{
	pixel aApples[SNAKE_MAX_APPLES]; /**< Positions of all existing apples. */
	uint8_t nAppleCount;             /**< Count of currently existing apples. */
} snake_apples_t;


/**
 * This function returns the next position which is calculated from a given
 * (current) position and a direction.
 * @param pxNext The position we're going to leave.
 * @param dir The direction that we are heading.
 * @return The next position according the given direction.
 */
static pixel snake_nextDirection(pixel const pxNext,
                                 snake_dir_t const dir)
{
	assert(dir < 4);
	static int8_t const nDelta[] = {0, -1, 0, 1, 0};
	return (pixel){pxNext.x + nDelta[dir], pxNext.y + nDelta[dir + 1]};
}


/**
 * This function draws a border around the playing field.
 */
static void snake_drawBorder(void)
{
#if NUM_COLS == NUM_ROWS
	for (uint8_t i = NUM_COLS; i--;)
	{
		setpixel((pixel){i, 0}, SNAKE_COLOR_BORDER);
		setpixel((pixel){i, NUM_ROWS - 1}, SNAKE_COLOR_BORDER);
		setpixel((pixel){0, i}, SNAKE_COLOR_BORDER);
		setpixel((pixel){NUM_COLS -1, i}, SNAKE_COLOR_BORDER);
	}
#else
	for (uint8_t x = NUM_COLS; x--;)
	{
		setpixel((pixel){x, 0}, SNAKE_COLOR_BORDER);
		setpixel((pixel){x, NUM_ROWS - 1}, SNAKE_COLOR_BORDER);
	}
	for (uint8_t y = NUM_ROWS; y--;)
	{
		setpixel((pixel){0, y}, SNAKE_COLOR_BORDER);
		setpixel((pixel){NUM_COLS - 1, y}, SNAKE_COLOR_BORDER);
	}
#endif
}

#ifdef GAME_SNAKE
/**
 * This function translates hardware port information into joystick directions.
 * @return The current direction of the joystick.
 * @see snake_dir_e
 */
static snake_dir_t snake_queryJoystick(void)
{
	snake_dir_t dirJoystick;
	if (JOYISUP)
	{
		dirJoystick = SNAKE_DIR_UP;
	}
	else if (JOYISRIGHT)
	{
		dirJoystick = SNAKE_DIR_RIGHT;
	}
	else if (JOYISDOWN)
	{
		dirJoystick = SNAKE_DIR_DOWN;
	}
	else if (JOYISLEFT)
	{
		dirJoystick = SNAKE_DIR_LEFT;
	}
	else
	{
		dirJoystick = SNAKE_DIR_NONE;
	}

	return dirJoystick;
}
#endif

/**
 * This function initializes the structure which represents the snake itself.
 * @param pprotSnake The pointer the protagonist structure to be initialized.
 */
static void snake_initGameProtagonist(snake_protagonist_t *pprotSnake)
{
	pprotSnake->aSegments[0] = (pixel){NUM_COLS / 2, NUM_ROWS / 2};
	pprotSnake->aSegments[1] = (pixel){NUM_COLS / 2, NUM_ROWS / 2 - 1};
	pprotSnake->nTailIndex = 0;
	pprotSnake->nHeadIndex = 1;
	pprotSnake->dir = SNAKE_DIR_UP;
}

#ifdef GAME_SNAKE
/**
 * Determines the next direction of the snake depending on the joystick's input.
 * @param pprotSnake A pointer to the structure of the protagonist.
 * @param pdirLast Last joystick direction to recognize prolonged key presses.
 */
static void snake_userControl(snake_protagonist_t *pprotSnake,
                              snake_dir_t *pdirLast)
{
	snake_dir_t dirJoystick = snake_queryJoystick();
#ifdef SNAKE_NEWCONTROL
	if (dirJoystick != SNAKE_DIR_NONE)
	{
		// valid transitions can only be uneven
		if ((pprotSnake->dir + dirJoystick) & 0x01)
		{
			pprotSnake->dir = dirJoystick;
		}
	}
#else
	if ((dirJoystick ^ *pdirLast) && (dirJoystick != SNAKE_DIR_NONE))
	{
		// only left or right movements are valid
		if (dirJoystick & 0x01)
		{
			// rotate through directions (either clockwise or counterclockwise)
			pprotSnake->dir = (pprotSnake->dir +
					(dirJoystick == SNAKE_DIR_LEFT ? 3 : 1)) % 4u;
		}
	}
	*pdirLast = dirJoystick;
#endif
}
#endif


#ifdef ANIMATION_SNAKE
/**
 * This function approximates the next direction which may lead to an apple
 * (with a particular probability).
 * @param pprotSnake A pointer to the hungry protagonist.
 * @param pApples A pointer to a bunch of apples.
 */
static void snake_autoRoute(snake_protagonist_t *pprotSnake,
                            snake_apples_t *pApples)
{
	pixel pxHead = pprotSnake->aSegments[pprotSnake->nHeadIndex];
	if (random8() < 80)
	{
		uint8_t nNextApple = 0;
		if (pApples->nAppleCount)
		{
			uint8_t nMinDist = UINT8_MAX;
			for (uint8_t i = 0; i < pApples->nAppleCount; ++i)
			{
				uint8_t nDistX;
				if (pxHead.x > pApples->aApples[i].x)
				{
					nDistX = pxHead.x - pApples->aApples[i].x;
				}
				else
				{
					nDistX = pApples->aApples[i].x - pxHead.x;
				}

				uint8_t nDistY;
				if (pxHead.y > pApples->aApples[i].y)
				{
					nDistY = pxHead.y - pApples->aApples[i].y;
				}
				else
				{
					nDistY = pApples->aApples[i].y - pxHead.y;
				}

				if ((nDistX + nDistY) < nMinDist)
				{
					nMinDist = nDistX + nDistY;
					nNextApple = i;
				}
			}
			if (pprotSnake->dir ^ 0x01) // vertical direction?
			{
				pprotSnake->dir = pApples->aApples[nNextApple].x > pxHead.x ?
						SNAKE_DIR_LEFT : SNAKE_DIR_RIGHT;
			}
			else
			{
				pprotSnake->dir = pApples->aApples[nNextApple].y > pxHead.y ?
						SNAKE_DIR_DOWN : SNAKE_DIR_UP;
			}
		}
	}

	for (uint8_t i = 0; i < 4; ++i)
	{
		pixel pxTest = snake_nextDirection(pxHead, pprotSnake->dir);
		if (get_pixel(pxTest))
		{
			for (uint8_t j = 0; j < pApples->nAppleCount; ++j)
			{
				if ((pxTest.x == pApples->aApples[j].x) &&
						(pxTest.y == pApples->aApples[j].y))
				{
					return;
				}
			}
			pprotSnake->dir = (pprotSnake->dir + 1u) % 4u;
		}
		else
		{
			break;
		}
	}
}
#endif


/**
 * Small animation that lets the dying snake disappear piece by piece.
 * @param pprotSnake A pointer to the dying snake.
 */
static void snake_eliminateProtagonist(snake_protagonist_t *pprotSnake)
{
	while (pprotSnake->nTailIndex != pprotSnake->nHeadIndex)
	{
		clearpixel(pprotSnake->aSegments[pprotSnake->nTailIndex++]);
		pprotSnake->nTailIndex %= USNAKE_MAX_LENGTH;
		wait(SNAKE_TERMINATION_DELAY);
	}
}


/**
 * Initializes the structure that keeps track of all currently existing apples.
 * @param pApples Pointer to the set of apples in question.
 */
static void snake_initApples(snake_apples_t *pApples)
{
	pApples->nAppleCount = 0;
}


/**
 * Checks for an apple at a given position and removes it if there is one.
 * @param pApples The set of apples which are lying on the playing field.
 * @param pxHead The position to be tested.
 * @return 0 if no apples were found, 1 otherwise
 */
static uint8_t snake_checkForApple(snake_apples_t *pApples, pixel pxHead)
{
	for (uint8_t i = pApples->nAppleCount; i--;)
	{
		if ((pxHead.x == pApples->aApples[i].x) &&
				(pxHead.y == pApples->aApples[i].y))
		{
			for (; i < pApples->nAppleCount; ++i)
			{
				pApples->aApples[i] = pApples->aApples[i + 1];
			}
			--pApples->nAppleCount;
			return 1;
		}
	}
	return 0;
}


/**
 * Creates some new apples from time to time.
 * @param pApples Pointer to a set of apples.
 */
static void snake_spawnApples(snake_apples_t *pApples)
{
	if ((pApples->nAppleCount < SNAKE_MAX_APPLES) && (random8() < 10))
	{
		pixel pxApple = (pixel){(random8() % (NUM_COLS-2)) + 1,
								   (random8() % (NUM_ROWS - 2)) + 1};
		if (!get_pixel(pxApple))
		{
			pApples->aApples[pApples->nAppleCount++] = pxApple;
		}
	}
}


/**
 * The main loop (plus initialization) that both drives the game and the
 * demo mode.
 * @param bDemoMode 0 indicates game mode, 1 indicates demo mode
 */
void snake_engine(uint8_t bDemoMode)
{
	// init
	snake_protagonist_t protSnake;
	snake_initGameProtagonist(&protSnake);
	snake_apples_t apples;
	snake_initApples(&apples);
	snake_dir_t dirLast = SNAKE_DIR_NONE;

	// init screen
	clear_screen(0);
	snake_drawBorder();

	for (uint8_t nAppleColor = 0; 1; nAppleColor ^= SNAKE_COLOR_APPLE)
	{
		// determine new direction
#if defined ANIMATION_SNAKE && defined GAME_SNAKE
		if (bDemoMode)
		{
			snake_autoRoute(&protSnake, &apples);
		}
		else
		{
			snake_userControl(&protSnake, &dirLast);
		}
#elif defined ANIMATION_SNAKE
		snake_autoRoute(&protSnake, &apples);
#else
		snake_userControl(&protSnake, &dirLast);
#endif

		// actually move head
		pixel pxOldHead = protSnake.aSegments[protSnake.nHeadIndex];
		protSnake.nHeadIndex = (protSnake.nHeadIndex + 1u) % USNAKE_MAX_LENGTH;
		protSnake.aSegments[protSnake.nHeadIndex] =
				snake_nextDirection(pxOldHead, protSnake.dir);

		// look if we have found an apple
		if (!snake_checkForApple(&apples,
				protSnake.aSegments[protSnake.nHeadIndex]))
		{
			// quit game if we hit something which is not an apple
			if (get_pixel(protSnake.aSegments[protSnake.nHeadIndex]))
			{
				snake_eliminateProtagonist(&protSnake);
				return;
			}

			// remove last segment
			clearpixel(protSnake.aSegments[protSnake.nTailIndex])
			protSnake.nTailIndex =
					(protSnake.nTailIndex + 1u) % USNAKE_MAX_LENGTH;

			// new apples
			snake_spawnApples(&apples);
		}
		// draw new head
		setpixel(protSnake.aSegments[protSnake.nHeadIndex],
				SNAKE_COLOR_PROTAGONIST);

		// draw apples
		for (uint8_t i = apples.nAppleCount; i--;)
		{
			setpixel(apples.aApples[i], nAppleColor);
		}

		wait(SNAKE_CYCLE_DELAY);
	}
}

/**
 * Snake in game mode.
 */
void snake_game(void)
{
	snake_engine(0);
}

/*@}*/
