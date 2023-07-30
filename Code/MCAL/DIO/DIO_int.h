/**
 * @file DIO_int.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_U8_PORTA 0
#define DIO_U8_PORTB 1
#define DIO_U8_PORTC 2
#define DIO_U8_PORTD 3

#define DIO_U8_PIN0    0
#define DIO_U8_PIN1    1
#define DIO_U8_PIN2    2
#define DIO_U8_PIN3    3
#define DIO_U8_PIN4    4
#define DIO_U8_PIN5    5
#define DIO_U8_PIN6    6
#define DIO_U8_PIN7    7


#define DIO_U8_OUTPUT  1
#define DIO_U8_INPUT   0


#define DIO_U8_HIGH  1
#define DIO_U8_LOW   0

void DIO_voidSetPinDir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir);
void DIO_voidSetPinVal(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 DIO_u8GetPinVal(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif