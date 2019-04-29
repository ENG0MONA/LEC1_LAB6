#include"../MCAL/DIO/DIO.h"
#include<avr/delay.h>

void main()
{
	//SET PIN AS INPUT FOR DIP SWITCH
	DIO_voidSetPinDirection(PORTA_ID,PIN0_ID,INPUT);

	//PULL UP THE DIP SWITCH PIN
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,HIGH);

	//SET PORT AS OUTPUT FOR LEDS
	DIO_voidSetPortDirection(PORTC_ID,0XFF);

	while(1){

	if(DIO_VALUE_TYPEGetPinValue(PORTA_ID,PIN0_ID)==LOW)
	{
		//SWICH PRESSED/ON
		//FLASH LED
		DIO_voidSetPortValue(PORTC_ID,0XFF);
		_delay_ms(500);
		DIO_voidSetPortValue(PORTC_ID,0X00);
		_delay_ms(500);
	}
	else
	{
		DIO_voidSetPortValue(PORTC_ID,0X00);
	}
}
}
