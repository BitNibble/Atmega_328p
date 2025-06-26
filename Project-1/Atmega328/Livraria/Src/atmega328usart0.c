/*************************************************************************
	Atmega328Usart0
Author:	  <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update:   01/01/2024
*************************************************************************/
/****** Comment:
	stable
*************************************************************************/
/*** File Library ***/
#include "atmega328usart0.h"
#include "buffer.h"
#include <string.h>

/*** File Variable ***/
static USART0 setup_usart0;

static BUFF rxbuff;
static UARTvar UART_Rx;

static UARTvar UART_RxBuf[UART0_RX_BUFFER_SIZE];
static const uint16_t uart0_rx_buffer_size = UART0_RX_BUFFER_SIZE - 1;
static uint8_t UART_LastRxError;
static uint8_t uart0flag;

/*** File Header ***/
UARTvar uart_read(void);
UARTvar uart_getch(void);
UARTvar* uart_gets(void);
void uart_rxflush(void);
void uart_write(UARTvar data);
void uart_putch(UARTvar c);
void uart_puts(UARTvar* s);
/*** Complimentary functions ***/
uint8_t USART0ReceiveComplete(void);
uint8_t USART0TransmitComplete(void);
uint8_t USART0DataRegisterEmpty(void);
uint8_t USART0FrameError(void);
uint8_t USART0DataOverRun(void);
uint8_t USART0ParityError(void);
uint8_t USART0ReadErrors(void);
void USART0ClearErrors(void);
void USART0DoubleTransmissionSpeed(void);

/*** Procedure & Function ***/
USART0 usart0_enable(uint32_t baud, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	uint8_t tSREG;
	tSREG = cpu_instance()->sreg.reg;
	cpu_instance()->sreg.par.i = 0;
	uart0flag = 1;
	uint16_t ubrr;
	rxbuff = buff_enable(uart0_rx_buffer_size, UART_RxBuf);
	ubrr = BAUDRATEnormal(baud);
	setup_usart0.par.ubrr = ubrr;
	setup_usart0.instance = usart0_instance();
	// V-table
	setup_usart0.read = uart_read;
	setup_usart0.getch = uart_getch;
	setup_usart0.gets = uart_gets;
	setup_usart0.rxflush = uart_rxflush;
	setup_usart0.write = uart_write;
	setup_usart0.putch = uart_putch;
	setup_usart0.puts = uart_puts;
	// Set baud rate
	if ( ubrr & 0x8000 ) 
	{
   		USART0DoubleTransmissionSpeed();  //Enable 2x speed
		ubrr = BAUDRATEdouble(baud);
   	}
	usart0_instance()->ubrr0.reg = writehlbyte(ubrr).reg;
	setup_usart0.par.ubrr = ubrr;
	// Enable USART receiver and transmitter and receive complete interrupt
	usart0_instance()->ucsr0b.reg = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	
	#ifdef URSEL0 // Set frame format: asynchronous, 8data, no parity, 1stop bit
		usart0_instance()->ucsr0c.par.ucsz0 = 1;
		usart0_instance()->ucsr0c.par.ucsz1 = 1;
		usart0_instance()->ucsr0b.par.ucsz2 = 0;
		usart0_instance()->ucsr0c.par.umsel = 1;
		setup_usart0.par.FDbits = 8;
		setup_usart0.par.Stopbits = 1;
		setup_usart0.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				usart0_instance()->ucsr0c.par.ucsz0 = 1;
				usart0_instance()->ucsr0c.par.ucsz1 = 1;
				usart0_instance()->ucsr0b.par.ucsz2 = 1;
				setup_usart0.par.FDbits = 9;
			break;
			case 8:
				usart0_instance()->ucsr0c.par.ucsz0 = 1;
				usart0_instance()->ucsr0c.par.ucsz1 = 1;
				usart0_instance()->ucsr0b.par.ucsz2 = 0;
				setup_usart0.par.FDbits=8;
			break;
			case 7:
				usart0_instance()->ucsr0c.par.ucsz0 = 0;
				usart0_instance()->ucsr0c.par.ucsz1 = 1;
				usart0_instance()->ucsr0b.par.ucsz2 = 0;
				setup_usart0.par.FDbits=7;
			break;
			case 6:
				usart0_instance()->ucsr0c.par.ucsz0 = 1;
				usart0_instance()->ucsr0c.par.ucsz1 = 0;
				usart0_instance()->ucsr0b.par.ucsz2 = 0;
				setup_usart0.par.FDbits = 6;
			break;
			case 5:
				usart0_instance()->ucsr0c.par.ucsz0 = 0;
				usart0_instance()->ucsr0c.par.ucsz1 = 0;
				usart0_instance()->ucsr0b.par.ucsz2 = 0;
				setup_usart0.par.FDbits=5;
			break;
			default:
				usart0_instance()->ucsr0c.par.ucsz0 = 1;
				usart0_instance()->ucsr0c.par.ucsz1 = 1;
				usart0_instance()->ucsr0b.par.ucsz2 = 0;
				setup_usart0.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				usart0_instance()->ucsr0c.par.usbs = 0;
				setup_usart0.par.Stopbits = 1;
			break;
			case 2:
				usart0_instance()->ucsr0c.par.usbs = 1;
				setup_usart0.par.Stopbits=2;
			break;	
			default:
				usart0_instance()->ucsr0c.par.usbs = 0;
				setup_usart0.par.Stopbits=1;
			break;
		}
		switch(Parity){
			case 0:
				usart0_instance()->ucsr0c.par.upm = 0;
				setup_usart0.par.Parity=0;
			break;
			case 2:
				usart0_instance()->ucsr0c.par.upm = 2;
				setup_usart0.par.Parity=2;
			break;
			case 3:
				usart0_instance()->ucsr0c.par.upm = 3;
				setup_usart0.par.Parity=3;
			break;
			default:
				usart0_instance()->ucsr0c.par.upm = 0;
				setup_usart0.par.Parity=0;
			break;
		}
	#endif
	cpu_instance()->sreg.reg = tSREG;
	cpu_instance()->sreg.par.i = 1;

	return setup_usart0;
}

USART0* usart0(void){ return &setup_usart0; }

UARTvar uart_read(void)
{
	UARTvar c;
	c = UART_Rx;
	UART_Rx = 0;
	return c;
}
UARTvar uart_getch(void)
{
	return uart_read();
}
UARTvar* uart_gets(void)
{
	return rxbuff.raw(&rxbuff.par);
}
void uart_rxflush(void)
{
	rxbuff.flush(&rxbuff.par);
	UART_LastRxError = 0;
}
void uart_write(UARTvar data)
{
	uint16_t timeout;
	usart0_instance()->ucsr0b.par.udrie = 1;
	usart0_instance()->udr0.reg = data;
	for( timeout = 600; !USART0DataRegisterEmpty() && timeout; timeout-- ); // minimum -> +/- 450
	//for( ; !USART0DataRegisterEmpty(); ); // without timeout
}
void uart_putch(UARTvar c)
{
	uart_write(c);
}
void uart_puts(UARTvar* s)
{
	char tmp;
	while(*s){
		tmp = *(s++);
		uart_putch(tmp);
	}
}

/*** File Interrupt ***/
ISR(UART_RX_COMPLETE)
{ // USART, RX Complete Handler
	unsigned char bit_8;
    unsigned char usr;
	
	usr = USART0ReadErrors();
    bit_8 = usart0_instance()->ucsr0b.par.rxb8;
	(void)bit_8;
	
	if(usr){ UART_LastRxError = usr; }
	
	UART_Rx = usart0_instance()->udr0.reg;
	rxbuff.push(&rxbuff.par, UART_Rx);
}

ISR(UART_UDR_EMPTY)
{ // USART, UDR Empty Handler
	usart0_instance()->ucsr0b.par.udrie = 0;
}

/*** Complimentary functions ***/
char* usart0_messageprint(USART0* uart, char* oneshot, char* msg, const char* endl)
{
	char* ptr;
	uint8_t length;
	uint8_t endlength = strlen(endl);
	if(uart0flag){ *oneshot = 0; uart0flag = 0; uart->rxflush();} // the matrix
	ptr = uart->gets();
	length = strlen(ptr);
	if(length >= endlength){
		if( !strcmp( ptr+(length-endlength), endl ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
		// default
		//else if( !strcmp( ptr+(length-endlength), "\r" ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
		//else if( !strcmp( ptr+(length-endlength), "\n" ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
	}
	return ptr;
}

/*** Auxiliar ***/
uint8_t USART0ReceiveComplete(void)
{
	return usart0_instance()->ucsr0a.par.rxc;
}
uint8_t USART0TransmitComplete(void)
{
	return usart0_instance()->ucsr0a.par.txc;
}
uint8_t USART0DataRegisterEmpty(void)
{
	return usart0_instance()->ucsr0a.par.udre;
}
uint8_t USART0FrameError(void)
{
	return usart0_instance()->ucsr0a.par.fe;
}
uint8_t USART0DataOverRun(void)
{
	return usart0_instance()->ucsr0a.par.dor;
}
uint8_t USART0ParityError(void)
{
	return usart0_instance()->ucsr0a.par.upe;
}
uint8_t USART0ReadErrors(void)
{
	return get_reg_block(usart0_instance()->ucsr0a.reg,3,2);
}
void USART0ClearErrors(void)
{
	set_reg_block(&usart0_instance()->ucsr0a.reg,3,2,0);
}
void USART0DoubleTransmissionSpeed(void)
{
	usart0_instance()->ucsr0a.par.u2x = 1;
}

/*** EOF ***/

