/*********************************************************
	ATMEGA 328 Instance
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega 328
Update:	  07/04/2024
Comment: 

**********************************************************/
#include "atmega328instance.h"
#include <stdarg.h>

#define FTDELAY_SIZE 256
unsigned int ft_Delay_Lock[FTDELAY_SIZE] = {0};
unsigned int ftCounter[FTDELAY_SIZE] = {0};
/**************************/
/**** HARDWARE HANDLER ****/
/**************************/
// GPWR
Atmega328GPWR_TypeDef* gpwr_instance(void)
{
	return (Atmega328GPWR_TypeDef*) Atmega328GPWR_Address;
}
// I/O Port (PORTB)
Atmega328PORTB_TypeDef* portb_instance(void)
{
	return (Atmega328PORTB_TypeDef*) Atmega328PORTB_Address;
}
// I/O Port (PORTC)
Atmega328PORTC_TypeDef* portc_instance(void)
{
	return (Atmega328PORTC_TypeDef*) Atmega328PORTC_Address;
}
// I/O Port (PORTD)
Atmega328PORTD_TypeDef* portd_instance(void)
{
	return (Atmega328PORTD_TypeDef*) Atmega328PORTD_Address;
}
// Timer/Counter 0, 1 and 2 Interrupt Flag
Atmega328TimerInterruptFlag_TypeDef* tc_iflag_instance(void)
{
	return (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
}
// External Interrupts Flag (EXINT)
Atmega328ExternalInterruptFlag_TypeDef* exint_iflag_instance(void)
{
	return (Atmega328ExternalInterruptFlag_TypeDef*) Atmega328ExternalInterruptFlag_Address;
}
// External Interrupts Mask (EXINT)
Atmega328ExternalInterruptMask_TypeDef* exint_imask_instance(void)
{
	return (Atmega328ExternalInterruptMask_TypeDef*) Atmega328ExternalInterruptMask_Address;
}
// CPU Register Gpio0 (CPU)
Atmega328CpuGeneralPurposeIoRegister0_TypeDef* cpu_gpio0_instance(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister0_TypeDef*) Atmega328CpuGeneralPurposeIoRegister0_Address;
}
// EEPROM (EEPROM)
Atmega328Eeprom_TypeDef* eeprom_instance(void)
{
	return (Atmega328Eeprom_TypeDef*) Atmega328Eeprom_Address;
}
// TIMER General Control
Atmega328TimerGeneralControlRegister_TypeDef* tc_gcontrol_instance(void)
{
	return (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
}
// Timer/Counter, 8-bit A sync (TC0)
Atmega328TimerCounter0_TypeDef* tc0_instance(void)
{
	return (Atmega328TimerCounter0_TypeDef*) Atmega328TimerCounter0_Address;
}
// Timer/Counter, 8-bit A sync Compare (TC0)
Atmega328TimerCompareRegister0_TypeDef* tc0_compare_instance(void)
{
	return (Atmega328TimerCompareRegister0_TypeDef*) Atmega328TimerCompareRegister0_Address;
}
// CPU Register Gpio1 (CPU)
Atmega328CpuGeneralPurposeIoRegister1_TypeDef* cpu_gpio1_instance(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister1_TypeDef*) Atmega328CpuGeneralPurposeIoRegister1_Address;
}
// CPU Register Gpio012 (CPU)
Atmega328CpuGeneralPurposeIoRegister_TypeDef* cpu_gpio012_instance(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister_TypeDef*) Atmega328CpuGeneralPurposeIoRegister_Address;
}
// CPU Register Gpio2 (CPU)
Atmega328CpuGeneralPurposeIoRegister2_TypeDef* cpu_gpio2_instance(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister2_TypeDef*) Atmega328CpuGeneralPurposeIoRegister2_Address;
}
// Serial Peripheral Interface (SPI)
Atmega328SerialPeripherialInterface_TypeDef* spi_instance(void)
{
	return (Atmega328SerialPeripherialInterface_TypeDef*) Atmega328SerialPeripherialInterface_Address;
}
// Analog Comparator (AC)
Atmega328AnalogComparator_TypeDef* ac_instance(void)
{
	return (Atmega328AnalogComparator_TypeDef*) Atmega328AnalogComparator_Address;
}
// Watchdog Timer (WDT)
Atmega328WatchdogTimer_TypeDef* wdt_instance(void)
{
	return (Atmega328WatchdogTimer_TypeDef*) Atmega328WatchdogTimer_Address;
}
// CPU Register (CPU)
Atmega328CPURegister_TypeDef* cpu_instance(void)
{
	return (Atmega328CPURegister_TypeDef*) Atmega328CPURegister_Address;
}
// External Interrupts Pin Change Mask (EXINT)
Atmega328ExternalInterruptPinChangeMask_TypeDef* exint_pcmask_instance(void)
{
	return (Atmega328ExternalInterruptPinChangeMask_TypeDef*) Atmega328ExternalInterruptPinChangeMask_Address;
}
// External Interrupts (EXINT)
Atmega328ExternalInterrupt_TypeDef* exint_instance(void)
{
	return (Atmega328ExternalInterrupt_TypeDef*) Atmega328ExternalInterrupt_Address;
}
// Timer/Counter 0, 1 and 2 Interrupt Mask
Atmega328TimerInterruptMask_TypeDef* tc_imask_instance(void)
{
	return (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
}
// Analog to Digital Converter (ADC)
Atmega328AnalogToDigitalConverter_TypeDef* adc_instance(void)
{
	return (Atmega328AnalogToDigitalConverter_TypeDef*) Atmega328AnalogToDigitalConverter_Address;
}
// Analog Comparator Did (AC)
Atmega328AnalogComparatorDid_TypeDef* ac_did_instance(void)
{
	return (Atmega328AnalogComparatorDid_TypeDef*) Atmega328AnalogComparatorDid_Address;
}
// Timer/Counter, 16-bit (TC1)
Atmega328TimerCounter1_TypeDef* tc1_instance(void)
{
	return (Atmega328TimerCounter1_TypeDef*) Atmega328TimerCounter1_Address;
}
// Timer/Counter, 16-bit Compare (TC1)
Atmega328TimerCompareRegister1_TypeDef* tc1_compare_instance(void)
{
	return (Atmega328TimerCompareRegister1_TypeDef*) Atmega328TimerCompareRegister1_Address;
}
// Timer/Counter, 8-bit (TC2)
Atmega328TimerCounter2_TypeDef* tc2_instance(void)
{
	return (Atmega328TimerCounter2_TypeDef*) Atmega328TimerCounter2_Address;
}
// Timer/Counter, 8-bit Compare (TC2)
Atmega328TimerCompareRegister2_TypeDef* tc2_compare_instance(void)
{
	return (Atmega328TimerCompareRegister2_TypeDef*) Atmega328TimerCompareRegister2_Address;
}
// Two Wire Serial Interface (TWI)
Atmega328TwoWireSerialInterface_TypeDef* twi_instance(void)
{
	return (Atmega328TwoWireSerialInterface_TypeDef*) Atmega328TwoWireSerialInterface_Address;
}
// USART (USART0)
Atmega328Usart0_TypeDef* usart0_instance(void)
{
	return (Atmega328Usart0_TypeDef*) Atmega328Usart0_Address;
}

/*** Atmega 128 Procedure and Function ***/
uint16_t readhlbyte(HighLowByte reg)
{
	return (reg.par.H << 8) | reg.par.L;
}
uint16_t readlhbyte(HighLowByte reg)
{
	return (reg.par.L << 8) | reg.par.H;
}
HighLowByte writehlbyte(uint16_t val)
{
	HighLowByte reg; reg.par.H = (val >> 8); reg.par.L = val;
	return reg;
}
HighLowByte writelhbyte(uint16_t val)
{
	HighLowByte reg; reg.par.L = (val >> 8); reg.par.H = val;
	return reg;
}
uint16_t SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}
/*** Procedure & Function ToolSet ***/
inline uint8_t Msk_Pos(uint8_t Msk){
	uint8_t Pos = 0;
	if( Msk ){
		for( ; !(Msk & 1); Msk >>= 1, Pos++ );
	}
	return Pos;
}
inline void set_reg(volatile uint8_t* reg, uint8_t hbits){
	*reg |= hbits;
}
inline void clear_reg(volatile uint8_t* reg, uint8_t hbits){
	*reg &= ~hbits;
}
inline uint8_t get_reg_Msk(uint8_t reg, uint8_t Msk)
{
	reg = (reg & Msk) >> Msk_Pos(Msk);
	return reg;
}
inline void write_reg_Msk(volatile uint8_t* reg, uint8_t Msk, uint8_t data)
{
	uint8_t value = *reg;
	uint8_t Pos = Msk_Pos(Msk);
	data = (data << Pos) & Msk; value &= ~(Msk); value |= data; *reg = value;
}
inline void set_reg_Msk(volatile uint8_t* reg, uint8_t Msk, uint8_t data)
{
	uint8_t Pos = Msk_Pos(Msk);
	data = (data << Pos) & Msk; *reg &= ~(Msk); *reg |= data;
}
uint8_t get_reg_block(uint8_t reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n < BYTE_BITS && size_block != 0 && bit_n + size_block <= BYTE_BITS) {
		uint8_t mask = (uint8_t)((1U << size_block) - 1);
		reg = (reg & (mask << bit_n)) >> bit_n;
	}
	return reg;
}
void write_reg_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	uint8_t value = *reg;
	if(bit_n < BYTE_BITS && size_block != 0 && bit_n + size_block <= BYTE_BITS) {
		uint8_t mask = (uint8_t)((1U << size_block) - 1);
		data &= mask; value &= ~(mask << bit_n);
		data = (data << bit_n);
		value |= data;
		*reg = value;
	}
}
void set_reg_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	if(bit_n < BYTE_BITS && size_block != 0 && bit_n + size_block <= BYTE_BITS) {
		uint8_t mask = (uint8_t)((1U << size_block) - 1);
		data &= mask;
		*reg &= ~(mask << bit_n);
		*reg |= (data << bit_n);
	}
}
uint8_t get_bit_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n)
{
	uint8_t value;
	uint8_t n = bit_n / BYTE_BITS; bit_n = bit_n % BYTE_BITS;
	value = *(reg + n );
	if(size_block != 0 && bit_n + size_block <= BYTE_BITS){
		uint8_t mask = (uint8_t)((1U << size_block) - 1);
		value = (value & (mask << bit_n)) >> bit_n;
	}
	return value;
}
void set_bit_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	uint8_t n = bit_n / BYTE_BITS; bit_n = bit_n % BYTE_BITS;
	if(size_block != 0 && bit_n + size_block <= BYTE_BITS) {
		uint8_t mask = (uint8_t)((1U << size_block) - 1);
		data &= mask;
		*(reg + n ) &= ~(mask << bit_n);
		*(reg + n ) |= (data << bit_n);
	}
}
void STM32446SetRegBits( uint8_t* reg, uint8_t n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits <= BYTE_BITS){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg |= (uint32_t)(1 << va_arg(list, int));
		}
		va_end(list);
	}
}
void STM32446ResetRegBits( uint8_t* reg, uint8_t n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits <= BYTE_BITS){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg &= (uint32_t)~(1 << va_arg(list, int));
		}
		va_end(list);
	}
}
void STM32446VecSetup( volatile uint8_t vec[], unsigned int size_block, unsigned int block_n, unsigned int data )
{
	const unsigned int n_bits = sizeof(data) * BYTE_BITS;
	if(size_block > n_bits){ size_block = n_bits; }
	const unsigned int mask = (uint8_t) ((1 << size_block) - 1);
	unsigned int index = (block_n * size_block) / n_bits;
	data &= mask;
	vec[index] &= ~( mask << ((block_n * size_block) - (index * n_bits)) );
	vec[index] |= ( data << ((block_n * size_block) - (index * n_bits)) );
}
/*** NULL Check ***/
int isPtrNull(void* ptr) {
	return ptr ? 0 : 1; // Returns 1 if NULL, 0 otherwise
}
int isCharPtrFlush(void* ptr) {
	// Cast the void pointer to a char pointer to dereference it
	return *((unsigned char*)ptr) ? 0 : 1; // Returns 1 if '\0', 0 otherwise
}
/*** Fall Threw Delay ***/
int ftdelayCycles( uint8_t lock_ID, unsigned int n_cycle ) {
	int ret = 0;
	if( ft_Delay_Lock[lock_ID] != lock_ID) {
		ft_Delay_Lock[lock_ID] = lock_ID;
		ftCounter[lock_ID] = n_cycle;
		}else{
		if( ftCounter[lock_ID]-- );else{ ft_Delay_Lock[lock_ID] = 0; ret = 1; }
	}
	return ret;
}
void ftdelayReset(uint8_t ID) {
	ft_Delay_Lock[ID] = 0;
	ftCounter[ID] = 0;
}
/******************/
uint16_t BAUDRATEnormal(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/16;
	baudrate /= BAUD; baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEdouble(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/8;
	baudrate /= BAUD; baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEsynchronous(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/2;
	baudrate /= BAUD; baudrate -= 1;
	return (uint16_t) baudrate;
}
/****** System ******/
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &CLKPR;
	prescaler &= 0x0F;
	sreg = cpu_instance()->sreg.var;
	cpu_instance()->sreg.var &= ~(1 << 7);
	
	*clkpr = (1 << CLKPCE);
	*clkpr = prescaler;
	
	cpu_instance()->sreg.var = sreg;
}
void Atmega328MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = cpu_instance()->sreg.var;
	cpu_instance()->sreg.var &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	cpu_instance()->sreg.var = sreg;
}

/******
n = bit_n/32; bit_n = bit_n - (n * 32); -> bit_n = bit_n % 32;
(a+b)/a = a/a + b/a = 1 + b/a
a/b/c/d/e = a/(b*c*d*e)
*******/

/*** EOF ***/

