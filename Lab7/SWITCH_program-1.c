#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_interface.h"

void SWITCH_voidInit(SWITCH_t* copy_pxSwitch)
{
    DIO_voidSetPinDirection(copy_pxSwitch->Port, copy_pxSwitch->Pin, DIO_PIN_INPUT);
    DIO_voidSetPinValue(copy_pxSwitch->Port, copy_pxSwitch->Pin, DIO_PIN_HIGH);
}