#ifndef H_BRIDGE_INTERFACE_H
#define H_BRIDGE_INTERFACE_H

#include "STD_TYPES.h"

void H_BRIDGE_voidInit(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2);
void H_BRIDGE_voidRotateCW(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2);
void H_BRIDGE_voidRotateCCW(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2);
void H_BRIDGE_voidStop(u8 copy_u8Port, u8 copy_u8Pin1, u8 copy_u8Pin2);

#endif