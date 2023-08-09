/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: EXTI						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define	EXTI_INTERFACE_H_


#define EXTI_LOW_LEVEL		1
#define EXTI_IOC			2
#define EXTI_FALLING_EDGE	3
#define EXTI_RISING_EDGE	4

#define EXTI_ENABLE		1
#define EXTI_DISABLE	0

#define EXTI_u8INT0	0
#define EXTI_u8INT1	1
#define EXTI_u8INT2	2


#define NO_ERROR 0
#define ERROR 	 1




void EXTI_voidInt0Innit(void);	/* PRE-BUILD : LOW, IOC, FALLING, RISING */

void EXTI_voidInt1Innit(void);	/* PRE-BUILD : LOW, IOC, FALLING, RISING */

void EXTI_voidInt2Innit(void);	/* PRE-BUILD : FALLING, RISING */


u8 EXTI_u8SetSenseControl_INT0(u8 Copy_u8ISC);	/* POST-BUILD : LOW, IOC, FALLING, RISING */

u8 EXTI_u8SetSenseControl_INT1(u8 Copy_u8ISC);	/* POST-BUILD : LOW, IOC, FALLING, RISING */

u8 EXTI_u8SetSenseControl_INT2(u8 Copy_u8ISC);	/* POST-BUILD : FALLING, RISING */


u8 EXTI_u8EXTI_EnDis(u8 Copy_u8INT_Index, u8 Copy_u8EnDis);


u8 EXTI_u8SetCallBack(u8 Copy_u8EXTI_Index, void (*Copy_PvEXTIFunc)(void) );

#endif
