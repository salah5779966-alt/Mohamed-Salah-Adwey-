#ifndef VOLTMETER_INTERFACE_H_
#define VOLTMETER_INTERFACE_H_

void VOLTMETER_voidInit(u8 Copy_u8ADCChannel);
u16 VOLTMETER_u16ReadVoltageMilliVolt(u8 Copy_u8ADCChannel);

#endif