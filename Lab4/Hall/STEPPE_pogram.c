#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include <util/delay.h>

void STEPPER_voidInit(void) {
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_BLUE_PIN, OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_PINK_PIN, OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_YELLOW_PIN, OUTPUT);
    DIO_voidSetPinDirection(STEPPER_PORT, STEPPER_ORANGE_PIN, OUTPUT);
}

void STEPPER_voidRotateCW(u16 Copy_u16Angle) {
    u16 Local_u16Iterations = (u16)(((u32)Copy_u16Angle * 2048) / 360) / 4;
    
    for (u16 i = 0; i < Local_u16Iterations; i++) {
        // Step 1
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, LOW);
        _delay_ms(10);

        // Step 2
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, LOW);
        _delay_ms(10);

        // Step 3
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, HIGH);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, LOW);
        _delay_ms(10);

        // Step 4
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, LOW);
        DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, HIGH);
        _delay_ms(10);
    }
}