#include <avr/io.h>
#include <util/delay.h>

// Define SPI pins
#define SPI_DDR     DDRB
#define SPI_PORT    PORTB
#define SS          PB2
#define MOSI        PB3
#define MISO        PB4
#define SCK         PB5

// Function to initialize SPI as Master
void SPI_MasterInit(void) {
	// Set MOSI, SCK, and SS as output
	SPI_DDR |= (1 << MOSI) | (1 << SCK) | (1 << SS);
	
	// Set MISO as input
	SPI_DDR &= ~(1 << MISO);
	
	// Enable SPI, Master, set clock rate fck/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

// Function to send and receive data over SPI
uint8_t SPI_Transfer(uint8_t data) {
	// Start transmission
	SPDR = data;
	
	// Wait for transmission complete
	while (!(SPSR & (1 << SPIF)));
	
	// Return received data
	return SPDR;
}

// Function to select slave
void SPI_SlaveSelect(uint8_t select) {
	if (select) {
		SPI_PORT &= ~(1 << SS);  // Select slave (active low)
		} else {
		SPI_PORT |= (1 << SS);   // Deselect slave
	}
}

// Function to initialize SPI as Slave
void SPI_SlaveInit(void) {
	// Set MISO as output
	SPI_DDR |= (1 << MISO);
	
	// Enable SPI
	SPCR = (1 << SPE);
}

// Function to receive data as Slave
uint8_t SPI_SlaveReceive(void) {
	// Wait for reception complete
	while (!(SPSR & (1 << SPIF)));
	
	// Return received data
	return SPDR;
}

int main(void) {
	// Initialize SPI as Master
	SPI_MasterInit();
	
	// Select slave
	SPI_SlaveSelect(1);
	
	// Send data over SPI
	uint8_t received_data = SPI_Transfer(0x55); // Example data to send
	
	// Deselect slave
	SPI_SlaveSelect(0);
	
	while (1) {
		// Main loop
	}
	
	return 0;
}

