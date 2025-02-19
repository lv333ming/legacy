/* shabea.c */
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
 * \file	shabea.c
 * \author	Daniel Otte 
 * \date	2007-06-07
 * \brief	SHABEA - a SHA Based Encryption Algorithm implementation
 * \par License	
 * GPL
 * 
 * SHABEAn-r where n is the blocksize and r the number of round used
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>
#include "sha256.h"

#include "config.h"
#include "uart.h"
#include "debug.h"
#include "memxor.h"


/*
 * SHABEA256-n
 */ 
 
#define BLOCKSIZE 256
#define BLOCKSIZEB (BLOCKSIZE/8)
#define HALFSIZEB  (BLOCKSIZEB/2)
#define HALFSIZE (BLOCKSIZE/2)

#define L ((uint8_t*)block+ 0)
#define R ((uint8_t*)block+16)
void shabea256(void * block, void * key, uint16_t keysize_b, uint8_t enc, uint8_t rounds){
	int8_t r;		/**/
	uint8_t tb[HALFSIZEB+2+(keysize_b+7)/8];	/**/
	uint16_t kbs;	/* bytes used for the key / temporary block */
	sha256_hash_t hash;
	
	r = (enc?0:(rounds-1));
	kbs = (keysize_b+7)/8;
	memcpy(tb+HALFSIZEB+2, key, kbs); /* copy key to temporary block */
	tb[HALFSIZEB+0] = 0;	/* set round counter high value to zero */
	
	for(;r!=(enc?(rounds):-1);enc?r++:r--){ /* enc: 0..(rounds-1) ; !enc: (rounds-1)..0 */
		memcpy(tb, R, HALFSIZEB); /* copy right half into tb */
		tb[HALFSIZEB+1] = r;
		sha256(&hash, tb, HALFSIZE+16+keysize_b);
		if(!(r==(enc?(rounds-1):0))){	
			/* swap */
			memxor(hash, L, HALFSIZEB);
			memcpy(L, R, HALFSIZEB);
			memcpy(R, hash, HALFSIZEB);
		} else {
			/* no swap */
			memxor(L, hash, HALFSIZEB);	
		}
	}
}


