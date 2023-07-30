
/**
 * @file SPI_PRIVATE_H
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H

#define SPDR *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)
#define SPCR *((volatile u8*)0x2D)

#define SPI_U8_MSB 0
#define SPI_U8_LSB 1

#define SPI_U8_FOSC_2 2
#define SPI_U8_FOSC_4 4
#define SPI_U8_FOSC_8 8
#define SPI_U8_FOSC_16 16
#define SPI_U8_FOSC_32 32
#define SPI_U8_FOSC_64 64
#define SPI_U8_FOSC_128 128

#define SPI_U8_MASTER 1
#define SPI_U8_SLAVE 0

#define SPI_U8_IDLE_HIGH 1
#define SPI_U8_IDLE_LOW 0

#define SPI_U8_TRAILING 1
#define SPI_U8_LEADING 0

#define SPI_U8_ENABLE 1
#define SPI_U8_DISABLE 0


#endif
