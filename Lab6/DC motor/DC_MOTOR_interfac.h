#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "STD_TYPES.h"

void BUTTON_voidInit(u8 copy_u8Port, u8 copy_u8Pin);
u8 BUTTON_u8Read(u8 copy_u8Port, u8 copy_u8Pin);

#endif