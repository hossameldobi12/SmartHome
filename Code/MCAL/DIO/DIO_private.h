/**
 * @file DIO_private.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA    (*(( volatile u8 *)0x3A))
#define DDRB    (*(( volatile u8 *)0x37))
#define DDRC    (*(( volatile u8 *)0x34))
#define DDRD    (*(( volatile u8 *)0x31))
                     
#define PORTA   (*(( volatile u8 *)0x3B))
#define PORTB   (*(( volatile u8 *)0x38))
#define PORTC   (*(( volatile u8 *)0x35))
#define PORTD   (*(( volatile u8 *)0x32))
                     
#define PINA    (*(( volatile u8 *)0x39))
#define PINB    (*(( volatile u8 *)0x36))
#define PINC    (*(( volatile u8 *)0x33))
#define PIND    (*(( volatile u8 *)0x30))

#endif