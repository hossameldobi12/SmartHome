/*
 * MOTOR_Configuration.h
 *
 * Created: 11/26/2022 4:00:56 PM
 *  Author: User
 */ 


#ifndef MOTOR_CONFIGURATION_H_
#define MOTOR_CONFIGURATION_H_



#define H_BRIDGE_ENABLE_PRT   DIO_U8_PORTB
#define H_BRIDGE_ENABLE1      DIO_U8_PIN0
#define H_BRIDGE_ENABLE2      DIO_U8_PIN7

#define H_BRIDGE_A_PRT        DIO_U8_PORTC
#define H_BRIDGE_B_PRT        DIO_U8_PORTA

#define H_BRIDGE_A1		      DIO_U8_PIN4
#define H_BRIDGE_A2		      DIO_U8_PIN5
#define H_BRIDGE_B1	          DIO_U8_PIN1
#define H_BRIDGE_B2           DIO_U8_PIN3
#define H_BRIDGE_STATE        DIO_U8_OUTPUT

#define H_BRIDGE_HIGH         DIO_U8_HIGH
#define H_BRIDGE_LOW          DIO_U8_LOW

typedef enum{
	clockwise,
	anticlockwise
}motor_direction;

typedef enum{
	enable1,
	enable2
}motor_enable;





#endif /* MOTOR_CONFIGURATION_H_ */