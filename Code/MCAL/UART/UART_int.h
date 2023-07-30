/**
 * @file TIMER0_int.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _UART_INT_H
#define _UART_INT_H
#include "STD_types.h"
#include "UART_config.h"



void UART_Initialize(UART_Mode mode, UART_Parity parity, UART_StopBits stop, UART_DataMode data);
void UART_Transmit(u8 dataTransmit);
u8 UART_Received(void);

void UART_SENDSTRING(const char* data);
u8 UART_RECEIVESTRING(u8 * data );

void uart_ini(void);
void uart_sendchar(u8 * data);
void UART_SENDSTRING(const char* data);
 u8 UART_RECEIVESTRING(u8 * data );




#endif

