#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#include "STD_TYPES.h"

void DC_MOTOR_voidInit(u8 copy_u8Port, u8 copy_u8Pin);
void DC_MOTOR_voidStart(u8 copy_u8Port, u8 copy_u8Pin);
void DC_MOTOR_voidStop(u8 copy_u8Port, u8 copy_u8Pin);

#endif