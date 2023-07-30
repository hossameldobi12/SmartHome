/*
* ADC_Interfacing.c
*
* Created: 9/30/2022 11:41:13 AM
*  Author: User
*/
#include "STD_types.h"
#include "BIT_math.h"
#include  <avr/io.h>
#include "ADC_Config.h"
#include "ADC_int.h"

void ADC_Initialization(void)
{
		/*enable ADC peripheral in MCU*/
	SET_BIT(ADCSRA, ADEN);
	/*set reference voltage to internal reference voltage = 2.56v. */
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
	/*select input channel to pin PA2*/
	CLEAR_BIT(ADMUX, MUX0);
	CLEAR_BIT(ADMUX, MUX1);
	CLEAR_BIT(ADMUX, MUX2);
	CLEAR_BIT(ADMUX, MUX3);
	CLEAR_BIT(ADMUX, MUX4);
	/*clear ADLAR bit, so the first 8-bits will return in ADCL, and last 2-bits in ADCH*/
	CLEAR_BIT(ADMUX, ADLAR);
	/*clear AUTO trigger ADC, so the ADC conversion will start only when you call:  ADC_convert_read() */
	CLEAR_BIT(ADCSRA, ADATE);
	/*disable ADC interrupt: */
	CLEAR_BIT(ADCSRA, ADIE);
	/*set pre-scaler to be: (F_CPU/64) = (8000000/64) = 125 KHz */
	CLEAR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
}
u16 ADC_READ(void)
{
		u16 ADC_data = 0;
	/*start conversion:*/
	SET_BIT(ADCSRA, ADSC);
	/*wait until conversion ended*/
	while(GET_BIT(ADCSRA, ADSC) == 1)
	{
		//wait until ADSC bit becomes zero
	}
	/*after conversion is finished, read data from ADCL then ADCH*/
	ADC_data = ADCL;
	ADC_data |= (ADCH << 8);
	/*return ADC data*/
	return ADC_data;
	
}
