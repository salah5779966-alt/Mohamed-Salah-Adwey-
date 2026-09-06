#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_LOW);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_LOW);
    
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);
    
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Data)
{
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_LOW);
    
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Data);
    
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_voidInit(void)
{
    DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);

    _delay_ms(30);
    LCD_voidSendCommand(0x38); // 8-bit mode, 2 lines, 5x7 font
    LCD_voidSendCommand(0x0C); // Display ON, Cursor OFF
    LCD_voidSendCommand(0x01); // Clear Display
    _delay_ms(2);
}

void LCD_voidSendString(const u8 *Copy_pu8String)
{
    u8 Local_u8Index = 0;
    while (Copy_pu8String[Local_u8Index] != '\0')
    {
        LCD_voidSendChar(Copy_pu8String[Local_u8Index]);
        Local_u8Index++;
    }
}