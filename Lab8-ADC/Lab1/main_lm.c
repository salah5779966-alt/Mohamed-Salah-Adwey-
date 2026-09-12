#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"

#define LM35_CHANNEL    0

#define GREEN_LED_PORT  DIO_PORTB
#define GREEN_LED_PIN   DIO_PIN0

#define YELLOW_LED_PORT DIO_PORTB
#define YELLOW_LED_PIN  DIO_PIN1

#define RED_LED_PORT    DIO_PORTB
#define RED_LED_PIN     DIO_PIN2

#define BUZZER_PORT     DIO_PORTB
#define BUZZER_PIN      DIO_PIN3

int main(void)
{
    u16 local_u16Temp = 0;

    DIO_voidSetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(RED_LED_PORT, RED_LED_PIN, DIO_OUTPUT);
    DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);

    LM35_voidInit(LM35_CHANNEL);

    while(1)
    {
        local_u16Temp = LM35_u16GetTemperature(LM35_CHANNEL);

        if(local_u16Temp < 20)
        {
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_HIGH);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
        }
        else if(local_u16Temp >= 20 && local_u16Temp <= 40)
        {
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_HIGH);
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
        }
        else
        {
            DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, DIO_LOW);
            DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_HIGH);
            DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
        }
    }

    return 0;
}