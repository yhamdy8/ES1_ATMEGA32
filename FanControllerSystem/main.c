/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		APP: Fan Control Based on Temp Sensor***********************/
/************************		Date: 3/7/2023						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "PORT_interface.h"
#include "LCD_interface.h"


void MOTOR_OFF(void);


u8 MOTOR_FLAG=0xff;

void main(void){
	GROUP_voidInitDIR();
	LCD_void_Innit_8Bit();
	ADC_voidInnit();
	TIMER_COUNTER_0_voidInit();

	u16 DigitalReading=0;
	u8 Temp=0;
	u32 Analog=0;
	u16 PrevTemp=1;

	while(1)
	{

		ADC_u8StartConversion_Synch(ADC_SINGLE_ENDED_IP_ADC0,&DigitalReading);
		Analog=((u32)DigitalReading*5000UL); // Analog = Digital * Step= Digital * (ref volt/resolution) = digital*ref volt
		Analog/=1024UL;	// analog /=resolution;
		Temp=Analog/10;	// since, 10mV = 1C. so cross multiplication
		if( !(PrevTemp == Temp) )	//Checking if the same value is found so it wont enter
		{
			if( (Temp >= 30) && (Temp < 60) && (MOTOR_FLAG !=1) ) // first case Working with 25%
			{
				TIMER0_voidSetCompareMatchValue(64);
				MOTOR_FLAG=1;
				LCD_void_WriteString("Motor Power=25%_",LCD_BIT_0,LCD_SECOND_LINE);
			}else
				if( (Temp >= 60) && (Temp < 90) && (MOTOR_FLAG !=2) ) // Second case Working with 50%
				{
					TIMER0_voidSetCompareMatchValue(128);
					MOTOR_FLAG=2;
					LCD_void_WriteString("Motor Power=50%_",LCD_BIT_0,LCD_SECOND_LINE);
				}else
					if( (Temp >= 90) && (Temp < 120) && (MOTOR_FLAG !=3) ) // Third case Working with 75%
					{
						TIMER0_voidSetCompareMatchValue(192);
						MOTOR_FLAG=3;
						LCD_void_WriteString("Motor Power=75%_",LCD_BIT_0,LCD_SECOND_LINE);
					}else
						if( (Temp >= 120) && (MOTOR_FLAG !=4) ) // Final case Working with 100%
						{
							TIMER0_voidSetCompareMatchValue(255);
							MOTOR_FLAG=1;
							LCD_void_WriteString("Motor Power=100%",LCD_BIT_0,LCD_SECOND_LINE);
						}else
							if( (Temp < 30) && (MOTOR_FLAG !=0) ) // case no need for Fan
							{
								MOTOR_FLAG=0;
								MOTOR_OFF();
								LCD_void_WriteString("___Motor OFF___!",LCD_BIT_0,LCD_SECOND_LINE);
							}
			/* Writing the Current Temp on LCD*/
			// Temp
			LCD_void_WriteString("________________", LCD_BIT_0, LCD_FIRST_LINE );
			LCD_void_WriteString("Temp = ", LCD_BIT_0, LCD_FIRST_LINE );
			LCD_void_WriteNumber(Temp);
			PrevTemp = Temp;	// assign current value to prev value to assure that it re-enter on new values only
		}
	}
}

void MOTOR_OFF(void)
{
	DIO_u8_Set_Pin_Value(DIO_u8_GROUP_B,DIO_u8_PIN_3, DIO_u8_PIN_LOW);
}
