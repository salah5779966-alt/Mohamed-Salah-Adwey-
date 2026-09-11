#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BUTTON_interface.h"

void BUTTON_voidInit(u8 copy_u8Port, u8 copy_u8Pin)
{
    DIO_voidSetPinDirection(copy_u8Port, copy_u8Pin, PIN_INPUT);
    DIO_voidSetPinValue(copy_u8Port, copy_u8Pin, PIN_HIGH);
}

u8 BUTTON_u8Read(u8 copy_u8Port, u8 copy_u8Pin)
{
    return DIO_u8GetPinValue(copy_u8Port, copy_u8Pin);
}