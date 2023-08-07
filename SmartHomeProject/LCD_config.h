/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	HAL							***********************/
/************************		COMPONENT: LCD						***********************/
/************************		VERSION: 1.00						***********************/
/************************		DATE: 15/05/2023					***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define LCD_CTRL_PORT	DIO_u8_GROUP_B	/*control port*/

#define	LCD_RS_PIN		DIO_u8_PIN_0	// RS pin
#define	LCD_RW_PIN		DIO_u8_PIN_1	// RW pin
#define	LCD_E_PIN		DIO_u8_PIN_2	// enable pin


#define LCD_DATA_PORT		DIO_u8_GROUP_C	/*data pins*/

#define LCD_u8_Data_Pin_0	DIO_u8_PIN_0
#define LCD_u8_Data_Pin_1   DIO_u8_PIN_1
#define LCD_u8_Data_Pin_2   DIO_u8_PIN_2
#define LCD_u8_Data_Pin_3   DIO_u8_PIN_3

#define LCD_u8_Data_Pin_4   DIO_u8_PIN_4
#define LCD_u8_Data_Pin_5   DIO_u8_PIN_5
#define LCD_u8_Data_Pin_6   DIO_u8_PIN_6
#define LCD_u8_Data_Pin_7   DIO_u8_PIN_7




#endif
