/*************************************************************************
	TIMER2
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update:   01/01/2024
*************************************************************************/
/***** Comment:
	Very Stable
*************************************************************************/
#ifndef _ATMEGA328TIMER2_H_
	#define _ATMEGA328TIMER2_H_

/*** Global Library ***/
#include "atmega328instance.h"

/*** Global Constant & Macro ***/
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#ifndef GLOBAL_INTERRUPT_ENABLE
		#define GLOBAL_INTERRUPT_ENABLE 7
	#endif
#else
	#error "Not Atmega 328"
#endif

/*** Global variable ***/
typedef struct{
	Atmega328TimerGeneralControlRegister_TypeDef* gcontrol_instance;
	Atmega328TimerCompareRegister2_TypeDef* compare_instance;
	Atmega328TimerInterruptMask_TypeDef* imask_instance;
	Atmega328TimerInterruptFlag_TypeDef* iflag_instance;
	Atmega328TimerCounter2_TypeDef* instance;
	// V-table
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
}TC2;

TC2 tc2_enable(unsigned char wavegenmode, unsigned char interrupt);
TC2* tc2(void);

#endif

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
	
/*** EOF ***/

