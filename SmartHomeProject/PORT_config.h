/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: GROUP						***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef GROUP_CONFIG_H_
#define GROUP_CONFIG_H_
	
	/* PORT DIR and VAL default to FLOATING INPUT */
	
/* choose DIR */
#define INPUT	0	
#define OUTPUT	1
 
/* case DIR: INPUT */
#define FLOATING	0
#define PULLUP		1
/* case DIR: OUTPUT */
#define LOW		0
#define HIGH	1	

							/* DIRECTION OF GROUP A */

#define GROUPA_PIN0_DIR		INPUT /* ADC0 */  //KPD  ROW PINS #1
#define GROUPA_PIN1_DIR		INPUT /* ADC1 */  //KPD  ROW PINS #2
#define GROUPA_PIN2_DIR		INPUT /* ADC2 */  //KPD  ROW PINS #3
#define GROUPA_PIN3_DIR		INPUT /* ADC3 */  //KPD  ROW PINS #4
#define GROUPA_PIN4_DIR		OUTPUT /* ADC4 */ // EMERGENCY LIGHT
#define GROUPA_PIN5_DIR		OUTPUT /* ADC5 */ // LED 7 & 8
#define GROUPA_PIN6_DIR		INPUT /* ADC6 */  // Potentiometer Sensor
#define GROUPA_PIN7_DIR		INPUT /* ADC7 */  // LDR Sensor
							/* VALUES OF GROUP A */
#define GROUPA_PIN0_INITIAL_VAL		PULLUP
#define GROUPA_PIN1_INITIAL_VAL		PULLUP
#define GROUPA_PIN2_INITIAL_VAL		PULLUP
#define GROUPA_PIN3_INITIAL_VAL		PULLUP
#define GROUPA_PIN4_INITIAL_VAL		LOW
#define GROUPA_PIN5_INITIAL_VAL		LOW
#define GROUPA_PIN6_INITIAL_VAL		PULLUP
#define GROUPA_PIN7_INITIAL_VAL		PULLUP

							/* DIRECTION OF GROUP B */

#define GROUPB_PIN0_DIR		OUTPUT             // LCD CONTROL PINS
#define GROUPB_PIN1_DIR		OUTPUT             // LCD CONTROL PINS
#define GROUPB_PIN2_DIR		OUTPUT /* INT2 */  // LCD CONTROL PINS
#define GROUPB_PIN3_DIR		OUTPUT /* OC0  */  //DC Motor Control
#define GROUPB_PIN4_DIR		OUTPUT             //KPD  Col PINS #1
#define GROUPB_PIN5_DIR		OUTPUT             //KPD  Col PINS #2
#define GROUPB_PIN6_DIR		OUTPUT             //KPD  Col PINS #3
#define GROUPB_PIN7_DIR		OUTPUT             //KPD  Col PINS #4
   	   	   	   	   	   	   	/* VALUES OF GROUP B */
#define GROUPB_PIN0_INITIAL_VAL		LOW
#define GROUPB_PIN1_INITIAL_VAL		LOW
#define GROUPB_PIN2_INITIAL_VAL		LOW
#define GROUPB_PIN3_INITIAL_VAL		LOW
#define GROUPB_PIN4_INITIAL_VAL		HIGH
#define GROUPB_PIN5_INITIAL_VAL		HIGH
#define GROUPB_PIN6_INITIAL_VAL		HIGH
#define GROUPB_PIN7_INITIAL_VAL		HIGH
  
							/* DIRECTION OF GROUP C */

#define GROUPC_PIN0_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN1_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN2_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN3_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN4_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN5_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN6_DIR		OUTPUT    // LCD DATA PINS
#define GROUPC_PIN7_DIR		OUTPUT    // LCD DATA PINS
							/* VALUES OF GROUP C */
#define GROUPC_PIN0_INITIAL_VAL		LOW
#define GROUPC_PIN1_INITIAL_VAL		LOW
#define GROUPC_PIN2_INITIAL_VAL		LOW
#define GROUPC_PIN3_INITIAL_VAL		LOW
#define GROUPC_PIN4_INITIAL_VAL		LOW
#define GROUPC_PIN5_INITIAL_VAL		LOW
#define GROUPC_PIN6_INITIAL_VAL		LOW
#define GROUPC_PIN7_INITIAL_VAL		LOW

							/* DIRECTION OF GROUP D */

#define GROUPD_PIN0_DIR		INPUT  /* Rx */   // BLUETOOTH MOD
#define GROUPD_PIN1_DIR		OUTPUT /* Tx */   // BLUETOOTH MOD
#define GROUPD_PIN2_DIR		INPUT  /* INT0 */ // EMERGENCY BUTTON
#define GROUPD_PIN3_DIR		OUTPUT /* INT1 */ // LED 1 & 2
#define GROUPD_PIN4_DIR		OUTPUT /* OC1B */ // LED 3 & 4
#define GROUPD_PIN5_DIR		OUTPUT  /* OC1A */ // Servo Motor Control
#define GROUPD_PIN6_DIR		OUTPUT /* ICU */  // EMERGENCY BUZZER
#define GROUPD_PIN7_DIR		OUTPUT /* OC2  */ // LED 5&6
							/* VALUES OF GROUP D */
#define GROUPD_PIN0_INITIAL_VAL		FLOATING
#define GROUPD_PIN1_INITIAL_VAL		LOW
#define GROUPD_PIN2_INITIAL_VAL		PULLUP
#define GROUPD_PIN3_INITIAL_VAL		LOW
#define GROUPD_PIN4_INITIAL_VAL		LOW
#define GROUPD_PIN5_INITIAL_VAL		LOW
#define GROUPD_PIN6_INITIAL_VAL		LOW
#define GROUPD_PIN7_INITIAL_VAL		LOW
 

#endif
