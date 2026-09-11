#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KPD_NOT_PRESSED 0xFF

void Keypad_voidInit(void);
u8 Keypad_u8GetPressedKey(void);

#endif