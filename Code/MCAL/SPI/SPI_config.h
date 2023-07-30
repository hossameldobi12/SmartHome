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

#ifndef  _SPI_CONFIG_H
#define _SPI_CONFIG_H

/*
SPI_U8_MSB
SPI_U8_LSB
*/
#define SPI_U8_DATA_ORDER       SPI_U8_MSB

/*
SPI_U8_FOSC_2
SPI_U8_FOSC_4
SPI_U8_FOSC_8
SPI_U8_FOSC_16
SPI_U8_FOSC_32
SPI_U8_FOSC_64
SPI_U8_FOSC_128
*/
#define SPI_U8_SPEED            SPI_U8_FOSC_128

/*
SPI_U8_MASTER
SPI_U8_SLAVE
*/
#define SPI_U8_MASTER_SLAVE     SPI_U8_MASTER

/*
SPI_U8_IDLE_LOW
SPI_U8_IDLE_HIGH
*/
#define SPI_U8_CLKPOL           SPI_U8_IDLE_LOW

/*
SPI_U8_LEADING
SPI_U8_TRAILING
*/ 
#define SPI_U8_CLKPHA           SPI_U8_LEADING

/*
SPI_U8_ENABLE
SPI_U8_DISABLE
*/
#define SPI_U8_ENABLE_DISABLE   SPI_U8_DISABLE




#endif
