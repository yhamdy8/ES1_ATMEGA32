/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: TIMER						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/



#ifndef  TIMER_1_INTERFACE_H_
#define  TIMER_1_INTERFACE_H_


#define NO_ERROR 0
#define ERROR	 2
#define NULL_POINTER 1


#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE	0

#define ICU_DIS_INTERRUPT	0
#define ICU_EN_INTERRUPT	1

void TIMER_COUNTER_1_voidInit(void);

void TIMER1_voidICR(u16 Copy_u16ICRValue);	/* TOP VALUE @ PWM */

void TIMER1_voidSetChannelACompareMatchValue(u16 Copy_u16Value);	/*To calc ON Time*/

u16 TIMER1_u16ReadTimer1Value(void);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);


u8 ICU_u8EnDisInterrupt(u8 Copy_u8EnDis);

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);

void ICU_voidInit(void);

u16 ICU_u16ReadInputCapture(void);

u8 ICU_u8SetCallBack( void (*Copy_pvCallBackFunc)(void) );

void TIMER1_voidStopTimer1(void);


#endif
