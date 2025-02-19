/*
	SPI Interface driver for the commodore64
	An SPI interface is generated by connecting the two serial Ports of the CIAs
	together, and programming the serial interface on CIA2 as output, and the one
	in CIA1 as input. Clock is connected between the CIAs and to the SPI clock, while
	the SP of CIA2 acts as MOSI and SP of CIA1 acts as MISO.
*/



#include "spi.h"

void spi_init(){
	outb(SPI_PORT, inb(SPI_PORT)|(1<<SPI_PIN_SS));
	outb(SPI_DDR, inb(SPI_DDR)|(1<<SPI_PIN_SS));

	outb(CIA2+CIA_TALO, 2); //set timer for serial clock to fastest that works
	outb(CIA2+CIA_TAHI, 0);
	outb(CIA2+CIA_CRA, 0x51);//serial is output, reload & start timera
	
	outb(CIA1+CIA_CRA, inb(CIA1+CIA_CRA) | 0x40);//serial is input
	outb(CIA1+CIA_CRA, inb(CIA1+CIA_CRA) & ~0x40);//serial is input


}

unsigned char spi_data(unsigned char c){
	outb(CIA2+CIA_SDR, c);
	while(!(inb(CIA1+CIA_ICR)&0x08)); //wait until spi transaction is complete
	return(inb(CIA1+CIA_SDR));
}
