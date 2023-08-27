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

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define BIT_0 	0
#define BIT_1 	1
#define BIT_2 	2
#define BIT_3	3
#define BIT_4	4
#define BIT_5	5
#define BIT_6 	6
#define BIT_7	7

#define LCD_FIRST_LINE 		0
#define LCD_SECOND_LINE		1

#define LCD_BIT_0      0
#define LCD_BIT_1      1
#define LCD_BIT_2      2
#define LCD_BIT_3      3
#define LCD_BIT_4      4
#define LCD_BIT_5      5
#define LCD_BIT_6      6
#define LCD_BIT_7      7
#define LCD_BIT_8      8
#define LCD_BIT_9      9
#define LCD_BIT_10     10
#define LCD_BIT_11     11
#define LCD_BIT_12     12
#define LCD_BIT_13     13
#define LCD_BIT_14     14
#define LCD_BIT_15     15

#define LCD_BIT_16 	   16


void LCD_void_Innit_8Bit(void);

void LCD_void_Write_Command(u8 Copy_u8_Command);

void LCD_void_Write_Data(u8 Copy_u8_Data);

void LCD_void_WriteString(const char* Copy_pcString, u8 Copy_u8_XPos, u8 Copy_u8_YPos);

void LCD_void_WriteNumber(u32 Copy_u32Number);

void LCD_void_GoTo_DDRAMPos( u8 Copy_u8_XPos, u8 Copy_u8_YPos);

void LCD_void_WriteSpecialCharacter(u8* Copy_u8SpCharacPattern_Array, u8 Copy_u8SPCharNo, u8 Copy_u8_XPos, u8 Copy_u8_YPos ); //CharacterNo min 0 max 7

void LCD_void_ClearScreen(void);

#endif
