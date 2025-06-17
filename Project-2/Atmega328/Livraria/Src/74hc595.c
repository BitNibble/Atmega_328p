/*************************************************************************
	74HC595
Author:   <sergio.salazar.santos@gmail.com>
License:  GNU General Public License     
Hardware: 74HC595
Date:     25/10/2020
Update:   05/01/2024
************************************************************************/
/****** Comment:
	Tested Atemga88 8Mhz and Atmega328 8Mhz and STM32F446RE
************************************************************************/
/*** File Library ***/
#include "74hc595.h"

/*** File Header ***/
void HC595_shift_bit(hc595_parameter* par, uint8_t state);
void HC595_shift_ibyte(hc595_parameter* par, uint8_t byte);
void HC595_shift_byte(hc595_parameter* par, uint8_t byte);
void HC595_shift_out(hc595_parameter* par);
hc595_parameter hc595_par_inic(volatile IO_var *ddr, volatile IO_var *port, uint8_t datapin, uint8_t clkpin, uint8_t outpin);

/*** 74HC595 Auxiliar ***/
hc595_parameter hc595_par_inic(volatile IO_var *ddr, volatile IO_var *port, uint8_t datapin, uint8_t clkpin, uint8_t outpin)
{
	hc595_parameter setup;

	setup.hc595_DDR = ddr;
	setup.hc595_PORT = port;
	setup.HC595_datapin = datapin;
	setup.HC595_clkpin = clkpin;
	setup.HC595_outpin = outpin;
	
	#if defined (STM32F446xx)
		*setup.hc595_DDR &= (IO_var) ~((3 << (datapin * 2)) | (3 << (clkpin * 2)) | (3 << (outpin * 2)));
		*setup.hc595_DDR |= ((1 << (datapin * 2)) | (1 << (clkpin * 2)) | (1 << (outpin * 2)));
	#else
		*setup.hc595_DDR |= (1 << datapin) | (1 << clkpin) | (1 << outpin);
	#endif
		*setup.hc595_PORT &= ~((1 << datapin) | (1 << clkpin) | (1 << outpin));

	return setup;
}

/*** 74HC595 Procedure & Function Definition ***/
HC595 hc595_enable(volatile IO_var *ddr, volatile IO_var *port, uint8_t datapin, uint8_t clkpin, uint8_t outpin)
{
	HC595 setup;

	setup.par = hc595_par_inic(ddr, port, datapin, clkpin, outpin);
	// Direccionar apontadores para PROTOTIPOS
	setup.bit = HC595_shift_bit;
	setup.ibyte = HC595_shift_ibyte;
	setup.byte = HC595_shift_byte;
	setup.out = HC595_shift_out;
	
	return setup;
}

void HC595_shift_bit(hc595_parameter* par, uint8_t state)
{
	if (state)
		*par->hc595_PORT |= (1 << par->HC595_datapin); // Data bit HIGH
	else
		*par->hc595_PORT &= ~(1 << par->HC595_datapin); // Data bit LOW
	*par->hc595_PORT |= (1 << par->HC595_clkpin); // Shift bit
	*par->hc595_PORT &= ~(1 << par->HC595_clkpin); //Shift disable
}

void HC595_shift_ibyte(hc595_parameter* par, uint8_t byte)
{
	uint8_t i;
	for(i = 0; i < 8; i++)
		HC595_shift_bit(par, byte & (1 << i));
	HC595_shift_out(par);
}

void HC595_shift_byte(hc595_parameter* par, uint8_t byte)
{
	uint8_t i;
	for(i = 0; i < 8; i++)
		HC595_shift_bit(par, byte & (1 << (7 - i)));
	HC595_shift_out(par);
}

void HC595_shift_out(hc595_parameter* par)
{
	*par->hc595_PORT |= (1 << par->HC595_outpin); // Output enable
	*par->hc595_PORT &= ~(1 << par->HC595_outpin); // Output disable
}

/*** EOF ***/

