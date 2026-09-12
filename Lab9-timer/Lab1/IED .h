#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

typedef unsigned char u8;

void LED_voidInit(u8 port, u8 pin);
void LED_voidToggle(u8 port, u8 pin);

#endif