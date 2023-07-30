/**
 * @file DIO_prog.c
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_private.h"


void DIO_voidSetPinDir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir)
{
	switch(Copy_u8Port)
	{
		case DIO_U8_PORTA:
		if(Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRA,Copy_u8Pin);
		}
		else if(Copy_u8Dir == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRA,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTB:
		if(Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRB,Copy_u8Pin);
		}
		else if(Copy_u8Dir == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRB,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTC:
		if(Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRC,Copy_u8Pin);
		}
		else if(Copy_u8Dir == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRC,Copy_u8Pin);
		}
		break;
		
		
		case DIO_U8_PORTD:
		if(Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRD,Copy_u8Pin);
		}
		else if(Copy_u8Dir == DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRD,Copy_u8Pin);
		}
		break;
	}
}
void DIO_voidSetPinVal(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case DIO_U8_PORTA:
		if(Copy_u8Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTA,Copy_u8Pin);
		}
		else if(Copy_u8Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTA,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTB:
		if(Copy_u8Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTB,Copy_u8Pin);
		}
		else if(Copy_u8Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTB,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTC:
		if(Copy_u8Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTC,Copy_u8Pin);
		}
		else if(Copy_u8Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTC,Copy_u8Pin);
		}
		break;
		
		
		case DIO_U8_PORTD:
		if(Copy_u8Value == DIO_U8_HIGH)
		{
			SET_BIT(PORTD,Copy_u8Pin);
		}
		else if(Copy_u8Value == DIO_U8_LOW)
		{
			CLEAR_BIT(PORTD,Copy_u8Pin);
		}
		break;
	}	
}
u8 DIO_u8GetPinVal(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Result = 0;
	switch(Copy_u8Port)
	{
		case DIO_U8_PORTA:
		Local_u8Result = GET_BIT(PINA , Copy_u8Pin);
		break;
		
		case DIO_U8_PORTB:
		Local_u8Result = GET_BIT(PINB , Copy_u8Pin);
		break;
		
		case DIO_U8_PORTC:
		Local_u8Result = GET_BIT(PINC , Copy_u8Pin);
		break;
		
		case DIO_U8_PORTD:
		Local_u8Result = GET_BIT(PIND , Copy_u8Pin);
		break;
	}

return 	Local_u8Result;
}