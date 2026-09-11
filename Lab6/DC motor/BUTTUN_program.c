#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DC_MOTOR_interface.h"

void DC_MOTOR_voidInit(u8 copy_u8Port, u8 copy_u8Pin)
{
    DIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, PIN_OUTPUT);
}

void DC_MOTOR_voidStart(u8 copy_u8Port, u8 copy_u8Pin)
{
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin, PIN_HIGH);
}

void DC_MOTOR_voidStop(u8 copy_u8Port, u8 copy_u8Pin)
{
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin, PIN_LOW);
}