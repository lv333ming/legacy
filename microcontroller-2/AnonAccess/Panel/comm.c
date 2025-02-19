/* comm.c */
/*
 *   This file is part of AnonAccess, an access system which can be used
 *    to open door or doing other things with an anonymity featured
 *    account managment.
 *   Copyright (C) 2006, 2007, 2008  Daniel Otte (daniel.otte@rub.de)
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 * 
 * 
 * 
 * 
 * 
 * 
 */
 
#include "config.h"
#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include "lop.h"
#include "lop_debug.h"
#include "types.h"
#include "sha256.h"
#include "comm.h"
#include "system_stats.h"
#include "lcd_tools.h"

extern lop_ctx_t lop1;
volatile uint8_t msg_wait;
volatile uint16_t msg_length;
volatile void* msg_data;

const char str_class_char_P[] PROGMEM = {'#','i','w','E','X', 'd'};

void session_init(void){
	//lop_reset(&lop1);
	uint8_t msg[3]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_SESSION_INIT
	};
	lcd_gotopos(1,1);
	lcd_writechar('x');
	lop_sendmessage(&lop1, 3, msg);
	lcd_gotopos(1,1);
	lcd_writechar('y');
} 
 
void submit_ab(authblock_t * ab, uint8_t admin){
	uint8_t msg[3+sizeof(authblock_t)+1]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ADD_AB,
		0
	};
	memcpy(&(msg[3]), ab, sizeof(authblock_t));
	msg[3+sizeof(authblock_t)]=admin?1:0;
	lop_sendmessage(&lop1, 3+sizeof(authblock_t)+1, msg);
}

void submit_pin(char* pin, uint16_t length_B){
	uint8_t msg[3+sizeof(sha256_hash_t)]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_AB_PINREPLY,
		0
	};
	sha256((sha256_hash_t*)((uint8_t*)msg+3), pin, length_B*8);
	lop_sendmessage(&lop1, 3+32, msg);
}


void send_mainopen(void){
	uint8_t msg[4]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ACTION,
		ACTION_MAINOPEN
	};
	lop_sendmessage(&lop1, 4, msg);
}

void send_mainclose(void){
	uint8_t msg[4]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ACTION,
		ACTION_MAINCLOSE
	};
	lop_sendmessage(&lop1, 4, msg);
} 

void send_getstat(void){
	uint8_t msg[4]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ACTION,
		ACTION_GETSTATS
	};
	lop_sendmessage(&lop1, 4, msg);
}


void send_getinfo(void){
	uint8_t msg[4]={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ACTION,
		ACTION_GETSTATS
	};
	lop_sendmessage(&lop1, 4, msg);
}

void req_bootab(char* name, char* pin, uint16_t pinlen_B, uint8_t anon, uint8_t pinflags){
	uint16_t len;
	len = strlen(name);
	if(len>=256){
		len=255;
	}
	uint8_t msg[3+1+len+sizeof(sha256_hash_t)+1+1]; /*={
		MASTERUNIT_ID,
		TERMINALUNIT_ID,
		MSGID_ADD_BOOTSTRAP,
		0
	};*/
	msg[0]=MASTERUNIT_ID;
	msg[1]=TERMINALUNIT_ID;
	msg[2]=MSGID_ADD_BOOTSTRAP;
	msg[3]=(uint8_t)len;
	memcpy(&(msg[4]), name, len);
	sha256((sha256_hash_t*)&(msg[3+1+len]),pin, pinlen_B*8);
	msg[3+1+len+sizeof(sha256_hash_t)]=anon?1:0;
	msg[3+1+len+sizeof(sha256_hash_t)+1]=pinflags&3;
	lop_sendmessage(&lop1, sizeof(msg), msg);
}

uint8_t waitformessage(uint16_t timeout){
	msg_wait=1;
	while(msg_wait && timeout){
		--timeout;
		_delay_ms(1);
	}
	msg_wait=0;	
	if(timeout==0)
		return 1;	
	if(msg_data==0)
		return 2;
	return 0;
}

void freemsg(void){
	if(msg_data)
		free((void*)msg_data);
	msg_length=0;
}

uint8_t getmsgid(const volatile void* msg){
	return ((uint8_t*)msg)[2];
}
