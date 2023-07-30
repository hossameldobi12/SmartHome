#include "STD_types.h"
#include "DIO_int.h"
#include "BUZZER_config.h"
#include "BUZZER_int.h"



 void buzzer_init(u8 u8buzzerport,u8 u8buzzerpin)
 {
  DIO_voidSetPinDir(u8buzzerport,u8buzzerpin,DIO_U8_OUTPUT);
 }
  void buzzer_on(u8 u8buzzerport,u8 u8buzzerpin)
  {
   DIO_voidSetPinVal(u8buzzerport,u8buzzerpin,DIO_U8_HIGH);
  }
  void buzzer_off(u8 u8buzzerport,u8 u8buzzerpin)
  {
    DIO_voidSetPinVal(u8buzzerport,u8buzzerpin,DIO_U8_LOW);
  }