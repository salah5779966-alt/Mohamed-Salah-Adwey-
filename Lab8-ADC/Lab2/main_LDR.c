#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LDR_interface.h"

#define LDR_CHANNEL     0

#define LED_PORT        DIO_PORTB
#define LED_PIN         DIO_PIN0

#define DARK_THRESHOLD_MV  2500

int main(void)
{
    u16 local_u16VoltageMV = 0;

    DIO_voidSetPinDirection(LED_PORT, LED_PIN, DIO_OUTPUT);

    LDR_voidInit(LDR_CHANNEL);

    while(1)
    {
        local_u16VoltageMV = LDR_u16ReadVoltageMilliVolt(LDR_CHANNEL);

        if(local_u16VoltageMV < DARK_THRESHOLD_MV)
        {
            DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_HIGH);
        }
        else
        {
            DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_LOW);
        }
    }

    return 0;
}