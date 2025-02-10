#include "usart.h"

int main(void) {
	// Initialize USART with 9600 baud rate
	USART_Init(MYUBRR);
	
	// Send a string
	USART_PrintString("Hello, World!\r\n");
	
	while (1) {
		// Receive a character and echo it back
		unsigned char receivedData = USART_Receive();
		USART_Transmit(receivedData);
	}
	
	return 0;
}

