#include <util/delay.h>
#include "..STD_TYPES.h"
#include "..DIO/DIO_interface.h"
#include "..EXTI/EXTI_interface.h"
#include "..GIE/GIE_interface.h"
#include "..SWITCH/SWITCH_interface.h"

volatile u8 global_u8AnimationMode = 0;

SWITCH_t Btn0 = {DIO_PORTD, DIO_PIN2};

void INT0_ISR(void)
{
    global_u8AnimationMode++;
    if (global_u8AnimationMode > 1)
    {
        global_u8AnimationMode = 0;
    }
}

int main(void)
{
    DIO_voidSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);
    SWITCH_voidInit(&Btn0);

    EXTI_voidSetCallBack(EXTI_INT0, &INT0_ISR);
    EXTI_voidInit(EXTI_INT0, EXTI_FALLING_EDGE);
    EXTI_voidEnableInterrupt(EXTI_INT0);

    GIE_voidEnable();

    while (1)
    {
        if (global_u8AnimationMode == 0)
        {
            for (u8 i = 0; i < 8; i++)
            {
                DIO_voidSetPortValue(DIO_PORTA, (1 << i));
                _delay_ms(200);
            }
        }
        else if (global_u8AnimationMode == 1)
        {
            DIO_voidSetPortValue(DIO_PORTA, 0xFF);
            _delay_ms(300);
            DIO_voidSetPortValue(DIO_PORTA, 0x00);
            _delay_ms(300);
        }
    }

    return 0;
}
