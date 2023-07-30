/**
 * @file LCD_config.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/* Pin selection */
#define LCD_U8_PIN_D0   DIO_U8_PIN0
#define LCD_U8_PIN_D1   DIO_U8_PIN1
#define LCD_U8_PIN_D2   DIO_U8_PIN2
#define LCD_U8_PIN_D3   DIO_U8_PIN3
#define LCD_U8_PIN_D4   DIO_U8_PIN4
#define LCD_U8_PIN_D5   DIO_U8_PIN5
#define LCD_U8_PIN_D6   DIO_U8_PIN6
#define LCD_U8_PIN_D7   DIO_U8_PIN7


#define LCD_U8_PIN_RS   DIO_U8_PIN1
#define LCD_U8_PIN_RW   DIO_U8_PIN2
#define LCD_U8_PIN_E    DIO_U8_PIN3

#define LCD_U8_PORT_D0   DIO_U8_PORTA
#define LCD_U8_PORT_D1   DIO_U8_PORTA
#define LCD_U8_PORT_D2   DIO_U8_PORTA
#define LCD_U8_PORT_D3   DIO_U8_PORTA
#define LCD_U8_PORT_D4   DIO_U8_PORTA
#define LCD_U8_PORT_D5   DIO_U8_PORTA
#define LCD_U8_PORT_D6   DIO_U8_PORTA
#define LCD_U8_PORT_D7   DIO_U8_PORTA

#define LCD_U8_PORT_RS   DIO_U8_PORTB
#define LCD_U8_PORT_RW   DIO_U8_PORTB
#define LCD_U8_PORT_E    DIO_U8_PORTB

/*
LCD_U8_8_BIT
LCD_U8_4_BIT
*/

#define LCD_U8_DATA_LENGTH LCD_U8_4_BIT


#endif 