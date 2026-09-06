#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(u8 Copy_u8Port, u8 Copy_u8Pin) {
    DIO_voidSetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_PIN_OUTPUT);
}

void LED_voidOn(u8 Copy_u8Port, u8 Copy_u8Pin) {
    DIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_HIGH);
}

void LED_voidOff(u8 Copy_u8Port, u8 Copy_u8Pin) {
    DIO_voidSetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_LOW);
}