#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "LM35_interface.h"

void LM35_voidInit(u8 Copy_u8ADCChannel)
{
    ADC_voidInit();
}

u16 LM35_u16GetTemperature(u8 Copy_u8ADCChannel)
{
    u16 local_u16AdcValue = 0;
    u32 local_u32MilliVolts = 0;
    u16 local_u16Temp = 0;

    local_u16AdcValue = ADC_u16ReadChannel(Copy_u8ADCChannel);
    local_u32MilliVolts = ((u32)local_u16AdcValue * 5000UL) / 1024UL;
    local_u16Temp = (u16)(local_u32MilliVolts / 10UL);

    return local_u16Temp;
}