#include "../MCAL/DIO_interface.h"
#include "../HAL/LCD_interface.h"
#include "../HAL/Keypad_interface.h"

int main(void)
{
    unsigned char Local_u8Key = KPD_NOT_PRESSED;
    int Local_s32Num1 = 0;
    int Local_s32Num2 = 0;
    unsigned char Local_u8Op = 0;
    unsigned char Local_u8State = 0;

    LCD_voidInit();
    Keypad_voidInit();

    while (1)
    {
        Local_u8Key = Keypad_u8GetPressedKey();

        if (Local_u8Key != KPD_NOT_PRESSED)
        {
            if (Local_u8Key == 'C')
            {
                LCD_voidClear();
                Local_s32Num1 = 0;
                Local_s32Num2 = 0;
                Local_u8Op = 0;
                Local_u8State = 0;
            }
            else if (Local_u8State == 0)
            {
                if (Local_u8Key >= '0' && Local_u8Key <= '9')
                {
                    Local_s32Num1 = (Local_s32Num1 * 10) + (Local_u8Key - '0');
                    LCD_voidSendData(Local_u8Key);
                }
                else if (Local_u8Key == '+' || Local_u8Key == '-' || Local_u8Key == '*' || Local_u8Key == '/')
                {
                    Local_u8Op = Local_u8Key;
                    LCD_voidSendData(Local_u8Key);
                    Local_u8State = 1;
                }
            }
            else if (Local_u8State == 1)
            {
                if (Local_u8Key >= '0' && Local_u8Key <= '9')
                {
                    Local_s32Num2 = (Local_s32Num2 * 10) + (Local_u8Key - '0');
                    LCD_voidSendData(Local_u8Key);
                }
                else if (Local_u8Key == '=')
                {
                    LCD_voidSendData('=');
                    int Local_s32Result = 0;

                    switch (Local_u8Op)
                    {
                        case '+': Local_s32Result = Local_s32Num1 + Local_s32Num2; break;
                        case '-': Local_s32Result = Local_s32Num1 - Local_s32Num2; break;
                        case '*': Local_s32Result = Local_s32Num1 * Local_s32Num2; break;
                        case '/': 
                            if (Local_s32Num2 != 0)
                            {
                                Local_s32Result = Local_s32Num1 / Local_s32Num2;
                            }
                            break;
                    }

                    if (Local_u8Op == '/' && Local_s32Num2 == 0)
                    {
                        LCD_voidClear();
                        LCD_voidSendString("Error");
                    }
                    else
                    {
                        LCD_voidSendNumber(Local_s32Result);
                    }

                    Local_u8State = 2;
                }
            }
        }
    }

    return 0;
}