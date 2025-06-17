/********************************************************************
	EXPLODE
Author:   <sergio.salazar.santos@gmail.com> 
License:  GNU General Public License
Hardware: all
Date:     16032021
********************************************************************/
/****** Comment:
	Pin Analysis
	Tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RE
********************************************************************/
/*** File Library ***/
#include "explode.h"

/*** File Header ***/
void EXPLODEupdate(explode_parameter* par, IO_var x);
IO_var EXPLODEhh(explode_parameter* par);
IO_var EXPLODEll(explode_parameter* par);
IO_var EXPLODElh(explode_parameter* par);
IO_var EXPLODEhl(explode_parameter* par);
explode_parameter explode_par_inic(void);

/*** EXPLODE Auxilar ***/
explode_parameter explode_par_inic(void)
{
	explode_parameter setup;

	setup.XI = 0;
	setup.XF = 0;

	return setup;
}
/*** EXPLODE Procedure & Function Definition ***/
EXPLODE explode_enable( void )
{
	// struct object
	EXPLODE setup;

	// inic VAR
	setup.par = explode_par_inic();
	// function pointers
	setup.update = EXPLODEupdate;

	return setup;
}
// boot
void EXPLODEupdate(explode_parameter* par, IO_var x)
{
	par->XI = par->XF;
	par->XF = x;
	par->HH = EXPLODEhh(par);
	par->LL = EXPLODEll(par);
	par->LH = EXPLODElh(par);
	par->HL = EXPLODEhl(par);
}
// hh
IO_var EXPLODEhh(explode_parameter* par)
{
	return (par->XI & par->XF);
}
// ll
IO_var EXPLODEll(explode_parameter* par)
{
	return ~(par->XI | par->XF);
}
// lh
IO_var EXPLODElh(explode_parameter* par)
{
	IO_var i;
	i = par->XI ^ par->XF;
	i &= par->XF;
	return i;
}
// hl
IO_var EXPLODEhl(explode_parameter* par)
{
	IO_var i;
	i = par->XF ^ par->XI;
	i &= par->XI;
	return i;
}

/*** EOF ***/

