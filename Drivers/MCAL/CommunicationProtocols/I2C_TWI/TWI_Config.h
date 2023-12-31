/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		COMPONENT: TWI						***********************/
/************************		VERSION: 1.00						***********************/
/************************		DATE: 10/07/2023					***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

/*
 * SCL_Freq = (System Frequency) / (16 + ( 2*TWBR ) * ( (4)^TWPS) )
 * Assume value to TWBR & TWPS till u reach the required value of SCL_freq
 * TWBR Value = 0 --> 255
 * TWPS Value = 0 --> 3
 */
#define TWBR 2
#define TWPS 0

#endif /* TWI_CONFIG_H_ */
