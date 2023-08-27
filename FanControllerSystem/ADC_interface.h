/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: ADC							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInnit(void);

u8 ADC_u8StartConversion_Synch(u8 Copy_u8Channel, u16* Copy_pu16Reading);

/* Before calling next function TURN ON GLOBAL INTERRUPT ENABLE */
u8 ADC_u8StartConversion_ASynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void) );


#define RESOLUTION_10BITS	1024
#define RESOLUTION_8BITS	256

	/* ANALOG CHANNEL & GAIN SELECTION */
#define ADC_SINGLE_ENDED_IP_ADC0	0
#define ADC_SINGLE_ENDED_IP_ADC1	1
#define ADC_SINGLE_ENDED_IP_ADC2	2
#define ADC_SINGLE_ENDED_IP_ADC3	3
#define ADC_SINGLE_ENDED_IP_ADC4	4
#define ADC_SINGLE_ENDED_IP_ADC5	5
#define ADC_SINGLE_ENDED_IP_ADC6	6
#define ADC_SINGLE_ENDED_IP_ADC7	7

#define ADC_DIFF_POS_ADC0_NEG_ADC0_GAIN_10X  8
#define ADC_DIFF_POS_ADC1_NEG_ADC0_GAIN_10X  9
#define ADC_DIFF_POS_ADC0_NEG_ADC0_GAIN_200X 10
#define ADC_DIFF_POS_ADC1_NEG_ADC0_GAIN_200X 11

#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_10X  12
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_10X  13
#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_200X 14
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_200X 15

#define ADC_DIFF_POS_ADC0_NEG_ADC1_GAIN_1X   16
#define ADC_DIFF_POS_ADC1_NEG_ADC1_GAIN_1X   17
#define ADC_DIFF_POS_ADC2_NEG_ADC1_GAIN_1X   18
#define ADC_DIFF_POS_ADC3_NEG_ADC1_GAIN_1X   19

#define ADC_DIFF_POS_ADC4_NEG_ADC1_GAIN_1X   20
#define ADC_DIFF_POS_ADC5_NEG_ADC1_GAIN_1X   21
#define ADC_DIFF_POS_ADC6_NEG_ADC1_GAIN_1X   22
#define ADC_DIFF_POS_ADC7_NEG_ADC1_GAIN_1X   23

#define ADC_DIFF_POS_ADC0_NEG_ADC2_GAIN_1X   24
#define ADC_DIFF_POS_ADC1_NEG_ADC2_GAIN_1X   25
#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_1X   26
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_1X   27

#define ADC_DIFF_POS_ADC4_NEG_ADC2_GAIN_1X   28
#define ADC_DIFF_POS_ADC5_NEG_ADC2_GAIN_1X   29

#define ADC_SINGLE_ENDED_IP_1DOT22VOLT   30
#define ADC_SINGLE_ENDED_IP_GND   31


#endif
