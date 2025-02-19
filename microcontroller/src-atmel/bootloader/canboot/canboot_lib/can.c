#include <avr/io.h>
#include <avr/pgmspace.h>

#include "../config.h"
#include "can.h"
#include "mcp2515reg.h"
#include "bootloader.h"

can_message Rx_msg, Tx_msg;

typedef uint16_t pgm_p_t;

#ifdef pgm_read_byte_far
	#undef pgm_read_byte
	#define pgm_read_byte(x) pgm_read_byte_far(0x10000l | (x))
#endif

/* MCP */
static void mcp_write_b(pgm_p_t stream) BOOTLOADER_SECTION;


// Functions

#define spi_release_ss() SPI_PORT |= _BV(SPI_PIN_SS)
#define spi_assert_ss() SPI_PORT &= ~_BV(SPI_PIN_SS)

static uint8_t spi_data(uint8_t c) __attribute__ ((noinline)) BOOTLOADER_SECTION;

static uint8_t spi_data(uint8_t c)
{
	SPDR = c;
	while (!(SPSR & _BV(SPIF)));
	return(SPDR);
}

void mcp_write(uint8_t reg, uint8_t data)
{
	spi_assert_ss();
	spi_data(WRITE);
	spi_data(reg);
	spi_data(data);
	spi_release_ss();
}

static void mcp_write_b(pgm_p_t stream)
{
	uint8_t len;

	while ((len = pgm_read_byte(stream++)))
	{
		spi_assert_ss();
		spi_data(WRITE);

		while (len--)
		{
			spi_data(pgm_read_byte(stream++));
		}
		spi_release_ss();
	}
}


//load a message to mcp2515 and start transmission
void can_transmit()
{
	uint8_t x;
	spi_assert_ss();

#ifdef MCP2510
	spi_data(WRITE);
	spi_data(TXB0SIDH);
#else
	spi_data(LOAD_TX_BUFFER);
#endif

	spi_data(((uint8_t) (Tx_msg.port_src << 2)) | (Tx_msg.port_dst >> 4));
	spi_data((uint8_t) ((Tx_msg.port_dst & 0x0C) << 3) | (1 << EXIDE) | (Tx_msg.port_dst & 0x03));
	spi_data(Tx_msg.addr_src);
	spi_data(Tx_msg.addr_dst);
	spi_data(Tx_msg.dlc);
	
	for (x = 0; x < Tx_msg.dlc; x++)
		spi_data(Tx_msg.data[x]);
	spi_release_ss();

	spi_assert_ss();
	spi_data(RTS + 1); // base addr + TXB0
	spi_release_ss();
}


//get a message from mcp2515 and disable RX interrupt Condition
static inline void message_fetch()
{
	uint8_t tmp1, tmp2, tmp3;
	uint8_t x;

	spi_assert_ss();

#ifdef MCP2510
	spi_data(READ);
	spi_data(RXB0SIDH);
#else
	spi_data(READ_RX_BUFFER);
#endif

	tmp1 = spi_data(0);
	Rx_msg.port_src = tmp1 >> 2;
	tmp2 = spi_data(0);
	tmp3 = (uint8_t)((uint8_t) (tmp2 >> 3) & 0x0C);
	Rx_msg.port_dst = ((uint8_t) (tmp1 << 4 ) & 0x30) | tmp3 | (uint8_t) (tmp2 & 0x03);

	Rx_msg.addr_src = spi_data(0);
	Rx_msg.addr_dst = spi_data(0);
	Rx_msg.dlc = spi_data(0) & 0x0F;
	for (x = 0; x < Rx_msg.dlc; x++)
		Rx_msg.data[x] = spi_data(0);
	spi_release_ss();

	//mcp_bitmod(CANINTF, _BV(RX0IF), 0x00); // only rx0 int is used so we can use write command
#ifdef MCP2510 // CANINTF is cleard by 'Read RX Buffer' instruction
	mcp_write(CANINTF, 0x00);
#endif
}


#define FLT_PORT_SRC 0
#define FLT_PORT_DST1 PORT_SDO_CMD
#define FLT_PORT_DST2 PORT_SDO_DATA
#define FLT_ADDR_SRC 0

#define MSK_PORT_SRC 0
#define MSK_PORT_DST 0x3F
#define MSK_ADDR_SRC 0
#define MSK_ADDR_DST 0xFF



/*******************************************************************/


// 0x01 : 125kbit/8MHz
// 0x03 : 125kbit/16MHz
// 0x04 : 125kbit/20MHz
#if F_MCP == 8000000
#define CNF1_T 0x01
#elif F_MCP == 16000000
#define CNF1_T 0x03
#elif F_MCP == 20000000
#define CNF1_T 0x04
#else
#error Can Baudrate is only defined for 8, 16 and 20 MHz
#endif


//uint8_t mcp_config_str1[] __attribute__ ((section (".progdata"))) = {
static const uint8_t mcp_config_str1[] PROGMEM = {
	2, BFPCTRL, 0x0C,		//RXBF Pins to Output
	4, CNF3,
		0x05,			//CNF3
		0xf1,			//CNF2
		0x40 | CNF1_T,		//CNF1
	2, RXB0CTRL,(0<<RXM1) | (0<<RXM0),
	9, RXF0SIDH,
		(FLT_PORT_SRC << 2) | (FLT_PORT_DST1 >> 4),
		((FLT_PORT_DST1 & 0x0C) << 3) | (1<<EXIDE) | (FLT_PORT_DST1 & 0x03),
		FLT_ADDR_SRC,
		0x35,
		(FLT_PORT_SRC << 2) | (FLT_PORT_DST2 >> 4),
		((FLT_PORT_DST2 & 0x0C) << 3) | (1<<EXIDE) | (FLT_PORT_DST2 & 0x03),
		FLT_ADDR_SRC,
		0x35,
	5, RXM0SIDH,
		(MSK_PORT_SRC << 2) | (MSK_PORT_DST >> 4),
		((MSK_PORT_DST & 0x0C) << 3) | (MSK_PORT_DST & 0x03),
		MSK_ADDR_SRC,
		MSK_ADDR_DST,
	0
};


//uint8_t mcp_config_str2[] __attribute__ ((section (".progdata"))) = {
static const uint8_t mcp_config_str2[] PROGMEM = {
	2, CANCTRL, 0,
	2, CANINTE, _BV(RX0IE),
	0
};

void can_init()
{
	//PORTB |= (1<<SPI_PIN_MISO); //MISO pullup for debugging

	//set output SPI pins to output
	#ifdef SPI_PIN_SS_AVR
		SPI_DDR |= _BV(SPI_PIN_MOSI) | _BV(SPI_PIN_SCK) | _BV(SPI_PIN_SS) | _BV(SPI_PIN_SS_AVR);
	#else
		SPI_DDR |= _BV(SPI_PIN_MOSI) | _BV(SPI_PIN_SCK) | _BV(SPI_PIN_SS);
	#endif

	#ifdef SPECIAL_CS
		SPECIAL_CS();
	#endif

	//set Slave select high
	spi_release_ss();
	SPCR = _BV(SPE) | _BV(MSTR);
	//Double speed on
	SPSR = _BV(SPI2X);

	spi_assert_ss();
	spi_data(RESET);
	spi_release_ss();

	mcp_write_b((pgm_p_t) mcp_config_str1);
	#ifdef GPIOR0
		mcp_write(RXF0EID0, GPIOR0);
		mcp_write(RXF1EID0, GPIOR0);
	#else
		mcp_write(RXF0EID0, Station_id);
		mcp_write(RXF1EID0, Station_id);
	#endif

	mcp_write_b((pgm_p_t) mcp_config_str2);
}


uint8_t can_get_nb()
{
	//check the pin, that the MCP's Interrup output connects to
	if (SPI_REG_PIN_MCP_INT & _BV(SPI_PIN_MCP_INT))
	{
		return 0; //no message
	}

	message_fetch();
	return 1;
}

