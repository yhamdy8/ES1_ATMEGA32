/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		APP:  STOP-WATCH					***********************/
/************************		DATE: 16/7/2023						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
//#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "TIMER1_interface.h"

#define _1SECOND	20	// Required No of times ISR is executed to increment 1 second in real time
#define DELAY_TIME 10 	// to use the persistence of vision concept


void ISRofCompMatch(void);
void RESET(void);
void PAUSE(void);
void RESUME(void);


u8 Glob_Counter1SecIncr=0;
u8 PauseFlag=0;

u8 S0=0;
u8 M0=0;
u8 H0=0;

/*
  Another Sol.
u8 M1=0;
u8 S1=0;
u8 H1=0;
*/


void main(void){
	GROUP_voidInitDIR();	// initialise pins
	EXTI_voidInt0Innit();	// initialise external interrupt 0
	EXTI_voidInt2Innit();   // initialise external interrupt 2
	EXTI_voidInt1Innit();   // initialise external interrupt 1
	GIE_voidEnable();		// initialise Global interrupt
	TIMER1_voidSTOPWATCHFUNC(&ISRofCompMatch); // Set Callback function & initialise timer1
	EXTI_u8SetCallBack(EXTI_u8INT2,&RESET);	   // Set Callback function for External interrupt 2
	EXTI_u8SetCallBack(EXTI_u8INT0,&PAUSE);    // Set Callback function for External interrupt 0
	EXTI_u8SetCallBack(EXTI_u8INT1,&RESUME);   // Set Callback function for External interrupt 1
	while(1){
		/*
		 Another Sol.

		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00100000);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,H1);
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00010000);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,H0);
		_delay_ms(DELAY_TIME);

		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00001000);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,M1);
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000100);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,M0);
		_delay_ms(DELAY_TIME);

		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000010);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,S1);
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000001);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,S0);
		_delay_ms(DELAY_TIME);*/
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00100000);	// Activate Bit 5 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,(H0/10) );		// Write bit 1 of the hours variable
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00010000);  // Activate Bit 4 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,(H0%10) );     // Write bit 0 of the hours variable
		_delay_ms(DELAY_TIME);

		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00001000);  // Activate Bit 3 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,(M0/10));      // Write bit 1 of the Minutes variable
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000100);  // Activate Bit 2 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C,(M0%10));      // Write bit 0 of the Minutes variable
		_delay_ms(DELAY_TIME);

		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000010);  // Activate Bit 1 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C, (S0/10) );    // Write bit 1 of the Seconds variable
		_delay_ms(DELAY_TIME);
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_A, 0b00000001);  // Activate Bit 0 of the SSG,, others bits OFF
		DIO_u8_Set_Port_Value(DIO_u8_GROUP_C, (S0%10) );    // Write bit 0 of the Seconds variable
		_delay_ms(DELAY_TIME);
	}
}


void ISRofCompMatch(void){
	if(PauseFlag == 0)		// Flag to check if System is Paused or not
	{
		Glob_Counter1SecIncr++;
	}
	if(Glob_Counter1SecIncr == _1SECOND){
		/*
		  Another Sol.
		   if ( S0 < 9 ){
			S0++;
		}
		else if( S1 < 5 ){
			S0=0;
			S1++;
		}else if(M0 < 9){
			S0=0;
			S1=0;
			M0++;
		}else if(M1 < 5){
			S0=0;
			S1=0;
			M0=0;
			M1++;
		}else if( H1 < 2){
			if( H0 < 9)
			{
				S0=0;
				S1=0;
				M0=0;
				M1=0;
				H0++;
			}else{
				S0=0;
				S1=0;
				M0=0;
				M1=0;
				H0=0;
				H1++;
			}
		}
		else if( H1 ==2 )
		{
			S0=0;
			S1=0;
			M0=0;
			M1=0;
			H0++;
		}
		if( H0 == 4)
		{
			S0=0;
			S1=0;
			M0=0;
			M1=0;
			H0=0;
			H1=0;
		}*/
		if (S0 <59){
			S0++;
		}else if(M0 < 59){
			S0=0;
			M0++;
		}else if(H0 < 24){
			S0=0;
			M0=0;
			H0++;
		}else {
			S0=0;
			M0=0;
			H0=0;
		}
		Glob_Counter1SecIncr = 0;
	}
}

void RESET(void){
	Glob_Counter1SecIncr=0;
	PauseFlag=0;
	S0=0;
	M0=0;
	H0=0;
/*
  Another Sol.
	S1=0;
	M1=0;
	H1=0;
	*/
}

void PAUSE(void){
	PauseFlag=1;
	/*
	  Another Sol.
	 Timer1_voidPauseStop();
	 */
}

void RESUME(void){
	PauseFlag=0;
	/*
	   Another Sol.
	 TIMER1_voidRESUME();
	 */
}
