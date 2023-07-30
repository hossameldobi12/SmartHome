

#include "STD_types.h"
#include "BIT_math.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_int.h"







void SPIint(void)
{
    //Data order
    #if SPI_U8_DATA_ORDER == SPI_U8_MSB
    CLEAR_BIT(SPCR, 5);
    #elif SPI_U8_DATA_ORDER == SPI_U8_LSB
    SET_BIT(SPCR, 5);
    #endif

    //Clock speed
    #if SPI_U8_SPEED == SPI_U8_FOSC_2
    SET_BIT(SPSR, 0);
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_4
    CLEAR_BIT(SPSR, 0);
    CLEAR_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_8
    SET_BIT(SPSR, 0);
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_16
    CLEAR_BIT(SPSR, 0);
    SET_BIT(SPCR, 0);
    CLEAR_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_32
    SET_BIT(SPSR, 0);
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_64
    CLEAR_BIT(SPSR, 0);
    CLEAR_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    #elif SPI_U8_SPEED == SPI_U8_FOSC_128
    CLEAR_BIT(SPSR, 0);
    SET_BIT(SPCR, 0);
    SET_BIT(SPCR, 1);
    #endif

    //Slave and Master select
    #if SPI_U8_MASTER_SLAVE == SPI_U8_MASTER
    SET_BIT(SPCR, 4);
    #elif SPI_U8_MASTER_SLAVE == SPI_U8_SLAVE
    CLEAR_BIT(SPCR,4);
    #endif

    //Clock Polarity
    #if SPI_U8_CLKPOL == SPI_U8_IDLE_LOW
    CLEAR_BIT(SPCR, 3);
    #elif SPI_U8_CLKPOL == SPI_U8_IDLE_HIGH
    SET_BIT(SPCR, 3);
    #endif

    //Clock phase
    #if SPI_U8_CLKPHA == SPI_U8_LEADING
    CLEAR_BIT(SPCR, 2);
    #elif SPI_U8_CLKPHA == SPI_U8_TRAILING
    SET_BIT(SPCR, 2);
    #endif

    //SPI enable
    #if  SPI_U8_ENABLE_DISABLE == SPI_U8_ENABLE
    SET_BIT(SPCR, 6);
    #elif SPI_U8_ENABLE_DISABLE == SPI_U8_DISABLE
    CLEAR_BIT(SPCR, 6);
    #endif
}

u8 TransferData(u8 data)
{
    SPDR = data;
    while(GET_BIT(SPSR, 7) == 0);
    return SPDR;
}