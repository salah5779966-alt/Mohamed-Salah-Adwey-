#include "../MCAL/TIMER0/timer0.h"
#include "../HAL/LED/led.h"

typedef unsigned char u8;
typedef unsigned short u16;

static u16 counter = 0;

void Timer_ISR_Action(void) {
    counter++;
    if (counter == 31) {
        LED_voidToggle(PORT_C, PIN0);
        counter = 0;
        TIMER0_voidSetPreload(6);
    }
}

int main(void) {
    LED_voidInit(PORT_C, PIN0);
    TIMER0_voidSetOVFCallback(Timer_ISR_Action);
    TIMER0_voidSetPreload(6);
    TIMER0_voidInit(TIMER0_NORMAL_MODE);
    sei();

    while (1) {
    }
}