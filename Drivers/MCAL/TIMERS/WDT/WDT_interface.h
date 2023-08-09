/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
/************************		AUTHOR: Youssef Hamdy			   	***********************/
/************************		LAYER:	MCAL						***********************/
/************************		DRIVER: WDT							***********************/
/************************		VERSION: 1.00						***********************/
/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

void WDT_voidSleep(u8 Copy_u8Value);

void WDT_voidEnable(void);

void WDT_voidDisable(void);

#if WDT_REF_VOLT ==	Vcc_5V

#define WDT_TIMEOUT_16_3_msec	0
#define WDT_TIMEOUT_32_5_msec	1
#define WDT_TIMEOUT_65_msec		2
#define WDT_TIMEOUT_0_13_sec	3
#define WDT_TIMEOUT_0_26_sec	4
#define WDT_TIMEOUT_0_52_sec	5
#define WDT_TIMEOUT_1_sec		6
#define WDT_TIMEOUT_2_1_sec		7

#elif WDT_REF_VOLT ==	Vcc_3V

#define WDT_TIMEOUT_17_1_msec	0
#define WDT_TIMEOUT_34_3_msec	1
#define WDT_TIMEOUT_68_5_msec	2
#define WDT_TIMEOUT_0_14_sec	3
#define WDT_TIMEOUT_0_27_sec	4
#define WDT_TIMEOUT_0_55_sec	5
#define WDT_TIMEOUT_1_1_sec		6
#define WDT_TIMEOUT_2_2_sec		7

#elif
#error "Wrong WDT_REF_VOLT Config Options!"
#endif

#endif /* WDT_INTERFACE_H_ */
