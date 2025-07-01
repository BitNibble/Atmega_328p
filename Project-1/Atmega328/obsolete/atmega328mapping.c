/********************************************************************
	ATMEGA 328 MAPPING
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update:   01/01/2024
*********************************************************************/
/****** Comment:
	Virtual Image Atmega 328 mapping and linking.
*********************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"

static ATMEGA328 setup_atmega328;

/*** File Procedure & Function ***/
ATMEGA328 atmega328_enable(void){
	/***GPWR***/
	setup_atmega328.gpwr_instance = gpwr_instance();
	/***AC***/
	setup_atmega328.ac_instance = ac_instance();
	setup_atmega328.ac_did_instance = ac_did_instance();
	/***ADC***/
	setup_atmega328.adc_instance = adc_instance();
	#if defined(_ANALOG_MODULE_)
		setup_atmega328.adc_enable = adc_enable;
		setup_atmega328.adc = adc();
	#endif
	/***CPU***/
	setup_atmega328.cpu_instance = cpu_instance();
	setup_atmega328.cpu_gpio012_instance = cpu_gpio012_instance();
	/***EEPROM***/
	setup_atmega328.eeprom_instance = eeprom_instance();
	#if defined(_EEPROM_MODULE_)
		setup_atmega328.eeprom_enable = eeprom_enable;
		setup_atmega328.eeprom = eeprom();
	#endif
	/***EXINT***/
	setup_atmega328.exint_instance = exint_instance();
	setup_atmega328.exint_iflag_instance = exint_iflag_instance();
	setup_atmega328.exint_imask_instance = exint_imask_instance();
	setup_atmega328.exint_pcmask_instance = exint_pcmask_instance();
	#if defined(_INTERRUPT_MODULE_)
		setup_atmega328.exint_enable = exint_enable;
		setup_atmega328.exint = exint();
	#endif
	/***PORTB***/
	setup_atmega328.portb_instance = portb_instance();
	/***PORTC***/
	setup_atmega328.portc_instance = portc_instance();
	/***PORTD***/
	setup_atmega328.portd_instance = portd_instance();
	/***SPI***/
	setup_atmega328.spi_instance = spi_instance();
	#if defined(_SPI_MODULE_)
		setup_atmega328.spi_enable = spi_enable;
		setup_atmega328.spi = spi();
	#endif
	/***TC1***/
	setup_atmega328.tc1_instance = tc1_instance();
	setup_atmega328.tc1_gcontrol_instance = tc_gcontrol_instance();
	setup_atmega328.tc1_iflag_instance = tc_iflag_instance();
	setup_atmega328.tc1_imask_instance = tc_imask_instance();
	setup_atmega328.tc1_compare_instance = tc1_compare_instance();
	#if defined(_TIMER1_MODULE_)
		setup_atmega328.tc1_enable = tc1_enable;
		setup_atmega328.tc1 = tc1();
	#endif
	/***TC0***/
	setup_atmega328.tc0_instance = tc0_instance();
	setup_atmega328.tc0_gcontrol_instance = tc_gcontrol_instance();
	setup_atmega328.tc0_iflag_instance = tc_iflag_instance();
	setup_atmega328.tc0_imask_instance = tc_imask_instance();
	setup_atmega328.tc0_compare_instance = tc0_compare_instance();
	#if defined(_TIMER0_MODULE_)
		setup_atmega328.tc0_enable = tc0_enable;
		setup_atmega328.tc0 = tc0();
	#endif
	/***TC2***/
	setup_atmega328.tc2_instance = tc2_instance();
	setup_atmega328.tc2_gcontrol_instance = tc_gcontrol_instance();
	setup_atmega328.tc2_iflag_instance = tc_iflag_instance();
	setup_atmega328.tc2_imask_instance = tc_imask_instance();
	setup_atmega328.tc2_compare_instance = tc2_compare_instance();
	#if defined(_TIMER2_MODULE_)
		setup_atmega328.tc2_enable = tc2_enable;
		setup_atmega328.tc2 = tc2();
	#endif
	/***TWI***/
	setup_atmega328.twi_instance = twi_instance();
	#if defined(_TWI_MODULE_)
		setup_atmega328.twi_enable = twi_enable;
		setup_atmega328.twi = twi();
	#endif
	/***USART***/
	setup_atmega328.usart0_instance = usart0_instance();
	#if defined(_USART0_MODULE_)
		setup_atmega328.usart0_enable = usart0_enable;
	#endif
	/***WDT***/
	setup_atmega328.wdt_instance = wdt_instance();
	/*** Pointer Function***/
	setup_atmega328.Clock_Prescaler_Select = Atmega328ClockPrescalerSelect;
	setup_atmega328.Move_Interrupts_To_Boot = Atmega328MoveInterruptsToBoot;
	
	return setup_atmega328;
}

ATMEGA328* atmega328(void){ return &setup_atmega328; }

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

/*** EOF ***/

