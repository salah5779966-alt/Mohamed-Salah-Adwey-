#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BUTTON_interface.h"
#include "DC_MOTOR_interface.h"

void main(void)
{
    u8 local_u8ButtonState = 1;

    BUTTON_voidInit(PORT_A, PIN0);
    DC_MOTOR_voidInit(PORT_B, PIN0);

    while (1)
    {
        local_u8ButtonState = BUTTON_u8Read(PORT_A, PIN0);

        if (local_u8ButtonState == 1)
        {
            DC_MOTOR_voidStart(PORT_B, PIN0);
        }
        else
        {
            DC_MOTOR_voidStop(PORT_B, PIN0);
        }
    }
}