/************************************************************************
	Atmega 328 Interrupt
Author:   <sergio.salazar.santos@gmail.com>
Hardware: ATmega328
License:  GNU General Public License 
Update:   01/01/2024
************************************************************************/
/****** Comment:

************************************************************************/
#ifndef _ATMEGA328INTERRUPT_H_
	#define _ATMEGA328INTERRUPT_H_

/*** Global Library ***/
#include "atmega328.h"

/*** Global Constant & Macros ***/
#define MCU_Control_Status_register_Mask 0X0F

/*** Global Variable ***/
typedef struct{
	// V-table
	void (*set)(uint8_t channel, uint8_t sense);
	void (*off)(uint8_t channel);
	uint8_t (*reset_status)(void);
}EXINT0;

EXINT0 exint_enable(void);
EXINT0* exint(void);

#endif

/*** File Interrupt ***/
// ISR(INT0_vect){}
// ISR(INT1_vect){}
	
/*** EOF ***/

