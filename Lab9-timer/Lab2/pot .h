#ifndef POT_H_
#define POT_H_

#include "../../MCAL/ADC/adc.h"

typedef unsigned char u8;
typedef unsigned short u16;

void POT_voidInit(void);
u16 POT_u16Read(u8 channel);

#endif