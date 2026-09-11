#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BUTTON_interface.h"
#include "H_BRIDGE_interface.h"

void main(void)
{
    u8 local_u8ButtonState = 1;
    u8 local_u8DirectionState = 0;
    u8 local_u8PreviousState = 1;

    BUTTON_voidInit(PORT_A, PIN0);
    H_BRIDGE_voidInit(PORT_B, PIN0, PIN1);

    while (1)
    {
        local_u8ButtonState = BUTTON_u8Read(PORT_A, PIN0);

        if (local_u8ButtonState == 0 && local_u8PreviousState == 1)
        {
            local_u8DirectionState ^= 1;
        }

        local_u8PreviousState = local_u8ButtonState;

        if (local_u8DirectionState == 0)
        {
            H_BRIDGE_voidRotateCW(PORT_B, PIN0, PIN1);
        }
        else
        {
            H_BRIDGE_voidRotateCCW(PORT_B, PIN0, PIN1);
        }
    }
}