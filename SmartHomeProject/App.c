/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR:  Youssef Hamdy			   	***********************/
/************************		file:	 Functions Implementations	***********************/
/************************		APP: 	 Smart Home					***********************/
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

u16 Data=0;
u8 DC_Flag=0;

void Login(void){
	u16 ID=0;                                                                   //Variable used to save id
	u16 Pass=0;                                                                 //Variable used to save password
	u8 LeftTrails=3;                                                            //Variable used to save left trails
	u8 Errflag=0;                                                               //Flag Raised if error is found
	while(LeftTrails>0)															//Checking on the ID
	{
		LCD_void_ClearScreen();
		if(LeftTrails<3)														//Checking on number of trails left for the user
		{
			LCD_void_WriteString("Left Trials:",LCD_BIT_0,LCD_SECOND_LINE);
			LCD_void_WriteNumber(LeftTrails);
		}
		LCD_void_WriteString("Enter ID:",LCD_BIT_0,LCD_FIRST_LINE);
		ID=GetID();																//Get ID and Save it to switch on it
		switch(ID)
		{
		default :																//Case no ID is found in the Data Base
			LCD_void_ClearScreen();
			LCD_void_WriteString("ID NOT FOUND!",LCD_BIT_0,LCD_FIRST_LINE);
			_delay_ms(1000);
			LCD_void_ClearScreen();
			Errflag=1;
			LeftTrails--;
			if(LeftTrails==0) break;
			LCD_void_WriteString("Try Again",LCD_BIT_0,LCD_FIRST_LINE);
			_delay_ms(1000);
			break;
		case USER1ID :															// User 1
			LCD_void_ClearScreen();
			LCD_void_WriteString("Enter PASS:",LCD_BIT_0,LCD_FIRST_LINE);
			Errflag=0;
			break;
		case USER2ID :															// User 2
			LCD_void_ClearScreen();
			LCD_void_WriteString("Enter PASS:",LCD_BIT_0,LCD_FIRST_LINE);
			Errflag=0;
			break;
		case USER3ID :															// User 3
			LCD_void_ClearScreen();
			LCD_void_WriteString("Enter PASS:",LCD_BIT_0,LCD_FIRST_LINE);
			Errflag=0;
			break;
		}
		if(Errflag==0)	break;													// No Error Found,User ID is correct so break the while loop
	}
	if((Errflag==1) && (LeftTrails==0))											//exceeded the trials limit,, System Will Pause till reset
	{
		LCD_void_ClearScreen();
		LCD_void_WriteString("Contact Management!",LCD_BIT_0,LCD_FIRST_LINE);
		while(1){

		}
	}
	LeftTrails=3;																//Reset the variable to check on password giving 3 trials
	while(LeftTrails > 0)														//Checking on the Password
	{
		if(LeftTrails < 3)														//Checking on number of trails left for the user
		{
			LCD_void_ClearScreen();
			LCD_void_WriteString("Left Trials:",LCD_BIT_0,LCD_SECOND_LINE);
			LCD_void_WriteNumber(LeftTrails);
		}
		LCD_void_WriteString("Enter PASS:",LCD_BIT_0,LCD_FIRST_LINE);
		Pass=GetID();															//Get ID and Save it to switch on it
		switch(ID){
		case USER1ID :															//For user 1
			if(Pass == USER1PASS)												//Pass is Correct
			{
				LCD_void_ClearScreen();
				LCD_void_WriteString("Welcome Youssef!",LCD_BIT_0,LCD_FIRST_LINE);
				Errflag=0;														// Reset Err Flag
			}else																// Password is not Correct
			{
				LeftTrails--;													// Trials--
				Errflag=1;													    // Raise Err Flag
				LCD_void_ClearScreen();
				LCD_void_WriteString("Wrong PASS",LCD_BIT_0,LCD_FIRST_LINE);
				_delay_ms(500);
			}
			break;
		case USER2ID :															// For user 2
			if(Pass == USER2PASS)
			{
				LCD_void_ClearScreen();
				LCD_void_WriteString("Welcome Aya!",LCD_BIT_0,LCD_FIRST_LINE);
				Errflag=0;
			}else
			{
				LeftTrails--;
				Errflag=1;
				LCD_void_ClearScreen();
				LCD_void_WriteString("Wrong PASS",LCD_BIT_0,LCD_FIRST_LINE);
				_delay_ms(500);
			}
			break;
		case USER3ID :															// For user 3
			if(Pass == USER3PASS)
			{
				LCD_void_ClearScreen();
				LCD_void_WriteString("Welcome Geogre!",LCD_BIT_0,LCD_FIRST_LINE);
				Errflag=0;
			}else
			{
				LeftTrails--;
				Errflag=1;
				LCD_void_ClearScreen();
				LCD_void_WriteString("Wrong PASS",LCD_BIT_0,LCD_FIRST_LINE);
				_delay_ms(500);
			}
			break;
		}
		if(Errflag==0) break;	 										    	// No Error Found,Password is correct so break the while loop
	}

	if((Errflag==1) && (LeftTrails==0))											//exceeded the trials limit,, System Will Pause till reset
	{
		LCD_void_ClearScreen();
		LCD_void_WriteString("Contact Management!",LCD_BIT_0,LCD_FIRST_LINE);
		while(1){

		}
	}
}

u16 GetID(void)
{
	u16	LocID=0;
	u8 LocPressedKey= KPD_NO_PRESSED_KEY;
	while(1)
	{
		LocPressedKey=KPD_u8GetPressedKey();									// Polling till a key is pressed
		if( (LocPressedKey >=0) && (LocPressedKey <=9) )						//Number is pressed
		{
			LocID*=10;															// Add digit to Variable to fetch new Number
			LocID+=LocPressedKey;												// Add the new number to the variable
			LCD_void_WriteNumber(LocPressedKey);								// Show the Variable on the LCD
		}
		else if( LocPressedKey =='C')											//Clear last digit
		{
			LocID/=10;															// Delete Last Digit from the Variable
			LCD_void_ClearScreen();												// Clear the Prev number
			LCD_void_WriteNumber(LocID);										// Show the new Number(Variable) on the LCD
		}
		else if( LocPressedKey =='K')											// Enter
		{
			break;																// Break the while(1) Loop
		}
		else if(LocPressedKey == 'R')											//Restart
		{
			LocID=0;															// Reset the Variable to zero
		}
	}
	return LocID;																// Return the Variable (ID/PASS)
}

void GetData(void){
	Data=USART_voidReadDataRegister();
}

void LightsOn(void){
	if(Data=='1')																	//Check function is called from main
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);

	DIO_u8_Set_Pin_Value(LED_PIN1_PORT,LED_PIN1_PIN,DIO_u8_PIN_HIGH);
	DIO_u8_Set_Pin_Value(LED_PIN2_PORT,LED_PIN2_PIN,DIO_u8_PIN_HIGH);
	DIO_u8_Set_Pin_Value(LED_PIN3_PORT,LED_PIN3_PIN,DIO_u8_PIN_HIGH);
	DIO_u8_Set_Pin_Value(LED_PIN4_PORT,LED_PIN4_PIN,DIO_u8_PIN_HIGH);


	if(Data=='1')																	//Check function is called from main
	{
		LCD_void_WriteString("____LIGHTS ON___",LCD_BIT_0,LCD_SECOND_LINE);
		Data=0;																		//Setting Data Variable to 0 so it wont re-enter again
	}
}

void LightsOff(void){
	if(Data== '2')																//Check function is called from main
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);
	DIO_u8_Set_Pin_Value(LED_PIN1_PORT,LED_PIN1_PIN,DIO_u8_PIN_LOW);
	DIO_u8_Set_Pin_Value(LED_PIN2_PORT,LED_PIN2_PIN,DIO_u8_PIN_LOW);
	DIO_u8_Set_Pin_Value(LED_PIN3_PORT,LED_PIN3_PIN,DIO_u8_PIN_LOW);
	DIO_u8_Set_Pin_Value(LED_PIN4_PORT,LED_PIN4_PIN,DIO_u8_PIN_LOW);

	if(Data == '2')																//Check function is called from main
	{
		LCD_void_WriteString("___LIGHTS OFF___",LCD_BIT_0,LCD_SECOND_LINE);
		Data =0;																//Setting Data Variable to 0 so it wont re-enter again
	}
}

void ControlLights(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);
	LCD_void_WriteString("__LIGHTS AUTO___",LCD_BIT_0,LCD_SECOND_LINE);
	u16 Loc_ADCReading=0;
	u16 PrevValue=1;
	while(Data == '3')
	{
		ADC_u8StartConversion_Synch(ADC_SINGLE_ENDED_IP_ADC7,&Loc_ADCReading);	//Reading the LDR Sensor
		if(PrevValue != Loc_ADCReading)											//Checking if it has a new value
		{
			switch(Loc_ADCReading)												//Lighting depending on LDR value
			{
			case 0 ... 255 :													//First range -NO LIGHTING-
				LightsOff();													//Turn LED array off to set new value for it
				LightsOn();
				break;
			case 256 ... 511 :													//Second range -SIMPLE LIGHTS-
				LightsOff();
				DIO_u8_Set_Pin_Value(LED_PIN1_PORT,LED_PIN1_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN2_PORT,LED_PIN2_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN3_PORT,LED_PIN3_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN4_PORT,LED_PIN4_PIN,DIO_u8_PIN_LOW);
				break;
			case 512 ... 766 :													//Third range -FAIR LIGHTING-
				LightsOff();
				DIO_u8_Set_Pin_Value(LED_PIN1_PORT,LED_PIN1_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN2_PORT,LED_PIN2_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN3_PORT,LED_PIN3_PIN,DIO_u8_PIN_LOW);
				DIO_u8_Set_Pin_Value(LED_PIN4_PORT,LED_PIN4_PIN,DIO_u8_PIN_LOW);
				break;
			case 767 ... 1024 :												 	//Fourth range -GOOD LIGHTING-
				LightsOff();
				DIO_u8_Set_Pin_Value(LED_PIN1_PORT,LED_PIN1_PIN,DIO_u8_PIN_HIGH);
				DIO_u8_Set_Pin_Value(LED_PIN2_PORT,LED_PIN2_PIN,DIO_u8_PIN_LOW);
				DIO_u8_Set_Pin_Value(LED_PIN3_PORT,LED_PIN3_PIN,DIO_u8_PIN_LOW);
				DIO_u8_Set_Pin_Value(LED_PIN4_PORT,LED_PIN4_PIN,DIO_u8_PIN_LOW);
				break;
			default:															//Fifth range -GREAT LIGHTING-
				LightsOff();
				break;
			}
			PrevValue=Loc_ADCReading;											//Save the LDR value to prevent it from entering again if it has the same value
		}
	}
}


void DoorOpen(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);

	TIMER_COUNTER_1_voidInit();													//Initiate Timer1 to produce PWM signal
	TIMER1_voidICR(PERIODIC_TIME);												//Set Periodic time

	TIMER1_voidSetChannelACompareMatchValue(DOOR_OPENED);  						//Set On-Time (Opening the door)
	LCD_void_WriteString("___DOOR OPEN____",LCD_BIT_0,LCD_SECOND_LINE);
	_delay_ms(250);																//Busy wait to let the servo motor reach the desired position
	TIMER1_voidStopTimer1();													//Timer1 OFF
	Data=0;																		//Setting Data Variable to zero so it wont re-enter again
}


void DoorClose(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);

	TIMER_COUNTER_1_voidInit();                                                //Initiate Timer1 to produce PWM signal
	TIMER1_voidICR(PERIODIC_TIME);                                             //Set Periodic time

	TIMER1_voidSetChannelACompareMatchValue(DOOR_CLOSED);                      //Set On-Time (Closing the door)
	LCD_void_WriteString("___DOOR CLOSE__",LCD_BIT_0,LCD_SECOND_LINE);
	_delay_ms(250);                                                            //Busy wait to let the servo motor reach the desired position
	TIMER1_voidStopTimer1();                                                   //Timer1 OFF
	Data=0;																	   //Setting Data Variable to zero so it wont re-enter again
}


s32 Map(s32 Copy_s32IN, s32 Copy_s32INmin, s32 Copy_s32INmax, s32 Copy_s32OUTmin, s32 Copy_s32OUTmax)
{
	return ((((Copy_s32IN - Copy_s32INmin)*(Copy_s32OUTmax - Copy_s32OUTmin))/(Copy_s32INmax - Copy_s32INmin)) + Copy_s32OUTmin);
}


void FanOn(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);
	if(DC_Flag)																	//Check if Fan was in Controlled by sensor (PWM was ON)
	{
		TIMER0_voidStopTimer0();												//Turn Timer0 (PWM) OFF
	}
	DIO_u8_Set_Pin_Value(FAN_PORT,FAN_PIN,DIO_u8_PIN_HIGH);
	LCD_void_WriteString("____FAN ON_____",LCD_BIT_0,LCD_SECOND_LINE);
	Data=0;																		//Setting Data Variable to zero so it wont re-enter again
}


void FanOff(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);
	if(DC_Flag)                                                             	//Check if Fan was in Controlled by sensor (PWM was ON)
	{
		TIMER0_voidStopTimer0();                                            	//Turn Timer0 (PWM) OFF
	}
	DIO_u8_Set_Pin_Value(FAN_PORT,FAN_PIN,DIO_u8_PIN_LOW);
	LCD_void_WriteString("____FAN Off____",LCD_BIT_0,LCD_SECOND_LINE);
	Data=0;                                                                 	//Setting Data Variable to zero so it wont re-enter again
}


void ControlFan(void){
	LCD_void_WriteString("_______________",LCD_BIT_0,LCD_SECOND_LINE);
	TIMER_COUNTER_0_voidInit();													//Initiate Timer1 (PWM)
	LCD_void_WriteString("___FAN AUTO____",LCD_BIT_0,LCD_SECOND_LINE);
	u16 LocADCReading=0;
	u8 PrevVal=1;
	DC_Flag=1;
	while(Data == '8')															//Polling while No other function is called
	{
		ADC_u8StartConversion_Synch(ADC_SINGLE_ENDED_IP_ADC6,&LocADCReading);	//Read the potentiometer value
		LocADCReading=Map(LocADCReading,0,1024,0,255);							//Map the reading to range of PWM
		if(PrevVal != LocADCReading)
		{
			TIMER0_voidSetCompareMatchValue(LocADCReading);						//Set the Value of On-Time
			PrevVal=LocADCReading;												//Save Current Reading to prevent it from entering if the Reading is still the same
		}
	}

}


void EXTI0Func(void){
	Data=122;																	//Set Variable to Emergency Code
	GIE_voidDisable();															//Turn OFF all interrupts to execute the Emergency function only
}


void EMRGNCYFUNC(void){
	LCD_void_WriteString("___EMERGENCY!___",LCD_BIT_0,LCD_FIRST_LINE);
	LCD_void_WriteString("_EXIT BUILDING__",LCD_BIT_0,LCD_SECOND_LINE);
	while(1){																	//Polling till the system resets
		DIO_u8_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,DIO_u8_PIN_HIGH);
		DIO_u8_Set_Pin_Value(EMRG_LIGHT_PORT,EMRG_LIGHT_PIN,DIO_u8_PIN_HIGH);
		_delay_ms(1000);
		DIO_u8_Set_Pin_Value(BUZZER_PORT,BUZZER_PIN,DIO_u8_PIN_LOW);
		DIO_u8_Set_Pin_Value(EMRG_LIGHT_PORT,EMRG_LIGHT_PIN,DIO_u8_PIN_LOW);
		_delay_ms(1000);
	}
}
