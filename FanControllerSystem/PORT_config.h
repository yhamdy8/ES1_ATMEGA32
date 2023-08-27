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

	
/* choose DIR */
#define INPUT	0	
#define OUTPUT	1
 
/* case DIR: INPUT */
#define FLOATING	0
#define PULLUP		1

/* case DIR: OUTPUT */
#define LOW		0
#define HIGH	1	

		/* PORT DIR and VAL are default to FLOATING INPUT */

							/* DIRECTION OF GROUP A */

#define GROUPA_PIN0_DIR		INPUT /* ADC0 */
#define GROUPA_PIN1_DIR		INPUT /* ADC1 */
#define GROUPA_PIN2_DIR		INPUT /* ADC2 */
#define GROUPA_PIN3_DIR		INPUT /* ADC3 */
#define GROUPA_PIN4_DIR		INPUT /* ADC4 */
#define GROUPA_PIN5_DIR		INPUT /* ADC5 */
#define GROUPA_PIN6_DIR		INPUT /* ADC6 */
#define GROUPA_PIN7_DIR		INPUT /* ADC7 */
							/* VALUES OF GROUP A */
#define GROUPA_PIN0_INITIAL_VAL		PULLUP
#define GROUPA_PIN1_INITIAL_VAL		FLOATING
#define GROUPA_PIN2_INITIAL_VAL		FLOATING
#define GROUPA_PIN3_INITIAL_VAL		FLOATING
#define GROUPA_PIN4_INITIAL_VAL		FLOATING
#define GROUPA_PIN5_INITIAL_VAL		FLOATING
#define GROUPA_PIN6_INITIAL_VAL		FLOATING
#define GROUPA_PIN7_INITIAL_VAL		FLOATING

							/* DIRECTION OF GROUP B */

#define GROUPB_PIN0_DIR		INPUT
#define GROUPB_PIN1_DIR		INPUT
#define GROUPB_PIN2_DIR		INPUT /* INT2 */
#define GROUPB_PIN3_DIR		OUTPUT /* OC0  */ // PWM SIGNAL
#define GROUPB_PIN4_DIR		INPUT
#define GROUPB_PIN5_DIR		INPUT
#define GROUPB_PIN6_DIR		INPUT
#define GROUPB_PIN7_DIR		INPUT
   	   	   	   	   	   	   	/* VALUES OF GROUP B */
#define GROUPB_PIN0_INITIAL_VAL		FLOATING
#define GROUPB_PIN1_INITIAL_VAL		FLOATING
#define GROUPB_PIN2_INITIAL_VAL		FLOATING
#define GROUPB_PIN3_INITIAL_VAL		LOW
#define GROUPB_PIN4_INITIAL_VAL		FLOATING
#define GROUPB_PIN5_INITIAL_VAL		FLOATING
#define GROUPB_PIN6_INITIAL_VAL		FLOATING
#define GROUPB_PIN7_INITIAL_VAL		FLOATING
  
							/* DIRECTION OF GROUP C */

#define GROUPC_PIN0_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN1_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN2_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN3_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN4_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN5_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN6_DIR		OUTPUT  //LCD DATA PINS
#define GROUPC_PIN7_DIR		OUTPUT  //LCD DATA PINS
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

#define GROUPD_PIN0_DIR		OUTPUT           //LCD CONTROL PINS
#define GROUPD_PIN1_DIR		OUTPUT           //LCD CONTROL PINS
#define GROUPD_PIN2_DIR		OUTPUT /* INT0 *///LCD CONTROL PINS
#define GROUPD_PIN3_DIR		INPUT /* INT1 */
#define GROUPD_PIN4_DIR		INPUT /* OC1B */
#define GROUPD_PIN5_DIR		INPUT /* OC1A */
#define GROUPD_PIN6_DIR		INPUT
#define GROUPD_PIN7_DIR		INPUT /* OC2  */
							/* VALUES OF GROUP D */
#define GROUPD_PIN0_INITIAL_VAL		LOW
#define GROUPD_PIN1_INITIAL_VAL		LOW
#define GROUPD_PIN2_INITIAL_VAL		LOW
#define GROUPD_PIN3_INITIAL_VAL		FLOATING
#define GROUPD_PIN4_INITIAL_VAL		FLOATING
#define GROUPD_PIN5_INITIAL_VAL		FLOATING
#define GROUPD_PIN6_INITIAL_VAL		FLOATING
#define GROUPD_PIN7_INITIAL_VAL		FLOATING
 

#endif
