/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		App: Smart Home With Voice Control	***********************/
/************************		Created: 31/7/2023					***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "TIMER_interface.h"
#include "TIMER1_interface.h"
#include "USART_interface.h"
#include "GIE_interface.h"
#include "KPD_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>
#include "App_Interface.h"


extern u16 Data;

void main(void){
	GROUP_voidInitDIR();
	LCD_void_Innit_8Bit();

	ADC_voidInnit();
	EXTI_voidInt0Innit();
	USART_voidInit();

	USART_voidSet_RXCallback(GetData);
	EXTI_u8SetCallBack(EXTI_u8INT0,&EXTI0Func);

	LCD_void_WriteString("Welcome...",LCD_BIT_0,LCD_FIRST_LINE);
	_delay_ms(1500);
	Login();

	GIE_voidEnable();

	while(1){

		switch(Data){
		case '1' :
			LightsOn();
			break;
		case '2' :
			LightsOff();
			break;
		case '3' :
			ControlLights();
			break;
		case '4' :
			DoorOpen();
			break;
		case '5' :
			DoorClose();
			break;
		case '6' :
			FanOn();
			break;
		case '7' :
			FanOff();
			break;
		case '8' :
			ControlFan();
			break;
		case 122 :
			EMRGNCYFUNC();
			break;
		default:
			break;
		}
	}
}
