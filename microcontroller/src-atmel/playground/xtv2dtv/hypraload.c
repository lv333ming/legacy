#include <avr/pgmspace.h>

uint8_t programm[] PROGMEM = {
	0xb,0x8,0xc0,0x7,0x9e,0x33,0x32,0x33,0x38,0,0,0,0x20,0x2f,0xf3,0xa9,
	0xe2,0xa2,0xf8,0x85,0xa7,0x86,0xa8,0xa9,0,0xa2,0x3,0x85,0xa9,0x86,0xaa,0xa9,
	0x8,0x20,0xc,0xed,0xa9,0x6f,0x20,0xb9,0xed,0xa9,0x4d,0x20,0xdd,0xed,0xa9,0x2d,
	0x20,0xdd,0xed,0xa9,0x57,0x20,0xdd,0xed,0xa0,0,0xa5,0xa9,0x20,0xdd,0xed,0xa5,
	0xaa,0x20,0xdd,0xed,0xa9,0x1e,0x20,0xdd,0xed,0xb1,0xa7,0x20,0xdd,0xed,0xc8,0xc0,
	0x1e,0x90,0xf6,0x20,0xfe,0xed,0x18,0xa5,0xa7,0x69,0x1e,0x85,0xa7,0x90,0x3,0xe6,
	0xa8,0x18,0xa5,0xa9,0xa6,0xaa,0x69,0x1e,0x85,0xa9,0x90,0x2,0xe6,0xaa,0xe0,0x5,
	0x90,0xad,0xc9,0,0x90,0xa9,0xa9,0x8,0x20,0xc,0xed,0xa9,0x6f,0x20,0xb9,0xed,
	0xa9,0x4d,0x20,0xdd,0xed,0xa9,0x2d,0x20,0xdd,0xed,0xa9,0x45,0x20,0xdd,0xed,0xa9,
	0x8b,0x20,0xdd,0xed,0xa9,0x4,0x20,0xdd,0xed,0xa9,0xb,0x8d,0x11,0xd0,0x20,0xfb,
	0xed,0xea,0xea,0x4c,0x2e,0xf0,0xa9,0xb,0x8d,0,0xdd,0x2c,0,0xdd,0x10,0xfb,
	0xa9,0x3,0x8d,0,0xdd,0xa2,0x5,0xca,0xea,0xd0,0xfc,0xa2,0x4,0xad,0,0xdd,
	0x2a,0x2a,0x66,0xb0,0x6a,0x66,0xb0,0xea,0xca,0xd0,0xf2,0xa5,0xb0,0x49,0xff,0x60,
	0x20,0x52,0xef,0xc9,0xff,0xf0,0xf8,0xa0,0,0xa9,0xb,0x8d,0,0xdd,0x2c,0,
	0xdd,0x10,0xfb,0xa9,0x3,0x8d,0,0xdd,0xa2,0x7,0xca,0xd0,0xfd,0xad,0,0xdd,
	0x2a,0x2a,0x66,0xb0,0x6a,0x66,0xb0,0xea,0xea,0xad,0,0xdd,0x2a,0x2a,0x66,0xb0,
	0x6a,0x66,0xb0,0xea,0xea,0xad,0,0xdd,0x2a,0x2a,0x66,0xb0,0x6a,0x66,0xb0,0xea,
	0xea,0xad,0,0xdd,0x2a,0x2a,0x66,0xb0,0x6a,0x66,0xb0,0xa5,0xb0,0x49,0xff,0x99,
	0xa6,0xfb,0xc8,0xd0,0xb4,0x60,0x78,0xa9,0x1,0x85,0xa7,0xa0,0xff,0x20,0x7c,0xef,
	0xc0,0xff,0xf0,0x40,0xa2,0x2,0xa5,0xa7,0xf0,0x2,0xa2,0x4,0xad,0xa6,0xfb,0xd0,
	0x7,0xee,0xa7,0xfb,0xad,0xa7,0xfb,0x2c,0xa9,0,0x85,0xa8,0xbd,0xa6,0xfb,0x91,
	0xae,0xe6,0xae,0xd0,0x2,0xe6,0xaf,0xe8,0xe4,0xa8,0xd0,0xf0,0xa2,0,0x86,0xa7,
	0xad,0xa6,0xfb,0xd0,0xc6,0xa9,0x35,0x85,0x1,0xa9,0x1b,0x8d,0x11,0xd0,0xa9,0x40,
	0x85,0x90,0x18,0x60,0xa9,0x35,0x85,0x1,0xa9,0x1b,0x8d,0x11,0xd0,0xea,0xa9,0x1d,
	0x38,0x60,0xa0,0,0xb9,0x42,0xf0,0x99,0x30,0x1,0xc8,0xc0,0x1f,0xd0,0xf5,0x20,
	0xd2,0xef,0x4c,0x30,0x1,0xea,0x8,0x48,0xa9,0,0xa8,0x59,0,0xa0,0xc8,0xd0,
	0xfa,0xc9,0x80,0xf0,0x4,0xa9,0x37,0x85,0x1,0xa6,0xae,0xa4,0xaf,0x68,0x28,0x58,
	0x60,0xdd,0x10,0xad,0xf0,0x22,0xad,0xa1,0x2,0x4a,0xb0,0xfa,0xad,0x1,0xdd,0x29,
	0xfd,0x8d,0x1,0xdd,0xad,0x1,0xdd,0x29,0x4,0xf0,0xf9,0xa9,0x90,0x18,0x4c,0x3b,
	0xef,0xad,0xa1,0x2,0x29,0x12,0xf0,0xf3,0x18,0x60,0xad,0x97,0x2,0xac,0x9c,0x2,
	0xcc,0x9b,0x2,0xf0,0xb,0x29,0xf7,0x8d,0x97,0x2,0xb1,0xf7,0xee,0x9c,0x2,0x60,
	0x9,0x8,0x8d,0x97,0x2,0xa9,0,0x60,0x48,0xad,0xa1,0x2,0xf0,0x11,0xad,0xa1,
	0x2,0x29,0x3,0xd0,0xf9,0xa9,0x10,0x8d,0xd,0xdd,0xa9,0,0x8d,0xa1,0x2,0x68,
	0x60,0xa5,0,0x29,0x6,0xc9,0x2,0xf0,0x3,0x4c,0x9e,0xfd,0xea,0xa9,0x5,0x85,
	0x9,0xa2,0x5a,0x86,0x4b,0xa2,0,0xa9,0x52,0x85,0x24,0x20,0x56,0xf5,0x50,0xfe,
	0xb8,0xad,0x1,0x1c,0xc5,0x24,0xf0,0x9,0xc6,0x4b,0xd0,0xef,0xa9,0xa,0x4c,0x69,
	0xf9,0x50,0xfe,0xb8,0xad,0x1,0x1c,0x95,0x25,0xe8,0xe0,0x7,0xd0,0xf3,0x20,0x97,
	0xf4,0xa5,0x16,0x45,0x17,0x45,0x18,0x45,0x19,0x45,0x1a,0xf0,0x7,0xc6,0x9,0xd0,
	0xc0,0x4c,0x1e,0xf4,0xa5,0x18,0xc5,0x6,0xf0,0x3,0x4c,0xb,0xf4,0x85,0x22,0xa9,
	0x6,0x85,0x31,0x4c,0x3c,0x4,0xa5,0x12,0xa6,0x13,0x85,0x16,0x86,0x17,0xa5,0x6,
	0x85,0x18,0xa5,0x7,0x85,0x19,0xa9,0,0x45,0x16,0x45,0x17,0x45,0x18,0x45,0x19,
	0x85,0x1a,0x20,0x34,0xf9,0xa2,0x5a,0x20,0x56,0xf5,0xa0,0,0x50,0xfe,0xb8,0xad,
	0x1,0x1c,0xd9,0x24,0,0xf0,0x6,0xca,0xd0,0xed,0x4c,0x51,0xf5,0xc8,0xc0,0x8,
	0xd0,0xea,0x20,0x56,0xf5,0x50,0xfe,0xb8,0xad,0x1,0x1c,0x91,0x30,0xc8,0xd0,0xf5,
	0xa0,0xba,0x50,0xfe,0xb8,0xad,0x1,0x1c,0x99,0,0x1,0xc8,0xd0,0xf4,0x20,0xe0,
	0xf8,0xa5,0x38,0xc5,0x47,0xf0,0x3,0x4c,0xf6,0xf4,0x20,0xe9,0xf5,0xc5,0x3a,0xf0,
	0x3,0x4c,0x2,0xf5,0xa0,0,0xa9,0x55,0x20,0x52,0x4,0xb9,0,0x6,0x85,0x77,
	0x2c,0,0x18,0x10,0xfb,0xa9,0x10,0x8d,0,0x18,0x2c,0,0x18,0x30,0xfb,0xa2,
	0,0x8a,0x66,0x77,0x2a,0x2a,0x66,0x77,0x2a,0x2a,0x8d,0,0x18,0x8a,0x66,0x77,
	0x2a,0x2a,0x66,0x77,0x2a,0x2a,0x8d,0,0x18,0x8a,0x66,0x77,0x2a,0x2a,0x66,0x77,
	0x2a,0x2a,0x8d,0,0x18,0x8a,0x66,0x77,0x2a,0x2a,0x66,0x77,0x2a,0x2a,0x8d,0,
	0x18,0xa2,0x2,0xca,0xd0,0xfd,0xa9,0xf,0x8d,0,0x18,0xc8,0xd0,0xad,0xea,0xea,
	0xea,0xea,0xea,0xea,0xea,0xad,0,0x1c,0x9,0x8,0x8d,0,0x1c,0xad,0,0x6,
	0xd0,0x3,0x4c,0x9e,0xfd,0xc5,0x18,0xd0,0xf9,0x85,0x6,0xad,0x1,0x6,0x85,0x7,
	0x4c,0x65,0x3,0x85,0x77,0x2c,0,0x18,0x10,0xfb,0xa9,0x10,0x8d,0,0x18,0x2c,
	0,0x18,0x30,0xfb,0xa2,0x4,0xa9,0,0x66,0x77,0x2a,0x2a,0x66,0x77,0x2a,0x2a,
	0x8d,0,0x18,0xca,0xd0,0xf0,0xea,0xea,0xea,0xea,0xea,0xea,0xa9,0xf,0x8d,0,
	0x18,0x60,0x60,0x85,0,0x58,0xa5,0,0x30,0xfc,0x78,0x60,0x78,0xea,0xea,0xea,
	0xea,0xea,0xea,0xa5,0x18,0x8d,0,0x6,0x85,0x6,0xa5,0x19,0x8d,0x1,0x6,0x85,
	0x7,0xa9,0x4,0x85,0x78,0xa9,0xe2,0x20,0x82,0x4,0xc9,0x2,0x90,0x33,0xa0,0,
	0x84,0x78,0xa4,0x78,0xb9,0xdb,0xfe,0xf0,0x12,0x58,0x20,0x76,0xd6,0x78,0xa9,0xe2,
	0x20,0x82,0x4,0xc9,0x2,0x90,0x1a,0xe6,0x78,0xd0,0xe7,0xa9,0xc0,0x20,0x82,0x4,
	0xa9,0xe2,0x20,0x82,0x4,0xc9,0x2,0x90,0x8,0xa9,0xff,0x20,0x52,0x4,0x4c,0x22,
	0xeb,0xad,0,0x6,0xf0,0xf8,0xc5,0x18,0xf0,0xc4,0xad,0,0x6,0x85,0x6,0xad,
	0x1,0x6,0x85,0x7,0x4c,0xa0,0x4,0xea,0xea,0xea,0xea,0xa0,0,0xb9,0x19,0xf4,
	0x99,0x30,0x1,0xc8,0xc0,0x1f,0xd0,0xf5,0x4c,0x30,0x1,0xa9,0,0xa8,0x59,0,
	0xa0,0xc8,0xd0,0xfa,0xc9,0x80,0xf0,0x7,0xa9,0x37,0x85,0x1,0x4c,0x1,0xf5,0x4c,
	0x30,0xf4,0xa0,0,0xb1,0xbb,0xc9,0x24,0xf0,0xf2,0xa9,0x1,0x85,0xa7,0xa9,0,
	0x85,0x90,0xa5,0xa7,0x20,0xc,0xed,0xa9,0x6f,0x20,0xb9,0xed,0xa5,0x90,0x10,0xb,
	0xe6,0xa7,0xa5,0xa7,0xc9,0x10,0xd0,0xe6,0x4c,0xbb,0xee,0xa5,0xa7,0xc9,0x8,0xf0,
	0xef,0xa0,0,0xb9,0x7a,0xf4,0xf0,0x6,0x20,0xd2,0xff,0xc8,0xd0,0xf5,0x20,0xe1,
	0xff,0xd0,0xfb,0xee,0xea,0xea,0xea,0xea,0x4c,0xbb,0xee,0xea,0xd,0x42,0x49,0x54,
	0x54,0x45,0x20,0x4e,0x55,0x52,0x20,0x46,0x4c,0x4f,0x50,0x50,0x59,0x20,0x41,0x4e,
	0x53,0x43,0x48,0x41,0x4c,0x54,0x45,0x4e,0xd,0,0,0,0,0,0,0,
	0,0,0,0,0,0x78,0xa9,0x37,0x85,0x1,0xa0,0,0x84,0x3,0xa9,0xa0,
	0x85,0x4,0xb1,0x3,0x91,0x3,0xe6,0x3,0xd0,0xf8,0xe6,0x4,0xd0,0xf4,0xa9,0xe5,
	0x8d,0xd6,0xfd,0xa9,0x4c,0x8d,0x72,0xfe,0x8d,0xf9,0xf4,0xa9,0xbc,0x8d,0x73,0xfe,
	0xa9,0xfe,0x8d,0x74,0xfe,0xa9,0x9,0x8d,0xfa,0xf4,0xa9,0xf4,0x8d,0xfb,0xf4,0xa9,
	0x12,0x85,0x3,0xa9,0xa,0x85,0x4,0xa9,0xe2,0x85,0x5,0xa9,0xf8,0x85,0x6,0xb1,
	0x3,0x91,0x5,0xc8,0xd0,0xf9,0xe6,0x4,0xe6,0x6,0xa5,0x6,0xc9,0xfa,0xd0,0xef,
	0xa9,0x10,0xa2,0x8,0x85,0x3,0x86,0x4,0xa9,0xbb,0xa2,0xee,0x85,0x5,0x86,0x6,
	0xb1,0x3,0x91,0x5,0xc8,0xd0,0xf9,0xe6,0x4,0xe6,0x6,0xa5,0x6,0xc9,0xf0,0xd0,
	0xef,0xb9,0x43,0xd,0x99,0x5f,0xe4,0xc8,0xc0,0x50,0xd0,0xf5,0xa0,0,0xb9,0xc,
	0xc,0x99,0x9,0xf4,0xc8,0xc0,0x94,0xd0,0xf5,0xa9,0x35,0x85,0x1,0x4c,0xf8,0xfc,
	0xea,0xea,0,0x20,0x42,0x59,0x54,0x45,0x53,0x20,0x46,0x52,0x45,0x45,0xd,0,
	0,0,0,0,0,0,0x93,0xd,0x20,0x20,0x20,0x20,0x2a,0x2a,0x2a,0x2a,
	0x20,0x43,0x36,0x34,0x2d,0x48,0x59,0x50,0x52,0x41,0x2d,0x4c,0x4f,0x41,0x44,0x2d,
	0x53,0x59,0x53,0x54,0x45,0x4d,0x20,0x2a,0x2a,0x2a,0x2a,0xd,0xd,0x20,0x28,0x43,
	0x29,0x38,0x34,0x20,0x12,0x54,0x52,0x49,0x42,0x41,0x52,0x92,0x20,0x20,0,0x81,
	0x48,0x20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0x38,0x2c,0x32,0x2c,0x32,0x33,0x30,0x2c,0x31,0x37,0x35,0x2c,0x32,0x33,0x32,0,
	0xd4,0x94,};

