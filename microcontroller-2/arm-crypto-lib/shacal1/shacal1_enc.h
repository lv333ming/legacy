/* shacal1_enc.h */
/*
    This file is part of the ARM-Crypto-Lib.
    Copyright (C) 2008  Daniel Otte (daniel.otte@rub.de)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SHACAL1_ENC_H_
#define SHACAL1_ENC_H_

#include <stdint.h>

#define SHACAL1_BLOCKSIZE 160
#define SHACAL1_BLOCKSIZE_B ((SHACAL1_BLOCKSIZE+7)/8)
#define SHACAL1_KEYSIZE 512
#define SHACAL1_KEYSIZE_B ((SHACAL1_KEYSIZE+7)/8)

void shacal1_enc(void* buffer, void* key, uint16_t keysize_b);

#endif /*SHACAL1_ENC_H_*/
