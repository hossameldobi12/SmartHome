/*
 * MOTOR_Interface.c
 *
 * Created: 11/26/2022 4:33:01 PM
 *  Author: User
 */ 

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "Motor_Private.h"
#include "MOTOR_Configuration.h"
#include "STD_types.h"

void Motor_Initialize(void)
{
	DIO_voidSetPinDir(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, H_BRIDGE_STATE);
	DIO_voidSetPinDir(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, H_BRIDGE_STATE);
	DIO_voidSetPinDir(H_BRIDGE_A_PRT, H_BRIDGE_A1, H_BRIDGE_STATE);
	DIO_voidSetPinDir(H_BRIDGE_A_PRT, H_BRIDGE_A2, H_BRIDGE_STATE);
	DIO_voidSetPinDir(H_BRIDGE_A_PRT, H_BRIDGE_B1, H_BRIDGE_STATE);
	DIO_voidSetPinDir(H_BRIDGE_A_PRT, H_BRIDGE_B2, H_BRIDGE_STATE);
}
void Motor_ON(motor_direction direction, motor_enable enable_pin)
{
	if(enable_pin == enable1)
	{
		if(direction == clockwise)
		{
			DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A1, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A2, H_BRIDGE_LOW);
		}
		else if(direction == anticlockwise){
			DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A1, H_BRIDGE_LOW);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A2, H_BRIDGE_HIGH);
		}
	}
	else if(enable_pin == enable2){
		if(direction == clockwise){
			DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B1, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B2, H_BRIDGE_LOW);
		}
		else if(direction == anticlockwise){
			DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, H_BRIDGE_HIGH);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B1, H_BRIDGE_LOW);
			DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B2, H_BRIDGE_HIGH);
		}
	}
}
void Motor_OFF(motor_enable enable_pin){
	if(enable_pin == enable1){
		DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE1, H_BRIDGE_LOW);
		DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A1, H_BRIDGE_LOW);
		DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_A2, H_BRIDGE_LOW);
	}
	else if(enable_pin == enable1){
		DIO_voidSetPinVal(H_BRIDGE_ENABLE_PRT, H_BRIDGE_ENABLE2, H_BRIDGE_LOW);
		DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B1, H_BRIDGE_LOW);
		DIO_voidSetPinVal(H_BRIDGE_A_PRT, H_BRIDGE_B2, H_BRIDGE_LOW);
	}
	
}