#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "VOLTMETER_interface.h"

#define VOLTMETER_CHANNEL   0

int main(void)
{
    u16 local_u16VoltageMV = 0;

    LCD_voidInit();
    VOLTMETER_voidInit(VOLTMETER_CHANNEL);

    LCD_voidSendString((u8*)"Voltage:");

    while(1)
    {
        local_u16VoltageMV = VOLTMETER_u16ReadVoltageMilliVolt(VOLTMETER_CHANNEL);

        LCD_voidSetCursor(0, 9);
        LCD_voidWriteNumber(local_u16VoltageMV);
        LCD_voidSendString((u8*)" mV  ");

        _delay_ms(1000);
    }

    return 0;
}s