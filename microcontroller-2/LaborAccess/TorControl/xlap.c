#include <avr/wdt.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <string.h>

#include "avrx.h"               // AvrX System calls/data structures

#include "config.h"
#include "spi.h"
#include "xcan.h"
#include "lap.h"

#include "fifo.h"
#include "rf.h"

uint8_t myaddr;

void process_sdo_message(){
}

void process_mgt_msg(){
	static can_message_t msg = {0, 0, PORT_MGT, PORT_MGT, 1, {FKT_MGT_PONG}};
	switch(rx_msg.data[0]){
		case FKT_MGT_RESET:
			wdt_enable(0);
			while(1);
		case FKT_MGT_PING:
			msg.addr_src = myaddr;
			msg.addr_dst = rx_msg.addr_src;
			can_put(&msg);
			break;
	}	
}

void process_remote_msg(){
	AvrXPutFifo(rftxfifo, *(uint32_t*)rx_msg.data);
}

void process_gate_msg(){
	if(!memcmp(rx_msg.data, (uint8_t[]){0xde,0xad,0xbe,0xef}, 4)){
		AvrXPutFifo(rftxfifo, 0x010050B5); //Tor auf 101101010101  B55
	}
}

AVRX_GCC_TASKDEF(laptask, 50, 3) /* name, stackspace, pri */
{
    while (1)
    {
		can_get();			//get next canmessage in rx_msg
		if(rx_msg.addr_dst == myaddr){
			if(rx_msg.port_dst == PORT_MGT){
				process_mgt_msg();	
			}else if(rx_msg.port_dst == PORT_REMOTE){
				process_remote_msg();
			}else if(rx_msg.port_dst == PORT_GATE){
				process_gate_msg();
			}
		}
    }
};

void xlap_init(){
	myaddr = eeprom_read_byte(0x00);
	spi_init();
	can_init();
}
