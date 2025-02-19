/* This file has been generated by pinning m4 system automatically.
   Please do not modify it, edit the m4 scripts below pinning/ instead. */

#undef BOOTLOADER_SECTION

  /* port the enc28j60 is attached to
   * ATTENTION: EITHER USE SS OR MAKE SURE, SS IS PULLED HIGH OR AN OUTPUT! */

#define SPI_CS_NET_PORT B
#define SPI_CS_NET_PIN 2
#define HAVE_SPI_CS_NET 1

#define SPI_CS_MCP_PORT B
#define SPI_CS_MCP_PIN 4
#define HAVE_SPI_CS_MCP 1


/* spi defines */
#define SPI_MOSI_PORT B
#define SPI_MOSI_PIN 5
#define HAVE_SPI_MOSI 1

#define SPI_MISO_PORT B
#define SPI_MISO_PIN 6
#define HAVE_SPI_MISO 1

#define SPI_SCK_PORT B
#define SPI_SCK_PIN 7
#define HAVE_SPI_SCK 1


  /* port the rfm12 module CS is attached to */
#define SPI_CS_RFM12_PORT B
#define SPI_CS_RFM12_PIN 1
#define HAVE_SPI_CS_RFM12 1


  /* port the LEDS for rfm12 txrx attached to */
#define RFM12_TX_PIN_PORT A
#define RFM12_TX_PIN_PIN 3
#define HAVE_RFM12_TX_PIN 1

#define RFM12_RX_PIN_PORT A
#define RFM12_RX_PIN_PIN 1
#define HAVE_RFM12_RX_PIN 1


  /* rfm12 module interrupt line */
#define RFM12_INT_PIN INT0
#define RFM12_INT_SIGNAL SIG_INTERRUPT0









#define _ATMEGA32

/* ATmega32 specific adjustments */
#define _TIMSK_TIMER1 TIMSK
#define _UDRIE_UART0 UDRIE
#define _TXEN_UART0 TXEN
#define _RXEN_UART0 RXEN
#define _RXCIE_UART0 RXCIE
#define _TXCIE_UART0 TXCIE
#define _UBRRH_UART0 UBRRH
#define _UBRRL_UART0 UBRRL
#define _UCSRA_UART0 UCSRA
#define _UCSRB_UART0 UCSRB
#define _UCSRC_UART0 UCSRC
#define _UCSZ0_UART0 UCSZ0
#define _UCSZ1_UART0 UCSZ1
#define _SIG_UART_RECV_UART0 SIG_USART_RECV
#define _SIG_UART_DATA_UART0 SIG_USART_DATA
#define _UDR_UART0 UDR
#define _UDRE_UART0 UDRE
#define _RXC_UART0 RXC
#define _TXC_UART0 TXC
#define USART0_UDRE_vect USART_UDRE_vect
#define USART0_RX_vect USART_RXC_vect
#define USART0_TX_vect USART_TXC_vect
#define _IVREG MCUCR
#define _EIMSK GICR

#define _TCCR2_PRESCALE TCCR2
#define _OUTPUT_COMPARE_IE2 OCIE2
#define _OUTPUT_COMPARE_REG2 OCR2
#define _SIG_OUTPUT_COMPARE2 SIG_OUTPUT_COMPARE2B
#define _SIG_OVERFLOW2 SIG_OVERFLOW2
#define _TIMSK_TIMER2 TIMSK

/* workaround for avr-libc devs not being able to decide how these registers
 * should be named... */
#ifdef SPCR0
    #define _SPCR0 SPCR0
#else
    #define _SPCR0 SPCR
#endif

#ifdef SPE0
    #define _SPE0 SPE0
#else
    #define _SPE0 SPE
#endif

#ifdef MSTR0
    #define _MSTR0 MSTR0
#else
    #define _MSTR0 MSTR
#endif

#ifdef SPSR0
    #define _SPSR0 SPSR0
#else
    #define _SPSR0 SPSR
#endif

#ifdef SPIF0
    #define _SPIF0 SPIF0
#else
    #define _SPIF0 SPIF
#endif

#ifdef SPDR0
    #define _SPDR0 SPDR0
#else
    #define _SPDR0 SPDR
#endif

#ifdef SPI2X0
    #define _SPI2X0 SPI2X0
#else
    #define _SPI2X0 SPI2X
#endif

#define _TIFR_TIMER1 TIFR

#define NET_MAX_FRAME_LENGTH 500

#define _PORT_CHAR(character) PORT ## character
#define PORT_CHAR(character) _PORT_CHAR(character)

#define _PIN_CHAR(character) PIN ## character
#define PIN_CHAR(character) _PIN_CHAR(character)
 
#define _DDR_CHAR(character) DDR ## character
#define DDR_CHAR(character) _DDR_CHAR(character)


#define DDR_CONFIG_IN(pin)  DDR_CHAR( pin ## _PORT) &= ~_BV((pin ## _PIN))
#define DDR_CONFIG_OUT(pin)  DDR_CHAR( pin ## _PORT) |= _BV((pin ## _PIN))

#define PIN_BV(pin) (_BV(pin ## _PIN))
#define PIN_NR(pin) (pin ## _PIN)
#define PIN_HIGH(pin) (PIN_CHAR(pin ## _PORT) & _BV(pin ## _PIN))
#define PIN_SET(pin) PORT_CHAR(pin ## _PORT) |= _BV(pin ## _PIN)
#define PIN_CLEAR(pin) PORT_CHAR(pin ## _PORT) &= ~_BV(pin ## _PIN)
#define PIN_TOGGLE(pin) PORT_CHAR(pin ## _PORT) ^= _BV(pin ## _PIN)
#define PIN_PULSE(pin) do { PORT_CHAR(pin ## _PORT) &= ~_BV(pin ## _PIN); \
                              PORT_CHAR(pin ## _PORT) ^= _BV(pin ## _PIN); } while(0)

