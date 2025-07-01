/*********************************************************
	ATMEGA 328 Instance
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega 328
Update:	  07/04/2024
Comment: 
	Simple tools
**********************************************************/
#ifndef _ATMEGA328INSTANCE_H_
	#define _ATMEGA328INSTANCE_H_
	
/*** Working Frequency ***/
// User may change to conform to use
#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/*********************************************************/
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
/*********************************************************/
#include "atmega328.h"
/*********************************************************/

// Macros for common operations
#define SET_REG(REG, HBITS)		(REG |= HBITS)
#define CLEAR_REG(REG, HBITS)	(REG &= ~HBITS)
#define READ_BIT(REG, BIT)		((REG >> BIT) & 1)
#define TOGGLE_REG(REG, HBITS)	(REG ^= HBITS)

/****************************/
/***** HARDWARE HANDLER *****/
/****************************/
// GPWR
Atmega328GPWR_TypeDef* gpwr_instance(void);
// I/O Port (PORTB)
Atmega328PORTB_TypeDef* portb_instance(void);
// I/O Port (PORTC)
Atmega328PORTC_TypeDef* portc_instance(void);
// I/O Port (PORTD)
Atmega328PORTD_TypeDef* portd_instance(void);
// Timer/Counter 0, 1 and 2 Interrupt Flag
Atmega328TimerInterruptFlag_TypeDef* tc_iflag_instance(void);
// External Interrupts Flag (EXINT)
Atmega328ExternalInterruptFlag_TypeDef* exint_iflag_instance(void);
// External Interrupts Mask (EXINT)
Atmega328ExternalInterruptMask_TypeDef* exint_imask_instance(void);
// CPU Register Gpio0 (CPU)
Atmega328CpuGeneralPurposeIoRegister0_TypeDef* cpu_gpio0_instance(void);
// EEPROM (EEPROM)
Atmega328Eeprom_TypeDef* eeprom_instance(void);
// TIMER General Control
Atmega328TimerGeneralControlRegister_TypeDef* tc_gcontrol_instance(void);
// Timer/Counter, 8-bit A sync (TC0)
Atmega328TimerCounter0_TypeDef* tc0_instance(void);
// Timer/Counter, 8-bit A sync Compare (TC0)
Atmega328TimerCompareRegister0_TypeDef* tc0_compare_instance(void);
// CPU Register Gpio1 (CPU)
Atmega328CpuGeneralPurposeIoRegister1_TypeDef* cpu_gpio1_instance(void);
// CPU Register Gpio012 (CPU)
Atmega328CpuGeneralPurposeIoRegister_TypeDef* cpu_gpio012_instance(void);
// CPU Register Gpio2 (CPU)
Atmega328CpuGeneralPurposeIoRegister2_TypeDef* cpu_gpio2_instance(void);
// Serial Peripheral Interface (SPI)
Atmega328SerialPeripherialInterface_TypeDef* spi_instance(void);
// Analog Comparator (AC)
Atmega328AnalogComparator_TypeDef* ac_instance(void);
// Watchdog Timer (WDT)
Atmega328WatchdogTimer_TypeDef* wdt_instance(void);
// CPU Register (CPU)
Atmega328CPURegister_TypeDef* cpu_instance(void);
// External Interrupts Pin Change Mask (EXINT)
Atmega328ExternalInterruptPinChangeMask_TypeDef* exint_pcmask_instance(void);
// External Interrupts (EXINT)
Atmega328ExternalInterrupt_TypeDef* exint_instance(void);
// Timer/Counter 0, 1 and 2 Interrupt Mask
Atmega328TimerInterruptMask_TypeDef* tc_imask_instance(void);
// Analog to Digital Converter (ADC)
Atmega328AnalogToDigitalConverter_TypeDef* adc_instance(void);
// Analog Comparator Did (AC)
Atmega328AnalogComparatorDid_TypeDef* ac_did_instance(void);
// Timer/Counter, 16-bit (TC1)
Atmega328TimerCounter1_TypeDef* tc1_instance(void);
// Timer/Counter, 16-bit Compare (TC1)
Atmega328TimerCompareRegister1_TypeDef* tc1_compare_instance(void);
// Timer/Counter, 8-bit (TC2)
Atmega328TimerCounter2_TypeDef* tc2_instance(void);
// Timer/Counter, 8-bit Compare (TC2)
Atmega328TimerCompareRegister2_TypeDef* tc2_compare_instance(void);
// Two Wire Serial Interface (TWI)
Atmega328TwoWireSerialInterface_TypeDef* twi_instance(void);
// USART (USART0)
Atmega328Usart0_TypeDef* usart0_instance(void);

/*** Atmega 328 Procedure and Function ***/
uint16_t readhlbyte(HighLowByte reg);
uint16_t readlhbyte(HighLowByte reg);
HighLowByte writehlbyte(uint16_t val);
HighLowByte writelhbyte(uint16_t val);
uint16_t swapbyte(uint16_t num);
uint16_t BAUDRATEnormal(uint32_t BAUD);
uint16_t BAUDRATEdouble(uint32_t BAUD);
uint16_t BAUDRATEsynchronous(uint32_t BAUD);
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler);
void Atmega328MoveInterruptsToBoot(void);

/*** Procedure and Function ToolSet ***/
void set_reg(volatile uint8_t* reg, uint8_t hbits);
void clear_reg(volatile uint8_t* reg, uint8_t hbits);
uint8_t get_reg_block(uint8_t reg, uint8_t size_block, uint8_t bit_n);
uint8_t get_reg_Msk(uint8_t reg, uint8_t Msk);
void write_reg_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void write_reg_Msk(volatile uint8_t* reg, uint8_t Msk, uint8_t data);
void set_reg_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void set_reg_Msk(volatile uint8_t* reg, uint8_t Msk, uint8_t data);
uint8_t get_bit_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n);
void set_bit_block(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
/*** NULL Check ***/
int isPtrNull(void* ptr);
int isCharPtrFlush(void* ptr);
/*** Fall Threw Delay ***/
int ftdelayCycles(uint8_t lock_ID, unsigned int n_cycle);
void ftdelayReset(uint8_t ID);
#endif

/*** Interrupt List ***/
// ISR(RESET_vect){}
// ISR(INT0_vect){}
// ISR(INT1_vect){}
// ISR(PCINT0_vect){}
// ISR(PCINT1_vect){}
// ISR(PCINT2_vect){}
// ISR(WDT_vect){}
// ISR(TIMER2_COMPA_vect){}
// ISR(TIMER2_COMPB_vect){}
// ISR(TIMER2_OVF_vect){}
// ISR(TIMER1_CAPT_vect){}
// ISR(TIMER1_COMPA_vect){}
// ISR(TIMER1_COMPB_vect){}
// ISR(TIMER1_OVF_vect){}
// ISR(TIMER0_COMPA_vect){}
// ISR(TIMER0_COMPB_vect){}
// ISR(TIMER0_OVF_vect){}
// ISR(SPI_STC_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}
// ISR(ADC_vect){}
// ISR(EE_READY_vect){}
// ISR(ADC_vect)
// ISR(ANALOG_COMP_vect){}
// ISR(TWI_vect){}
// ISR(SPM_READY_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}
	
/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

/*** EOF ***/

