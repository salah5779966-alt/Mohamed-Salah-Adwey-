#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendString(const char *Copy_charString);
void LCD_voidSendNumber(int Copy_s32Number);
void LCD_voidClear(void);

#endif