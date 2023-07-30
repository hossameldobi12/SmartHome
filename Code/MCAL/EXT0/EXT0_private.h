/**
 * @file EXT0_private.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef EXT0_PRIVATE_H_
#define EXT0_PRIVATE_H_

#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)


#define EXT0_Rising        0
#define EXT0_Falling       1
#define EXT0_Any_Change    2
#define EXT0_Low           3



#endif