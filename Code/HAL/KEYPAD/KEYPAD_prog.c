/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 11-11-2022            */
/*          Version: 1.0                */
/*          Module: KEYPAD              */
/****************************************/
#include "STD_types.h"
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

void KEYPAD_voidInit(void)
{
	/*pin directions */
	DIO_voidSetPinDir(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1,DIO_U8_INPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2,DIO_U8_INPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3,DIO_U8_INPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4,DIO_U8_INPUT);
	
	DIO_voidSetPinDir(KEYPAD_U8_PORT_R1,KEYPAD_U8_PIN_R1,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_R2,KEYPAD_U8_PIN_R2,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_R3,KEYPAD_U8_PIN_R3,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_U8_PORT_R4,KEYPAD_U8_PIN_R4,DIO_U8_OUTPUT);
	
	
	#if KEYPAD_U8_MODE == KEYPAD_U8_INT_PULL_UP
	DIO_voidSetPinVal(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4,DIO_U8_HIGH);	
	
	#elif KEYPAD_U8_MODE == KEYPAD_U8_EXT_PULL_UP
	
	
	#endif
}
u8 KEYPAD_u8GetButton(void)
{
	u8 Local_u8Button = KEYPAD_U8_NULL;
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R1,KEYPAD_U8_PIN_R1,DIO_U8_LOW);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R2,KEYPAD_U8_PIN_R2,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R3,KEYPAD_U8_PIN_R3,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R4,KEYPAD_U8_PIN_R4,DIO_U8_HIGH);
	
	if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R1C1;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R1C2;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R1C3;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R1C4;
	}
	
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R1,KEYPAD_U8_PIN_R1,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R2,KEYPAD_U8_PIN_R2,DIO_U8_LOW);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R3,KEYPAD_U8_PIN_R3,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R4,KEYPAD_U8_PIN_R4,DIO_U8_HIGH);
	
	if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R2C1;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R2C2;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R2C3;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R2C4;
	}
	
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R1,KEYPAD_U8_PIN_R1,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R2,KEYPAD_U8_PIN_R2,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R3,KEYPAD_U8_PIN_R3,DIO_U8_LOW);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R4,KEYPAD_U8_PIN_R4,DIO_U8_HIGH);
	
	if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R3C1;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R3C2;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R3C3;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R3C4;
	}
	

	DIO_voidSetPinVal(KEYPAD_U8_PORT_R1,KEYPAD_U8_PIN_R1,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R2,KEYPAD_U8_PIN_R2,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R3,KEYPAD_U8_PIN_R3,DIO_U8_HIGH);
	DIO_voidSetPinVal(KEYPAD_U8_PORT_R4,KEYPAD_U8_PIN_R4,DIO_U8_LOW);
	
	if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C1,KEYPAD_U8_PIN_C1) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R4C1;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C2,KEYPAD_U8_PIN_C2) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R4C2;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C3,KEYPAD_U8_PIN_C3) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R4C3;
	}
	else if(DIO_u8GetPinVal(KEYPAD_U8_PORT_C4,KEYPAD_U8_PIN_C4) == DIO_U8_LOW)
	{
		Local_u8Button = KEYPAD_U8_R4C4;
	}	
	
	return Local_u8Button;
}