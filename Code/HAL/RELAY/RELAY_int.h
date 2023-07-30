#ifndef RELAY_INT_H
#define RELAY_INT_H

#include "STD_types.h"
#include "RELAY_config.h"

  void relay_init(u8 u8relayport,u8 u8relaypin);
  void relay_on(u8 u8relayport,u8 u8relaypin);
  void relay_off(u8 u8relayport,u8 u8relaypin);
  
#endif