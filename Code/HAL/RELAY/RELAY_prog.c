#include "STD_types.h"
#include "DIO_int.h"
#include "RELAY_config.h"
#include "RELAY_private.h"



 void relay_init(u8 u8relayport,u8 u8relaypin)
 {
  DIO_voidSetPinDir(u8relayport,u8relaypin,DIO_U8_OUTPUT);
 }
  void relay_on(u8 u8relayport,u8 u8relaypin)
  {
   DIO_voidSetPinVal(u8relayport,u8relaypin,DIO_U8_HIGH);
  }
  void relay_off(u8 u8relayport,u8 u8relaypin)
  {
    DIO_voidSetPinVal(u8relayport,u8relaypin,DIO_U8_LOW);
  }