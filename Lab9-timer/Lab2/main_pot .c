#include "../MCAL/TIMER0/timer0.h"
#include "../HAL/LED/led.h"
#include "../HAL/POT/pot.h"

typedef unsigned char u8;
typedef unsigned short u16;

void CTC_ISR_Action(void) {
    LED_voidToggle(PORT_C, PIN0);
}

int main(void) {
    LED_voidInit(PORT_C, PIN0);
    POT_voidInit();
    
    TIMER0_voidSetCTCCallback(CTC_ISR_Action);
    TIMER0_voidInit(TIMER0_CTC_MODE);
    sei();

    while (1) {
        u16 adc_val = POT_u16Read(0);
        u8 ocr_val = (u8)(adc_val >> 2);
        TIMER0_voidSetCompareValue(ocr_val);
    }
}