#include "../MCAL/DIO_interface.h"
#include "../HAL/Keypad_interface.h"
#include "../HAL/SevenSegment_interface.h"

int main(void)
{
    unsigned char Local_u8Key = KPD_NOT_PRESSED;

    SevenSegment_voidInit();
    Keypad_voidInit();

    while (1)
    {
        Local_u8Key = Keypad_u8GetPressedKey();

        if (Local_u8Key != KPD_NOT_PRESSED)
        {
            if (Local_u8Key >= '1' && Local_u8Key <= '9')
            {
                SevenSegment_voidDisplayNumber(Local_u8Key - '0');
            }
        }
    }

    return 0;
}
