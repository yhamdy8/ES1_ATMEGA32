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





#ifndef EXTI_CONFIG_H_
#define	EXTI_CONFIG_H_

/* SENSE OPTIONS :
 * 					1- EXTI_LOW_LEVEL
 * 					2- EXTI_IOC
 * 					3- EXTI_FALLING_EDGE
 * 					4- EXTI_RISING_EDGE
 */
#define INT0_SENSE 			EXTI_FALLING_EDGE
#define INT1_SENSE 			EXTI_FALLING_EDGE
#define INT2_SENSE			EXTI_FALLING_EDGE
/* INITIAL_STATE OPTIONS :
 * 							1-EXTI_ENABLE
 * 							2-EXTI_DISABLE
 */
#define INT0_INITIAL_STATE 	EXTI_ENABLE
#define INT1_INITIAL_STATE 	EXTI_ENABLE
#define INT2_INITIAL_STATE	EXTI_ENABLE


#endif
