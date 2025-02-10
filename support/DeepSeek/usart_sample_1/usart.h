#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL  // 16 MHz clock speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_Init(unsigned int ubrr) {
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	
	// Enable receiver and transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	
	// Set frame format: 8 data bits, 1 stop bit, no parity
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART_Transmit(unsigned char data) {
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1 << UDRE0)));
	
	// Put data into buffer, sends the data
	UDR0 = data;
}

unsigned char USART_Receive(void) {
	// Wait for data to be received
	while (!(UCSR0A & (1 << RXC0)));
	
	// Get and return received data from buffer
	return UDR0;
}

void USART_PrintString(const char *str) {
	while (*str) {
		USART_Transmit(*str++);
	}
}

#endif // USART_H
