/*
 * LM35_Interface.c
 *
 * Created: 12/23/2022 6:49:57 PM
 *  Author: dutzr
 */ 
#include "STD_types.h"
#include "LM35_Private.h"
#include "ADC_int.h"
u16 First_LM35_read(void)
{
	u16 temp = 0;
	temp = ADC_READ();
	temp = (temp*0.25);
	return temp;	
}
