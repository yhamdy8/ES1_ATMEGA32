/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		file:	Configuration & Interface	***********************/
/************************		APP: 	Smart Home					***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_


 	 	 	 	 	 	 	 /* User names and Passwords Configurations */
//User Names
#define USER1ID	1234
#define	USER2ID	3456
#define USER3ID	6789
//User Passwords
#define USER1PASS	4321
#define USER2PASS	6543
#define USER3PASS	9876

 /* Pin Configurations*/
//LED Ports
#define LED_PIN1_PORT	DIO_u8_GROUP_D
#define LED_PIN2_PORT	DIO_u8_GROUP_D
#define LED_PIN3_PORT	DIO_u8_GROUP_D
#define LED_PIN4_PORT	DIO_u8_GROUP_A

//LED Pins Number
#define LED_PIN1_PIN	DIO_u8_PIN_3
#define LED_PIN2_PIN	DIO_u8_PIN_4
#define LED_PIN3_PIN	DIO_u8_PIN_7
#define LED_PIN4_PIN	DIO_u8_PIN_5

//DC-Motor Port and Pin Number
#define FAN_PORT		DIO_u8_GROUP_B
#define FAN_PIN			DIO_u8_PIN_3

//Emergency Buzzer and Led Port and Pin Number
#define BUZZER_PORT DIO_u8_GROUP_D
#define BUZZER_PIN  DIO_u8_PIN_6
#define EMRG_LIGHT_PORT DIO_u8_GROUP_A
#define EMRG_LIGHT_PIN	DIO_u8_PIN_4

 /* Configuration for Servo Motor based on Data-sheet*/
// Tp,Ton
#define PERIODIC_TIME 20000
#define DOOR_CLOSED 450
#define DOOR_OPENED 2200

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

 	 	 	 	 	 	 	 	 	/* App Functions Prototype */

/*
 * INPUT ARG: void
 * Return Type: u16 (ID/Password)
 * Description: This Function is used to get the ID/PASS entered by the user using KPD.
 */
u16 GetID(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to login into the system making sure the ID & PASS are correct,
 * 					having only 3 trials for each.
 */
void Login(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to Set LED array ON
 */
void LightsOn(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to Set LED array OFF.
 */
void LightsOff(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to Control the LED array using LDR Sensor.
 */
void ControlLights(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to turn the servo motor in a position that the door can open.
 */
void DoorOpen(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to turn the servo motor in a position that the door is closed.
 */
void DoorClose(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to turn the DC motor (FAN) ON with Full Power.
 */
void FanOn(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to turn the DC motor (FAN) OFF.
 */
void FanOff(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to control the DC motor (FAN) using a potentiometer
 */
void ControlFan(void);

/*
 * INPUT ARG: Copy_s32IN     -> Value in INPUT range to map in OUTPUT range.
 * 			  Copy_s32INmin  -> INPUT range Minimum value.
 * 			  Copy_s32INmax  -> INPUT range Maximum value.
 * 			  Copy_s32OUTmin -> OUTPUT range Minimum value.
 * 			  Copy_s32OUTmax -> OUTPUT range Maximum value.
 * Return Type: s32 -> Value mapped in the OUTPUT range
 * Description: This Function is used to map from OUTPUT range to INPUT range,
 * 					giving a certain value in the input range
 */
s32 Map(s32 Copy_s32IN, s32 Copy_s32INmin, s32 Copy_s32INmax, s32 Copy_s32OUTmin, s32 Copy_s32OUTmax);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function (CALLBACK FUNCTION) is used to assign data to variable "Data",
 * 					sent from Bluetooth module based on an interrupt on receive complete.
 */
void GetData(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function (CALLBACK FUNCTION) is used to set Data initiate the Emergency protocol,
 * 		 			based on EXternal INterrupt 0 which has the highest priority.
 */
void EXTI0Func(void);

/*
 * INPUT ARG: void
 * Return Type: void
 * Description: This Function is used to Alert people that there is an emergency using LCD,Buzzer & Red LED.
 */
void EMRGNCYFUNC(void);


#endif /* APP_INTERFACE_H_ */
