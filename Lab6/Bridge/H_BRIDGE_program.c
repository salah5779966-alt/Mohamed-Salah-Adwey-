#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "H_BRIDGE_interface.h"

void H_BRIDGE_voidInit(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2)
{
    DIO_voidSetPinDirection(copy_u8Port, copy_u8Pin1, PIN_OUTPUT);
    DIO_voidSetPinDirection(copy_u8Port, copy_u8Pin2, PIN_OUTPUT);
}

void H_BRIDGE_voidRotateCW(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2)
{
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin1, PIN_HIGH);
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin2, PIN_LOW);
}

void H_BRIDGE_voidRotateCCW(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2)
{
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin1, PIN_LOW);
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin2, PIN_HIGH);
}

void H_BRIDGE_voidStop(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2)
{
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin1, PIN_LOW);
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin2, PIN_LOW);
}