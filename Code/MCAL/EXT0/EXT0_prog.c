/**
 * @file EXT0_prog.c
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


  #include "STD_types.h"
  #include "BIT_math.h"
  #include "EXT0_private.h"
  #include  "EXT0_config.h"
  #include  "EXT0_int.h"



void EXT0_init (void)
{
  #if EXT0_ISC == EXT0_Rising

  SET_BIT(MCUCR,0);
  SET_BIT(MCUCR,1);

  #elif EXT0_ISC == EXT0_Falling

  CLEAR_BIT(MCUCR,0);
  SET_BIT(MCUCR,1);

   #elif EXT0_ISC == EXT0_Any_Change
   SET_BIT(MCUCR,1);
   CLEAR_BIT(MCUCR0);

   #elif EXT0_ISC == EXT0_Low
   CLEAR_BIT (MCUCR,0);
   CLEAR_BIT (MCUCR,1);

   #endif
}
void EXT0_enable (void)
{
    SET_BIT(GICR,6);
}
void EXT0_disable (void)
{
CLEAR_BIT(GICR,6);
}
void EXT0_clear_flag (void)
{
  SET_BIT(GIFR,6);
}