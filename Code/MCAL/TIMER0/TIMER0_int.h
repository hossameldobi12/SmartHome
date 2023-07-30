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


#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H
#include "STD_types.h"

void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_u8Val);

void TIMER0_void_SetCompareVal(u8 Copy_u8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);





#endif

