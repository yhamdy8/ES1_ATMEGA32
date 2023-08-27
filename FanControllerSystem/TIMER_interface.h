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



#ifndef  TIMER_INTERFACE_H_
#define  TIMER_INTERFACE_H_


#define NO_ERROR 0
#define NULL_POINTER 1


void TIMER_COUNTER_0_voidInit(void);

u8 TIMER0_u8SetCallBack_COMPMATCH( void (*Copy_pvCallBackFunc)(void) );

u8 TIMER0_u8SetCallBack_OVFLOW( void (*Copy_pvCallBackFunc)(void) );

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);

void TIMER0_voidStopTimer0(void);
/*
void TIMER_COUNTER_1_voidInit(void);

void TIMER1_voidICR(u16 Copy_u16ICRValue);	/* TOP VALUE @ PWM *

void TIMER1_voidSetChannelACompareMatchValue(u8 Copy_u8Value);	/*To calc ON Time*
*/






#endif
