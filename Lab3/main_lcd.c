#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

int main(void)
{
    LCD_voidInit();

    LCD_voidSendString((u8*)"Mohamed Salah");

    while (1)
    {
    }
    
    return 0;
}