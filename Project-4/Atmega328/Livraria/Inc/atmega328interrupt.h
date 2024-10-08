/************************************************************************
	Atmega 328 Interrupt
Author: Sergio Manuel Santos
		<sergio.salazar.santos@gmail.com>
Hardware: ATmega328
License: GNU General Public License 
Update: 01/01/2024
************************************************************************/
/****** Comment:

************************************************************************/
#ifndef _ATMEGA328INTERRUPT_H_
	#define _ATMEGA328INTERRUPT_H_

/*** Global Library ***/
#include "atmega328instance.h"

/*** Global Constant & Macros ***/
//#define External_Interrupt_Flag_instanceister EIFR
//#define Pin_Change_Interrrupt_Control_instanceister PCICR
//#define Pin_Change_Interrupt_Flag_instanceister PCIFR
//#define Pin_Change_Mask_instanceister_2 PCMSK2
//#define Pin_Change_Mask_instanceister_1 PCMSK1
//#define Pin_Change_Mask_instanceister_0 PCMSK0
//#define MCU_Control_Status_instanceister MCUSR
#define MCU_Control_Status_instanceister_Mask 0X0F

/*** Global Variable ***/
typedef struct{
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

