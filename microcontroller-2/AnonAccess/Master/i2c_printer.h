/* i2c_printer.h */
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


#ifndef I2C_PRINTER_H_
#define I2C_PRINTER_H_

#include "config.h"
#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "mcp23017.h"
#include "i2c.h"
#include "i2c_tools.h"

void printer_char(char c);
void printer_str(const char *str);
void printer_str_P(PGM_P str);
void printer_hexdump(const void* buffer, uint16_t length);
void printer_reset(void);
void printer_init(void);


#endif /*I2C_PRINTER_H_*/
