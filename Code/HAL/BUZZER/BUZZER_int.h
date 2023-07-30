#ifndef BUZZER_INT_H
#define BUZZER_INT_H

#include "STD_types.h"
#include "BUZZER_config.h"

  void buzzer_init(u8 u8buzzerport,u8 u8buzzerpin);
  void buzzer_on(u8 u8buzzerport,u8 u8buzzerpin);
  void buzzer_off(u8 u8buzzerport,u8 u8buzzerpin);
  
#endif