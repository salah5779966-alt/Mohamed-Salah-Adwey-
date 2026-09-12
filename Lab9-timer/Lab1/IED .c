#include "led.h"

void LED_voidInit(u8 port, u8 pin) {
    DIO_voidSetPinDirection(port, pin, OUTPUT);
}

void LED_voidToggle(u8 port, u8 pin) {
    DIO_voidTogglePin(port, pin);
}