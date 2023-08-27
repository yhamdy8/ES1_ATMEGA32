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



#ifndef EXTI_REGISTER_H_
#define	EXTI_REGISTER_H_

#define EXTI_u8GICR	*((volatile u8*) 0x5B)	// PIE
#define EXTI_u8GICR_INT1	7
#define EXTI_u8GICR_INT0	6
#define EXTI_u8GICR_INT2	5

#define EXTI_u8GIFR	*((volatile u8*) 0x5A)	// PIF
//#define SREG	*((volatile u8*) 0x5F)	// GIE driver

#define EXTI_u8MCUCR 	*((volatile u8*) 0x55)	// INT1, INT0.. Interrupt Sensing control
#define	EXTI_u8MCUCR_ISC11	3
#define EXTI_u8MCUCR_ISC10	2
#define EXTI_u8MCUCR_ISC01	1
#define EXTI_u8MCUCR_ISC00	0


#define EXTI_u8MCUCSR	*((volatile u8*) 0x54)	// INT2.. Interrupt Sensing control
#define EXTI_u8MCUCSR_INT2	6






#endif
