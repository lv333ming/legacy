#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "debug.h"

int debug_level  = 0;    
int debug_syslog = 0 ;  

void debug( int level, char *format, ... )
{
	va_list ap;

	if (debug_level < level) {
			return;
	}

	if (level == 0)
		fprintf(stderr, "ERROR: ");

	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fprintf(stderr, "\n");
	va_end(ap);
}

void debug_perror( int level, char *format, ... )
{
	va_list ap;

	if (debug_level < level)
			return;

	if (level == 0)
		fprintf(stderr, "ERROR: ");

	va_start(ap, format);
	vfprintf(stderr, format, ap);
	fprintf(stderr, " (%s)\n", strerror(errno) );
	va_end(ap);
}

void debug_assert( int test, char *format, ... )
{
	va_list ap;

	if (test)
			return;

	va_start(ap, format);
	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, format, ap);
	fprintf(stderr, " (%s)\n", strerror(errno) );
	va_end(ap);

	exit(1);
}

void debug_assert2(char *format, ... )
{
	va_list ap;

	va_start(ap, format);
	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, format, ap);
	fprintf(stderr, " (%s)\n", strerror(errno) );
	va_end(ap);

	exit(1);
}

void debug_hexdump(int level, char *text, unsigned char *addr, int size){
	unsigned char x=0, sbuf[3];
	
	printf(text);
	while(size--){
		printf("%02x ", *addr++);
		if(++x == 16){
			printf("\n");
			x = 0;
		}
	}
	printf("\n");
}

