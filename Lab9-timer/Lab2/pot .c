#include "pot.h"

void POT_voidInit(void) {
    ADC_voidInit();
}

u16 POT_u16Read(u8 channel) {
    return ADC_u16Read(channel);
}