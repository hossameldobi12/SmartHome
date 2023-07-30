/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 11-11-2022            */
/*          Version: 1.0                */
/*          Module: KEYPAD              */
/****************************************/
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO_int.h"

/* Pin selection */
#define KEYPAD_U8_PIN_C1   DIO_U8_PIN3
#define KEYPAD_U8_PIN_C2   DIO_U8_PIN6
#define KEYPAD_U8_PIN_C3   DIO_U8_PIN5
#define KEYPAD_U8_PIN_C4   DIO_U8_PIN4

#define KEYPAD_U8_PORT_C1  DIO_U8_PORTD
#define KEYPAD_U8_PORT_C2  DIO_U8_PORTD
#define KEYPAD_U8_PORT_C3  DIO_U8_PORTD
#define KEYPAD_U8_PORT_C4  DIO_U8_PORTD
 
#define KEYPAD_U8_PIN_R1   DIO_U8_PIN0
#define KEYPAD_U8_PIN_R2   DIO_U8_PIN1
#define KEYPAD_U8_PIN_R3   DIO_U8_PIN2
#define KEYPAD_U8_PIN_R4   DIO_U8_PIN3

#define KEYPAD_U8_PORT_R1  DIO_U8_PORTC
#define KEYPAD_U8_PORT_R2  DIO_U8_PORTC
#define KEYPAD_U8_PORT_R3  DIO_U8_PORTC
#define KEYPAD_U8_PORT_R4  DIO_U8_PORTC

#define KEYPAD_U8_R1C1  '7'
#define KEYPAD_U8_R1C2  '8'
#define KEYPAD_U8_R1C3  '9'
#define KEYPAD_U8_R1C4  '/'

#define KEYPAD_U8_R2C1  '4'
#define KEYPAD_U8_R2C2  '5'
#define KEYPAD_U8_R2C3  '6'
#define KEYPAD_U8_R2C4  '*'

#define KEYPAD_U8_R3C1  '1'
#define KEYPAD_U8_R3C2  '2'
#define KEYPAD_U8_R3C3  '3'
#define KEYPAD_U8_R3C4  '-'

#define KEYPAD_U8_R4C1  '/'
#define KEYPAD_U8_R4C2  '0'
#define KEYPAD_U8_R4C3  '='
#define KEYPAD_U8_R4C4  '+'
/*
KEYPAD_U8_EXT_PULL_UP
KEYPAD_U8_INT_PULL_UP
*/

#define KEYPAD_U8_MODE KEYPAD_U8_INT_PULL_UP

#endif