/************************************************************************
	ATMEGA 328 INSTANCES
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update:   01/01/2024
************************************************************************/
/****** Comment:
	Virtual Image Atmega 328.
************************************************************************/
#ifndef _ATMEGA328_H_
	#define _ATMEGA328_H_

/*** Global Library ***/
#include "atmega328registers.h"

/*** Global Constant & Macro ***/
/******** INSTANCES *******/
#define Atmega328GPWR_Address 0x0000
#define Atmega328PORTB_Address 0x0023
#define Atmega328PORTC_Address 0x0026
#define Atmega328PORTD_Address 0x0029
#define Atmega328Eeprom_Address 0x003F
#define Atmega328TimerCounter0_Address 0x0044
#define Atmega328SerialPeripherialInterface_Address 0x004C
#define Atmega328AnalogComparator_Address 0x0050
#define Atmega328CPURegister_Address 0x0053
#define Atmega328WatchdogTimer_Address 0x0060
#define Atmega328ExternalInterrupt_Address 0x0068
#define Atmega328AnalogToDigitalConverter_Address 0x0078
#define Atmega328TimerCounter1_Address 0x0080
#define Atmega328TimerCounter2_Address 0x00B0
#define Atmega328TwoWireSerialInterface_Address 0x00B8
#define Atmega328Usart0_Address 0x00C0
// AUXILIAR
#define Atmega328TimerInterruptFlag_Address 0x0035
#define Atmega328ExternalInterruptFlag_Address 0x003B
#define Atmega328ExternalInterruptMask_Address 0x003D
#define Atmega328CpuGeneralPurposeIoRegister_Address 0x003E
#define Atmega328CpuGeneralPurposeIoRegister0_Address 0x003E
#define Atmega328TimerGeneralControlRegister_Address 0x0043
#define Atmega328TimerCompareRegister0_Address 0x0047
#define Atmega328CpuGeneralPurposeIoRegister1_Address 0x004A
#define Atmega328CpuGeneralPurposeIoRegister2_Address 0x004B
#define Atmega328ExternalInterruptPinChangeMask_Address 0x006B
#define Atmega328TimerInterruptMask_Address 0x006E
#define Atmega328AnalogComparatorDid_Address 0x007F
#define Atmega328TimerCompareRegister1_Address 0x0086
#define Atmega328TimerCompareRegister2_Address 0x00B3

/*** Global Variable ***/
// Low Byte High Byte
typedef volatile union {
	struct{
		uint8_t L; // Lower Address
		uint8_t H; // Higher Address
	}par;
	uint16_t reg;
} HighLowByte;
// Low Word High Word
typedef volatile union {
	struct{
		uint16_t L; // Lower Address
		uint16_t H; // Higher Address
	}par;
	uint32_t reg;
} HighLowWord;

/*****************************/
/**** MAIN HARDWARE LAYER ****/
/*****************************/
// GPWR
typedef struct {
	volatile uint8_t r0; // 0x00
	volatile uint8_t r1; // 0x01
	volatile uint8_t r2; // 0x02
	volatile uint8_t r3; // 0x03
	volatile uint8_t r4; // 0x04
	volatile uint8_t r5; // 0x05
	volatile uint8_t r6; // 0x06
	volatile uint8_t r7; // 0x07
	volatile uint8_t r8; // 0x08
	volatile uint8_t r9; // 0x09
	volatile uint8_t r10; // 0x0A
	volatile uint8_t r11; // 0x0B
	volatile uint8_t r12; // 0x0C
	volatile uint8_t r13; // 0x0D
	volatile uint8_t r14; // 0x0E
	volatile uint8_t r15; // 0x0F
	volatile uint8_t r16; // 0x10
	volatile uint8_t r17; // 0x11
	volatile uint8_t r18; // 0x12
	volatile uint8_t r19; // 0x13
	volatile uint8_t r20; // 0x14
	volatile uint8_t r21; // 0x15
	volatile uint8_t r22; // 0x16
	volatile uint8_t r23; // 0x17
	volatile uint8_t r24; // 0x18
	volatile uint8_t r25; // 0x19
	volatile HighLowByte X; // 0x1A 0x1B
	volatile HighLowByte Y; // 0x1C 0x1D
	volatile HighLowByte Z; // 0x1E 0x1F
} Atmega328GPWR_TypeDef;

// I/O Port (PORTB)
typedef struct {
	PIN_b pin; // 0x23
	DD_rb ddr; // 0x24
	PORT_b port; //0x25
} Atmega328PORTB_TypeDef;

// I/O Port (PORTC)
typedef struct {
	PIN_c pin; // 0x26
	DD_rc ddr; // 0x27
	PORT_c port; // 0x28
} Atmega328PORTC_TypeDef;

// I/O Port (PORTD)
typedef struct {
	PIN_d pin; // 0x29
	DD_rd ddr; // 0x2A
	PORT_d port; // 0x2B
} Atmega328PORTD_TypeDef;

// Timer/Counter 0, 1 and 2 Interrupt Flag
typedef struct {
	TC0_ifr tifr0; // 0x35
	TC1_ifr tifr1; // 0x36
	TC2_ifr tifr2; // 0x37
} Atmega328TimerInterruptFlag_TypeDef;

// External Interrupts Flag (EXINT)
typedef struct {
	EXINT_pcifr pcifr; // 0x3B
	EXINT_ifr eifr; // 0x3C
} Atmega328ExternalInterruptFlag_TypeDef;

// External Interrupts Mask (EXINT)
typedef struct {
	EXINT_imsk eimsk; // 0x3D [eimsk]
} Atmega328ExternalInterruptMask_TypeDef;

// CPU Register Gpio0 (CPU)
typedef struct {
	MCU_gpior0 r0; // 0x3E [gpior0]
} Atmega328CpuGeneralPurposeIoRegister0_TypeDef;

// EEPROM (EEPROM)
typedef struct {
	EEPROM_cr eecr; // 0x3F
	EEPROM_dr eedr; // 0x40
	EEPROM_ar eear; // 0x41
} Atmega328Eeprom_TypeDef;

// TIMER General Control
typedef struct {
	GTC_cr gtccr; // 0x43 [gtccr]
} Atmega328TimerGeneralControlRegister_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	TC0_cra tccr0a; // 0x44
	TC0_crb tccr0b; // 0x45
	TC0_nt tcnt0; // 0x46
	TC0_ocra ocr0a; // 0x47
	TC0_ocrb ocr0b; // 0x48
} Atmega328TimerCounter0_TypeDef;

// Timer/Counter, 8-bit A sync Compare (TC0)
typedef struct {
	TC0_ocra ocr0a; // 0x47
	TC0_ocrb ocr0b; // 0x48
} Atmega328TimerCompareRegister0_TypeDef;

// CPU Register Gpio1 (CPU)
typedef struct {
	MCU_gpior1 r1; // 0x4A [gpior1]
} Atmega328CpuGeneralPurposeIoRegister1_TypeDef;

// CPU Register Gpio012 (CPU)
typedef struct {
	MCU_gpior0 r0; // 0x3E
	uint8_t fill[11]; // (0x4A - 0x3E) - 1
	MCU_gpior1 r1; // 0x4A
	MCU_gpior2 r2; // 0x4B
} Atmega328CpuGeneralPurposeIoRegister_TypeDef;

// CPU Register Gpio2 (CPU)
typedef struct {
	MCU_gpior2 r2; // 0x4B [gpior2]
} Atmega328CpuGeneralPurposeIoRegister2_TypeDef;

// Serial Peripheral Interface (SPI)
typedef struct {
	SPI_cr spcr; // 0x4C
	SPI_sr spsr; // 0x4D
	SPI_dr spdr; // 0x4E
} Atmega328SerialPeripherialInterface_TypeDef;

// Analog Comparator (AC)
typedef struct {
	AC_sr acsr; // 0x50 [acsr]
} Atmega328AnalogComparator_TypeDef;

// Watchdog Timer (WDT)
typedef struct {
	WDT_csr wdtcsr; // 0x60 [wdtcsr]
} Atmega328WatchdogTimer_TypeDef;

// CPU Register (CPU)
typedef struct {
	MCU_smcr smcr; // 0x53
	MCU_sr mcusr; // 0x54
	MCU_cr mcucr; // 0x55
	uint8_t fill1; // (0x57 - 0x55) - 1
	MCU_spmcsr spmcsr; // 0x57
	uint8_t fill2[5]; // (0x5D - 0x57) - 1
	MCU_sp sp; // 0x5D 0x5E
	MCU_sreg sreg; // 0x5F
	uint8_t fill3; // (0x61 - 0x5F) - 1
	MCU_clkpr clkpr; // 0x61
	uint8_t fill4[2]; // (0x64 - 0x61) - 1
	MCU_prr prr; // 0x64
	uint8_t fill5; // (0x66 - 0x64) - 1
	MCU_osccal osccal; // 0x66
} Atmega328CPURegister_TypeDef;

// External Interrupt (EXINT)
typedef struct {
	EXINT_pcicr pcicr; // 0x68
	EXINT_icra eicra; // 0x69
	uint8_t fill; // (0x6B - 0x69) - 1
	EXINT_pcmsk0 pcmsk0; // 0x6B
	EXINT_pcmsk1 pcmsk1; // 0x6C
	EXINT_pcmsk2 pcmsk2; // 0x6D
} Atmega328ExternalInterrupt_TypeDef;

// External Interrupt Pin Change Mask (EXINT)
typedef struct {
	EXINT_pcmsk0 pcmsk0; // 0x6B
	EXINT_pcmsk1 pcmsk1; // 0x6C
	EXINT_pcmsk2 pcmsk2; // 0x6D
} Atmega328ExternalInterruptPinChangeMask_TypeDef;

// Timer/Counter 0, 1 and 2 Interrupt Mask
typedef struct {
	TC0_imsk timsk0; // 0x6E
	TC1_imsk timsk1; // 0x6F
	TC2_imsk timsk2; // 0x70
} Atmega328TimerInterruptMask_TypeDef;

// Analog to Digital Converter (ADC)
typedef struct {
	ADC_dr adc; // 0x78 0x79
	ADC_sra adcsra; // 0x7A
	ADC_srb adcsrb; // 0x7B
	ADC_admux admux; // 0x7C
	uint8_t fill; // (0x7E - 0x7C) - 1
	ADC_didr0 didr0; // 0x7E
	AC_didr1 didr1; // 0x7F
} Atmega328AnalogToDigitalConverter_TypeDef;

// Analog Comparator Did (AC)
typedef struct {
	ADC_didr0 r0; // 0x7E [didr0]
	AC_didr1 r1; // 0x7F [didr1]
} Atmega328AnalogComparatorDid_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	TC1_cra tccr1a; // 0x80
	TC1_crb tccr1b; // 0x81
	TC1_crc tccr1c; // 0x82
	uint8_t fill; // (0x84 - 0x82) - 1
	TC1_nt tcnt1; // 0x84 0x85
	TC1_icr icr1; // 0x86 0x87
	TC1_ocra ocr1a; // 0x88 0x89
	TC1_ocrb ocr1b; // 0x8A 0x8B
} Atmega328TimerCounter1_TypeDef;

// Timer/Counter, 16-bit Compare (TC1)
typedef struct {
	TC1_icr icr1; // 0x86 0x87
	TC1_ocra ocr1a; // 0x88 0x89
	TC1_ocrb ocr1b; // 0x8A 0x8B
} Atmega328TimerCompareRegister1_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	TC2_cra tccr2a; // 0xB0
	TC2_crb tccr2b; // 0xB1
	TC2_nt tcnt2; // 0xB2
	TC2_ocra ocr2a; // 0xB3
	TC2_ocrb ocr2b; // 0xB4
	uint8_t fill; // (0xB6 - 0xB4) - 1
	TC2_assr assr; // 0xB6
} Atmega328TimerCounter2_TypeDef;

// Timer/Counter, 8-bit Compare (TC2)
typedef struct {
	TC2_ocra ocr2a; // 0xB3
	TC2_ocrb ocr2b; // 0xB4
	uint8_t fill; // (0xB6 - 0xB4) - 1
	TC2_assr assr; // 0xB6
} Atmega328TimerCompareRegister2_TypeDef;

// Two Wire Serial Interface (TWI)
typedef struct {
	TWI_br twbr; // 0xB8
	TWI_sr twsr; // 0xB9
	TWI_ar twar; // 0xBA
	TWI_dr twdr; // 0xBB
	TWI_cr twcr; // 0xBC
	TWI_amr twamr; // 0xBD
} Atmega328TwoWireSerialInterface_TypeDef;

// USART (USART0)
typedef struct {
	USART0_csra ucsr0a; // 0xC0
	USART0_csrb ucsr0b; // 0xC1
	USART0_csrc ucsr0c; // 0xC2
	uint8_t fill; // (0xC4 - 0xC2) - 1
	USART0_brr ubrr0; // 0xC4 0xC5
	USART0_dr udr0; // 0xC6
} Atmega328Usart0_TypeDef;

/*** FLASH ***/
// Interrupt Vectors (ISR)
typedef struct { // SRAM START = 0x0100 END = 0x0877 atmega328
	HighLowByte RESET_vect; // 0x0000
	HighLowByte INT0_vect; // 0x0002
	HighLowByte INT1_vect; // 0x0004
	HighLowByte PCINT0_vect; // 0x0006
	HighLowByte PCINT1_vect; // 0x0008
	HighLowByte PCINT2_vect; // 0x000A
	HighLowByte WDT_vect; // 0x000C
	HighLowByte TIMER2_COMPA_vect; // 0x000E
	HighLowByte TIMER2_COMPB_vect; // 0x0010
	HighLowByte TIMER2_OVF_vect; // 0x0012
	HighLowByte TIMER1_CAPT_vect; // 0x0014
	HighLowByte TIMER1_COMPA_vect; // 0x0016
	HighLowByte TIMER1_COMPB_vect; // 0x0018
	HighLowByte TIMER1_OVF_vect; // 0x001A
	HighLowByte TIMER0_COMPA_vect; // 0x001C
	HighLowByte TIMER0_COMPB_vect; // 0x001E
	HighLowByte TIMER0_OVF_vect; // 0x0020
	HighLowByte SPI_STC_vect; // 0x0022
	HighLowByte USART_RX_vect; // 0x0024
	HighLowByte USART_UDRE_vect; // 0x0026
	HighLowByte USART_TX_vect; // 0x0028
	HighLowByte ADC_vect; // 0x002A
	HighLowByte EE_READY_vect; // 0x002C
	HighLowByte ANALOG_COMP_vect; // 0x002E
	HighLowByte TWI_vect; // 0x0030
	HighLowByte SPM_READY_vect; // 0x0032
} Atmega328InterruptVectors_TypeDef;

#endif

/***
CONTROL STATUS IMASK IFLAG
***/

/*** EOF ***/

