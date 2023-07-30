/**
 * @file TIMER0_config.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef  _UART_CONFIG_H
#define _UART_CONFIG_H


//#define FRQ      160000
#define BaudRate 9600ul
//UART mode
typedef enum
{
	Asynchronous = 0,
	Synchronous = 1
}UART_Mode;
//UART Parity
typedef enum
{
	Disable = 0,
	Even = 1,
	Odd = 2
}UART_Parity;
//UART Stop Bits
typedef enum
{
	Bit_1 = 0,
	Bit_2 = 1
}UART_StopBits;
//UART Data Modes
typedef enum
{
	Bits_5 = 0,
	Bits_6 = 1,
	Bits_7 = 2,
	Bits_8 = 3,
	Bits_9 = 4
}UART_DataMode;


#endif
