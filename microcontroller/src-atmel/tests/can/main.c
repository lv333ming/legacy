
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>
#include <stdlib.h>

#include "config.h"

#include "util.h"
#include "uart.h"
#include "spi.h"
#include "can.h"

// Timer Interrupt
SIGNAL(SIG_OUTPUT_COMPARE0)
{
	static int count = 0;
	static char z = 0;

	if ( count++ > 0x40 ) {
		count = 0;
		PORTC ^= 0x08;

		can_message *msg = can_buffer_get();

		msg->addr_src  = 0x11;
		msg->addr_dst  = 0x22;
		msg->port_src  = 0x01;
		msg->port_dst  = 0x02;
		msg->dlc       = 4;
		msg->data[0]   = z++;

		can_transmit(msg);
	}
}

void timer0_on(){
/* 	TCCR0: FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
		CS02 CS01 CS00
		 0    0    0	       stop
		 0    0    1       clk
		 0    1    0       clk/8
		 0    1    1       clk/64
		 1    0    0       clk/256
		 1    0    1       clk/1024
	
*/
	TCCR0 = 0x08 | 0x05 ;// CTC Mode, clk/1024
	TCNT0 = 0;	// reset timer
	OCR0  = 0xff;	// Compare with this value
	TIMSK = 0x02;	// Compare match Interrupt on
}


int main(){
	uart_init();
	spi_init();
	can_init();
	can_setmode(normal);

	sei();
	DDRC = 0xff;

	uart_putc('*');

	timer0_on();

	while(1) {
		can_message *msg = can_get();

		uart_putstr("\r\n");
		uart_hexdump(msg, 16 );
	}

	return 0;
}
