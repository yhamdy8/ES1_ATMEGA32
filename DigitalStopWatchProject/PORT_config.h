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

#define GROUPA_PIN0_DIR		OUTPUT  //Activation Pins for SSG Bit0,, S0
#define GROUPA_PIN1_DIR		OUTPUT  //Activation Pins for SSG Bit1,, S1
#define GROUPA_PIN2_DIR		OUTPUT  //Activation Pins for SSG Bit2,, M0
#define GROUPA_PIN3_DIR		OUTPUT  //Activation Pins for SSG Bit3,, M1
#define GROUPA_PIN4_DIR		OUTPUT  //Activation Pins for SSG Bit4,, H0
#define GROUPA_PIN5_DIR		OUTPUT  //Activation Pins for SSG Bit5,, H1
#define GROUPA_PIN6_DIR		OUTPUT
#define GROUPA_PIN7_DIR		OUTPUT
							/* VALUES OF GROUP A */
#define GROUPA_PIN0_INITIAL_VAL		LOW
#define GROUPA_PIN1_INITIAL_VAL		LOW
#define GROUPA_PIN2_INITIAL_VAL		LOW
#define GROUPA_PIN3_INITIAL_VAL		LOW
#define GROUPA_PIN4_INITIAL_VAL		LOW
#define GROUPA_PIN5_INITIAL_VAL		LOW
#define GROUPA_PIN6_INITIAL_VAL		LOW
#define GROUPA_PIN7_INITIAL_VAL		LOW

							/* DIRECTION OF GROUP B */

#define GROUPB_PIN0_DIR		INPUT
#define GROUPB_PIN1_DIR		INPUT
#define GROUPB_PIN2_DIR		INPUT // Interrupt 2 pin - Reset -
#define GROUPB_PIN3_DIR		INPUT // OC0
#define GROUPB_PIN4_DIR		INPUT
#define GROUPB_PIN5_DIR		INPUT
#define GROUPB_PIN6_DIR		INPUT
#define GROUPB_PIN7_DIR		INPUT
   	   	   	   	   	   	   	/* VALUES OF GROUP B */
#define GROUPB_PIN0_INITIAL_VAL		FLOATING
#define GROUPB_PIN1_INITIAL_VAL		FLOATING
#define GROUPB_PIN2_INITIAL_VAL		PULLUP		// INT2
#define GROUPB_PIN3_INITIAL_VAL		FLOATING
#define GROUPB_PIN4_INITIAL_VAL		FLOATING
#define GROUPB_PIN5_INITIAL_VAL		FLOATING
#define GROUPB_PIN6_INITIAL_VAL		FLOATING
#define GROUPB_PIN7_INITIAL_VAL		FLOATING
  
							/* DIRECTION OF GROUP C */

#define GROUPC_PIN0_DIR		OUTPUT  // Pins writing Decimal values to the decoder which translate to BCD as Ip for SSG
#define GROUPC_PIN1_DIR		OUTPUT  // Pins writing Decimal values to the decoder which translate to BCD as Ip for SSG
#define GROUPC_PIN2_DIR		OUTPUT  // Pins writing Decimal values to the decoder which translate to BCD as Ip for SSG
#define GROUPC_PIN3_DIR		OUTPUT  // Pins writing Decimal values to the decoder which translate to BCD as Ip for SSG
#define GROUPC_PIN4_DIR		INPUT
#define GROUPC_PIN5_DIR		INPUT
#define GROUPC_PIN6_DIR		INPUT
#define GROUPC_PIN7_DIR		INPUT
							/* VALUES OF GROUP C */
#define GROUPC_PIN0_INITIAL_VAL		LOW
#define GROUPC_PIN1_INITIAL_VAL		LOW
#define GROUPC_PIN2_INITIAL_VAL		LOW
#define GROUPC_PIN3_INITIAL_VAL		LOW
#define GROUPC_PIN4_INITIAL_VAL		FLOATING
#define GROUPC_PIN5_INITIAL_VAL		FLOATING
#define GROUPC_PIN6_INITIAL_VAL		FLOATING
#define GROUPC_PIN7_INITIAL_VAL		FLOATING

							/* DIRECTION OF GROUP D */

#define GROUPD_PIN0_DIR		INPUT
#define GROUPD_PIN1_DIR		INPUT
#define GROUPD_PIN2_DIR		INPUT	// INT 0 Pin - PAUSE -
#define GROUPD_PIN3_DIR		INPUT	// INT 1 Pin - RESUME -
#define GROUPD_PIN4_DIR		INPUT
#define GROUPD_PIN5_DIR		INPUT
#define GROUPD_PIN6_DIR		INPUT
#define GROUPD_PIN7_DIR		INPUT
							/* VALUES OF GROUP D */
#define GROUPD_PIN0_INITIAL_VAL		FLOATING
#define GROUPD_PIN1_INITIAL_VAL		FLOATING
#define GROUPD_PIN2_INITIAL_VAL		PULLUP
#define GROUPD_PIN3_INITIAL_VAL		PULLUP
#define GROUPD_PIN4_INITIAL_VAL		FLOATING
#define GROUPD_PIN5_INITIAL_VAL		FLOATING
#define GROUPD_PIN6_INITIAL_VAL		FLOATING
#define GROUPD_PIN7_INITIAL_VAL		FLOATING
 

#endif
