#define F_CPU 16000000UL
#include <util/delay.h>
#include "../STD_TYPES.h"
#include "../MCAL/DIO_interface.h"
#include "Keypad_interface.h"

#define KPD_PORT PORTC

static const u8 KPD_u8Buttons[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};

void Keypad_voidInit(void)
{
    DIO_voidSetPinDirection(KPD_PORT, PIN0, OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN1, OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN2, OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN3, OUTPUT);

    DIO_voidSetPinDirection(KPD_PORT, PIN4, INPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN5, INPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN6, INPUT);
    DIO_voidSetPinDirection(KPD_PORT, PIN7, INPUT);

    DIO_voidSetPortValue(KPD_PORT, 0xFF);
}

u8 Keypad_u8GetPressedKey(void)
{
    u8 Local_u8PressedKey = KPD_NOT_PRESSED;
    u8 Local_u8Col, Local_u8Row;

    for (Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
    {
        DIO_voidSetPinValue(KPD_PORT, Local_u8Col, LOW);

        for (Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
        {
            if (DIO_u8GetPinValue(KPD_PORT, Local_u8Row + 4) == LOW)
            {
                Local_u8PressedKey = KPD_u8Buttons[Local_u8Row][Local_u8Col];
                while (DIO_u8GetPinValue(KPD_PORT, Local_u8Row + 4) == LOW);
                _delay_ms(20);
            }
        }

        DIO_voidSetPinValue(KPD_PORT, Local_u8Col, HIGH);
    }

    return Local_u8PressedKey;
}