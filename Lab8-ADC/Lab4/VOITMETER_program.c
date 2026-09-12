#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "VOLTMETER_interface.h"

void VOLTMETER_voidInit(u8 Copy_u8ADCChannel)
{
    ADC_voidInit();
}

u16 VOLTMETER_u16ReadVoltageMilliVolt(u8 Copy_u8ADCChannel)
{
    u16 local_u16AdcValue = 0;
    u32 local_u32MilliVolts = 0;

    local_u16AdcValue = ADC_u16ReadChannel(Copy_u8ADCChannel);
    local_u32MilliVolts = ((u32)local_u16AdcValue * 5000UL) / 1024UL;

    return (u16)local_u32MilliVolts;
}