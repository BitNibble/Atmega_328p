#include <avr/io.h>
#include <util/twi.h>

#define F_CPU 16000000UL  // 16 MHz
#define F_SCL 100000UL    // 100 kHz

void I2C_Init() {
	// Set prescaler to 1
	TWSR = 0x00;
	
	// Set bit rate
	TWBR = ((F_CPU / F_SCL) - 16) / 2;
	
	// Enable TWI
	TWCR = (1 << TWEN);
}

uint8_t I2C_Start() {
	// Send START condition
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	
	// Wait for TWINT flag set
	while (!(TWCR & (1 << TWINT)));
	
	// Check status
	if ((TWSR & 0xF8) != TW_START) {
		return 1; // Error
	}
	
	return 0; // Success
}

void I2C_Stop() {
	// Send STOP condition
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

uint8_t I2C_Write(uint8_t data) {
	// Load data into TWDR
	TWDR = data;
	
	// Start transmission
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	// Wait for TWINT flag set
	while (!(TWCR & (1 << TWINT)));
	
	// Check status
	if ((TWSR & 0xF8) != TW_MT_DATA_ACK) {
		return 1; // Error
	}
	
	return 0; // Success
}

uint8_t I2C_Read(uint8_t *data, uint8_t ack) {
	// Start reception
	if (ack) {
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
		} else {
		TWCR = (1 << TWINT) | (1 << TWEN);
	}
	
	// Wait for TWINT flag set
	while (!(TWCR & (1 << TWINT)));
	
	// Read data
	*data = TWDR;
	
	// Check status
	if ((TWSR & 0xF8) != TW_MR_DATA_ACK && (TWSR & 0xF8) != TW_MR_DATA_NACK) {
		return 1; // Error
	}
	
	return 0; // Success
}

uint8_t I2C_ReadByte(uint8_t *data, uint8_t ack) {
	return I2C_Read(data, ack);
}

uint8_t I2C_WriteByte(uint8_t data) {
	return I2C_Write(data);
}

uint8_t I2C_ReadRegister(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data) {
	uint8_t ret;
	
	// Send START condition
	ret = I2C_Start();
	if (ret) return ret;
	
	// Send device address with write bit
	ret = I2C_Write((dev_addr << 1) | TW_WRITE);
	if (ret) return ret;
	
	// Send register address
	ret = I2C_Write(reg_addr);
	if (ret) return ret;
	
	// Send repeated START condition
	ret = I2C_Start();
	if (ret) return ret;
	
	// Send device address with read bit
	ret = I2C_Write((dev_addr << 1) | TW_READ);
	if (ret) return ret;
	
	// Read data
	ret = I2C_Read(data, 0);
	if (ret) return ret;
	
	// Send STOP condition
	I2C_Stop();
	
	return 0; // Success
}

uint8_t I2C_WriteRegister(uint8_t dev_addr, uint8_t reg_addr, uint8_t data) {
	uint8_t ret;
	
	// Send START condition
	ret = I2C_Start();
	if (ret) return ret;
	
	// Send device address with write bit
	ret = I2C_Write((dev_addr << 1) | TW_WRITE);
	if (ret) return ret;
	
	// Send register address
	ret = I2C_Write(reg_addr);
	if (ret) return ret;
	
	// Send data
	ret = I2C_Write(data);
	if (ret) return ret;
	
	// Send STOP condition
	I2C_Stop();
	
	return 0; // Success
}
