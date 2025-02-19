/* ui_primitives.h */
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


#ifndef UI_PRIMITIVES_H_
#define UI_PRIMITIVES_H_

#include <stdint.h>
#include <avr/pgmspace.h>
#include "rtc.h"

/* we use a integer instead of void* 'cause the compiler keepr rumoring about 
 * data_ptr <-> func_ptr conversation 
 */
typedef uint16_t superp;

typedef struct menu_st{
	PGM_P name;                 /* 2 byte */
	enum {none, 
		  autosubmenu,
		  submenu, 
		  execute, 
		  back, 
		  terminator} options;  /* 1 byte*/
	superp x;                   /* 2 byte */
} menu_t;

typedef enum {none_st, flash_st, stack_st, heap_st, ram_st, copy_st} storage_type_t;
typedef enum {success_st=0, failed_st=1, processing_st=2, informative_st} state_t;	

#define UI_SUCCESS_CHAR    0xE8 /* normaly a sqrt symbol */
#define UI_FAILED_CHAR     '!'
#define UI_PROCESSING_CHAR '*'
#define UI_INFORMATIVE_CHAR 'i'


typedef struct ui_loglist_entry_st{
	storage_type_t storage_type;
	state_t state;
	void* str;	
} ui_loglist_entry_t;

typedef struct ui_loglist_st{
	uint8_t entrysn;
	uint8_t idx;
	void (*free)(ui_loglist_entry_t* e);
	ui_loglist_entry_t* entrys;
} ui_loglist_t;

#define LCD_LABORLOGO     7
#define LCD_RADIOSELECT   5
#define LCD_CHECKSELECT   6
#define LCD_RADIONOSELECT 'o'
#define LCD_CHECKNOSELECT 0xDB

#define LCD_FULLCHAR  255
#define LCD_EMPTYCHAR  ' '
#define LCD_RARROW 0x7E
#define LCD_LARROW 0x7F

#define NO_KEY     ' '
#define ENTER_KEY  'F'
#define SELECT_KEY 'E'
#define UP_KEY     '0'
#define DOWN_KEY   'C'
#define CORRECT_KEY 'C'

extern char ui_statusstring[6];

void    ui_primitives_init(void);
void    ui_progressbar(  double percent, uint8_t xpos, uint8_t ypos, uint8_t width);
uint8_t ui_radioselect(  uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, const char* opts);
uint8_t ui_radioselect_P(uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, PGM_P opts);
void    ui_checkselect(  uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height ,const char* opts, uint8_t* config);
void    ui_checkselect_P(uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, PGM_P opts, uint8_t* config);
void    ui_menuexec(menu_t* menu);
void    ui_drawframe(   uint8_t posx, uint8_t posy, uint8_t width, uint8_t height, char framechar);
void    ui_hexdump(     uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, const volatile void* data, uint16_t length);
void    ui_hexdump_P(   uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, PGM_VOID_P data, uint16_t length);
void    ui_textwindow(  uint8_t posx, uint8_t posy, uint8_t width, uint8_t height, char* text);
void    ui_textwindow_P(uint8_t posx, uint8_t posy, uint8_t width, uint8_t height, PGM_P text);

char    ui_waitforkeypress(void);
char    ui_waitforkeypresswhile(void(*fpt)(void*), void* param);
char    ui_waitforkeypresstimed(timestamp_t* tdiff);
void    ui_waitforkey(char key);

uint8_t read_decimaln(uint8_t xpos, uint8_t ypos, char* str, uint8_t n);
uint8_t read_pinn(uint8_t xpos, uint8_t ypos, char disp,char* str, uint8_t n);
uint8_t read_hexn(uint8_t xpos, uint8_t ypos, char* str, uint8_t n);
uint8_t read_strn(uint8_t xpos, uint8_t ypos, PGM_P charset,char * str, uint8_t n);
uint8_t read_strnwhile(uint8_t xpos, uint8_t ypos, PGM_P charset, 
                       char * str, uint8_t n, void(*fpt)(void*), void* param);

void genaddr(uint16_t value, char* str, uint8_t len);
void data2hex(const void* buffer, char* dest, uint8_t length);
void data2hex_P(PGM_VOID_P buffer, char* dest, uint8_t length);

void    ui_printstatusline(void);

void lcd_writeB64(void* data, uint16_t length);
void lcd_writelinen(const char* text, uint16_t length);
void lcd_writelinen_P(PGM_P text, uint16_t length);
void lcd_writeB64long(uint8_t xpos, uint8_t ypos, uint8_t width, void* data, uint16_t length);

void    ui_loginit(ui_loglist_t* log, uint8_t size);
void    ui_logrm(ui_loglist_t* log);
void    ui_logfree(ui_loglist_t* log);
uint8_t ui_logappend(ui_loglist_t* log, void* str, storage_type_t st, state_t state);
void    ui_logchangelaststate(ui_loglist_t* log, state_t state);
ui_loglist_entry_t* ui_logget(ui_loglist_t* log, uint8_t index);
uint8_t ui_logactcount(ui_loglist_t* log);
void    ui_logprint(uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, ui_loglist_t* log);
void ui_logreader(uint8_t xpos, uint8_t ypos, uint8_t width, uint8_t height, ui_loglist_t* log);


int8_t ui_keyortimeout(uint16_t timeout);

#endif /*UI_PRIMITIVES_H_*/
