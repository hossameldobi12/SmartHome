/*
 * MOTOR_Private.h
 *
 * Created: 11/26/2022 4:00:25 PM
 *  Author: User
 */ 


#ifndef MOTOR_PRIVATE_H_
#define MOTOR_PRIVATE_H_


#include "Motor_Configuration.h"

void Motor_Initialize(void);
void Motor_ON(motor_direction direction, motor_enable enable_pin);
void Motor_OFF(motor_enable enable_pin);



#endif /* MOTOR_PRIVATE_H_ */