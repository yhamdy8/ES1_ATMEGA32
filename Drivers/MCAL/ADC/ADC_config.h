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

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_u32TIMEOUT	50000
#define NO_ERRORS		0
#define NULL_POINTER	1
#define BUSY_FUNC		2
#define TIMEOUT_ERROR	7
/* ADC_PRESCALER_SELECTION OPTIONS :
 * 									1-DIV_2
 * 									2-DIV_4
 * 									3-DIV_8
 * 									4-DIV_16
 * 									5-DIV_32
 * 									6-DIV_64
 * 									7-DIV_128
 */
#define ADC_PRESCALER_SELECTION    DIV_128

/* ADC_REF_VOLT OPTIONS :
 * 									1- REFVOL_5V
 * 									2- REFVOL_2DOT56V
 * 									3- EXTERNAL_VOLT
 */
#define ADC_REF_VOLT	REFVOL_5V
#if ADC_REF_VOLT == EXTERNAL_VOLT
 /* IN CASE OF EXTERNAL VOLT PLEASE ENTER ITS VALUE BELOW */
#define ADC_EXT_REF_VOLT	0
#endif


/* ADC_DATA_REGISTER_RESOLUTION OPTIONS :
 * 									1- RESOLUTION_10BITS
 * 									2- RESOLUTION_8BITS
 */
#define ADC_RESOLUTION	RESOLUTION_10BITS

/*	ADC_AUTO_TRIGGER OPTIONS :
 * 									1- AUTO_TRIGGER_ENABLE	// ADC START ON +VE EDGE
 * 									2- AUTO_TRIGGER_DISABLE	// Single Conversion Mode
 */
#define ADC_AUTO_TRIGGER	 AUTO_TRIGGER_DISABLE
#if ADC_AUTO_TRIGGER == AUTO_TRIGGER_ENABLE
	/* Select Auto trigger channel */
#define AUTO_TRIGGER_CHANNEL	ADC_SINGLE_ENDED_IP_ADC0
/*	ADC_AUTO_TRIGGER_SOURCE OPTIONS :
 * 									1- ADTS_FREE_RUNNING_MODE
 * 									2- ADTS_ANALOG_COMPARATOR
 * 									3- ADTS_EXTI0
 * 									4- ADTS_TIMER_COUNTER0_COMPARE_MATCH
 * 									5- ADTS_TIMER_COUNTER0_OVERFLOW
 * 									6- ADTS_TIMER_COUNTER_COMPARE_MATCH_B
 * 									7- ADTS_TIMER_COUNTER1_OVERFLOW
 * 									8- ADTS_TIMER_COUNTER1_CAPTURE_EVENT
 */
#define ADC_AUTO_TRIGGER_SOURCE		ADTS_FREE_RUNNING_MODE

#endif


#endif
