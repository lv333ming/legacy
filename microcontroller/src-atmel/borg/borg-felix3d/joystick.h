#ifndef JOYSTICK_H
#define JOYSTICK_H

extern unsigned char waitForFire;
inline void joy_init();

#define PORTJOYGND PORTB
#define DDRJOYGND DDRB
#define BITJOY0 PB0
#define BITJOY1 PB1

#define PORTJOYDIRS PORTD
#define DDRJOYDIRS DDRD
#define PINJOYDIRS PIND
#define BITUP PD4
#define BITDOWN PD5
#define BITLEFT PD6
#define BITRIGHT PD7
#define BITFIRE PD3

#define JOYUSE0() PORTJOYGND |= (1<<BITJOY1); PORTJOYGND &= ~(1<<BITJOY0);
#define JOYUSE1() PORTJOYGND |= (1<<BITJOY0); PORTJOYGND &= ~(1<<BITJOY1);

#define JOYISUP (!(PINJOYDIRS & (1<<BITUP)))
#define JOYISDOWN (!(PINJOYDIRS & (1<<BITDOWN)))
#define JOYISLEFT (!(PINJOYDIRS & (1<<BITLEFT)))
#define JOYISRIGHT (!(PINJOYDIRS & (1<<BITRIGHT)))
#define JOYISFIRE (!(PINJOYDIRS & (1<<BITFIRE)))

#endif // JOYSTICK_H
