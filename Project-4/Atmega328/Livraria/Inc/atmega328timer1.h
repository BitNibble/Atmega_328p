/*************************************************************************
	TIMER1
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update:   01/01/2024
*************************************************************************/
/****** Comment:
	Very Stable
*************************************************************************/
#ifndef _ATMEGA328TIMER1_H_
	#define _ATMEGA328TIMER1_H_

/*** Global Library ***/
#include "atmega328.h"

/*** Global Constant & Macro ***/
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif

/*** Global variable ***/
typedef struct{
	// V-table
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
}TC1;

TC1 tc1_enable(unsigned char wavegenmode, unsigned char interrupt);
TC1* tc1(void);

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

/***EOF***/

