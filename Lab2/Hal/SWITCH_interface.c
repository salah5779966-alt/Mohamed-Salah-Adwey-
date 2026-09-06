#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SWITCH_interface.h"

void SWITCH_voidInit(u8 Copy_u8Port, u8 Copy_u8Pin) {
    DIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_PIN_INPUT);
    DIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_HIGH);
}

u8 SWITCH_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin) {
    return DIO_u8GetPinValue(Copy_u8Port, Copy_u8Pin);
}