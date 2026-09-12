#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

void LM35_voidInit(u8 Copy_u8ADCChannel);
u16 LM35_u16GetTemperature(u8 Copy_u8ADCChannel);

#endif