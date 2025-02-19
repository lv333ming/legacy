
#include <avr/wdt.h>
#include <avr/io.h>
#include <avr/eeprom.h>

#include <avrx-io.h>
#include <avrx-signal.h>
#include <string.h>

#include "avrx.h"               // AvrX System calls/data structures

#include "config.h"
#include "spi.h"
#include "xcan.h"
#include "lap.h"


uint8_t myaddr;
unsigned int klight_stat = 0;

static can_message_t msg = {0, 0, PORT_MGT, PORT_MGT, 1, {FKT_MGT_PONG}};
	
void process_mgt_msg()
{
	switch(rx_msg.data[0])
	{
		case FKT_MGT_RESET:
			wdt_enable(0);
			while(1);
		case FKT_MGT_PING:
			msg.addr_dst = rx_msg.addr_src;
			can_put(&msg);
			break;
	}
}

AVRX_GCC_TASKDEF(laptask, 50, 3)
{
    while (1)
    {
		can_get();			//get next canmessage in rx_msg
		if (rx_msg.addr_dst == myaddr)
		{
			if (rx_msg.port_dst == PORT_MGT)
			{
				process_mgt_msg();
			}
		}
		else
		if ((rx_msg.addr_dst == 0x02) && (rx_msg.port_dst == 0x01) && (rx_msg.data[0] == 0x00) && (rx_msg.data[1] == 0x00))
		{
			if (rx_msg.data[2] == 0x01)
			{
				klight_stat = 1;
				PORTC |= _BV(PC3);
				PORTC &= ~_BV(PC4);
			}
			else if (rx_msg.data[2] == 0x00)
			{
				klight_stat = 0;
				PORTC |= _BV(PC4);
				PORTC &= ~_BV(PC3);
			}
		}
    }
};

void xlap_init()
{
	myaddr = eeprom_read_byte(0x00);
	msg.addr_src = myaddr;
	spi_init();
	can_init();
}
