/**
 * @file LCD_prog.c
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "STD_types.h"
#include  "BIT_math.h"
#include "DIO_int.h"
#include  "LCD_private.h"
#include  "LCD_config.h"
#include  "LCD_int.h"
#include   "avr/io.h"
#include <util/delay.h>


void lcd_init(void)
{
	
	DIO_voidSetPinDir(LCD_U8_PORT_RS , LCD_U8_PIN_RS , DIO_U8_OUTPUT);	
	DIO_voidSetPinDir(LCD_U8_PORT_RW , LCD_U8_PIN_RW , DIO_U8_OUTPUT);	
	DIO_voidSetPinDir(LCD_U8_PORT_E ,  LCD_U8_PIN_E  , DIO_U8_OUTPUT);	

	DIO_voidSetPinDir(LCD_U8_PORT_D4 , LCD_U8_PIN_D4 , DIO_U8_OUTPUT);	
	DIO_voidSetPinDir(LCD_U8_PORT_D5 , LCD_U8_PIN_D5 , DIO_U8_OUTPUT);	
	DIO_voidSetPinDir(LCD_U8_PORT_D6 , LCD_U8_PIN_D6 , DIO_U8_OUTPUT);	
	DIO_voidSetPinDir(LCD_U8_PORT_D7 , LCD_U8_PIN_D7 , DIO_U8_OUTPUT);
	
		_delay_ms(35);
		lcd_display_inist(0x33);
		_delay_ms(2);
		lcd_display_inist(0x32);
		_delay_ms(2);
		lcd_display_inist(0x28);
		_delay_ms(2);
		lcd_display_inist(0x01);
		_delay_ms(2);
		lcd_display_inist(0x02);
		_delay_ms(2);
		lcd_display_inist(0x0C);
		_delay_ms(2);
		lcd_display_inist(0x06);
		_delay_ms(2);

	
	
}
void lcd_display_data(u8 Copy_u8Data)
{
	DIO_voidSetPinVal(LCD_U8_PORT_RS , LCD_U8_PIN_RS , DIO_U8_HIGH);
	DIO_voidSetPinVal(LCD_U8_PORT_RW , LCD_U8_PIN_RW , DIO_U8_LOW);	

    /*if(DIO_u8GetPinVal(Copy_u8Data , 4) == 1)
	{
		DIO_voidSetPinVal(LCD_U8_PORT_D4 , LCD_U8_PIN_D4 , DIO_U8_HIGH);
	}	
    else
	{
		DIO_voidSetPinVal(LCD_U8_PORT_D4 , LCD_U8_PIN_D4 , DIO_U8_LOW);
	}*/

      PORTA = Copy_u8Data; // high nibble
	
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_LOW);
	_delay_ms(1);
	
    PORTA = Copy_u8Data << 4; // high nibble
	
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_LOW);
	_delay_ms(1);
}
void lcd_display_inist(u8 Copy_u8Inst)
{
	DIO_voidSetPinVal(LCD_U8_PORT_RS , LCD_U8_PIN_RS , DIO_U8_LOW);
	DIO_voidSetPinVal(LCD_U8_PORT_RW , LCD_U8_PIN_RW , DIO_U8_LOW);	

    PORTA = Copy_u8Inst; // high nibble
	
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_LOW);
	_delay_ms(1);
	
    PORTA = Copy_u8Inst << 4; // high nibble
	
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinVal(LCD_U8_PORT_E , LCD_U8_PIN_E , DIO_U8_LOW);
	_delay_ms(1);	
}
void lcd_display_string(s8 *P_s8String)
{
	u8 Local_u8Index = 0;
	while(P_s8String[Local_u8Index] != '\0')
	{
		lcd_display_data(P_s8String[Local_u8Index]);
		Local_u8Index++;
	}
}
void lcd_clear(void)

{
	lcd_display_inist(0b00000001);
	_delay_ms(2);
}
void lcd_setcursor(u8 Copy_u8Row ,u8 Copy_u8Col)
{   u8 Local_u8Adress = 0x80;
	switch(Copy_u8Row)
	{
		case LCD_U8_ROW1:
			Local_u8Adress = 0x80 + Copy_u8Col;
		break;
		case LCD_U8_ROW2:
			Local_u8Adress = 0xC0 + Copy_u8Col;
		break;
	}
	lcd_display_inist(Local_u8Adress);
}

void LCD_voidCustomChar(u8 Copy_u8Location ,s8* P_s8String)
{  
	lcd_display_inist(Copy_u8Location);
	for(u8 i=0; i <8; i++)
	{
		lcd_display_data(P_s8String[i]);
	}
}

