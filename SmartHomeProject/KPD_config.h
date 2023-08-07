/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	HAL							***********************/
/************************		COMPONENT: KPD						***********************/
/************************		VERSION: 1.00						***********************/
/************************		DATE: 21/05/2023					***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_ROW_NUM		4
#define KPD_COL_NUM		4

#define KPD_COL_PORT	DIO_u8_GROUP_B

#define KPD_COL_PIN_0	DIO_u8_PIN_4
#define KPD_COL_PIN_1	DIO_u8_PIN_5
#define KPD_COL_PIN_2	DIO_u8_PIN_6
#define KPD_COL_PIN_3	DIO_u8_PIN_7

#define KPD_ROW_PORT	DIO_u8_GROUP_A

#define KPD_ROW_PIN_0	DIO_u8_PIN_0
#define KPD_ROW_PIN_1	DIO_u8_PIN_1
#define KPD_ROW_PIN_2	DIO_u8_PIN_2
#define KPD_ROW_PIN_3	DIO_u8_PIN_3





//
#define KPD_ARR_VAL		{ {1,2,3,0}, {4,5,6,0}, {7,8,9,0}, {'C',0,'K',0} }

#endif
