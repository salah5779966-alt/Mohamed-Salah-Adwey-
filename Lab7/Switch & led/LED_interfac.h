#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

typedef struct
{
    u8 Port;
    u8 Pin;
} LED_t;

void LED_voidInit(LED_t* copy_pxLed);
void LED_voidTurnOn(LED_t* copy_pxLed);
void LED_voidTurnOff(LED_t* copy_pxLed);
void LED_voidToggle(LED_t* copy_pxLed);

#endif