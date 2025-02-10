#include <avr/io.h>
#include "i2c.h"

int main() {
	uint8_t data;
	
	I2C_Init();
	
	// Write 0x55 to register 0x01 of device with address 0x50
	I2C_WriteRegister(0x50, 0x01, 0x55);
	
	// Read from register 0x01 of device with address 0x50
	I2C_ReadRegister(0x50, 0x01, &data);
	
	while (1) {
		// Main loop
	}
	
	return 0;
}
