#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "POT_interface.h"

#define POT_CHANNEL     0

#define RED_LED_PORT    DIO_PORTB
#define RED_LED_PIN     DIO_PIN0

#define YELLOW_LED_PORT DIO_PORTB
#define YELLOW_LED_PIN  DIO_PIN1

#define GREEN_LED_PORT  DIO_PORTB
#define GREEN_LED_PIN   DIO_PIN2

int main(void)
{
    u16 local_u16VoltageMV = 0;

    DIO_voidSetPinDirection(RED_LED_PORT, RED_LED_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, DIO_OUTPUT);

    POT_voidInit(POT_CHANNEL);

    while(1)
    {
        local_u16VoltageMV = POT_u16ReadVoltageMilliVolt(POT_CHANNEL);

        if(local_u16VoltageMV > 0 && local_u16VoltageMV < 1500)
        {
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_HIGH);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_LOW);
        }
        else if(local_u16VoltageMV >= 1500 && local_u16VoltageMV < 3000)
        {
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_HIGH);
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_LOW);
        }
        else if(local_u16VoltageMV >= 3000)
        {
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_HIGH);
        }
        else
        {
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_LOW);
        }
    }

    return 0;
}