*In this project we aim to develop a system which turn ON/OFF fan based on temp, while adjusting the speed automatically.
*This was made using
MCAL: DIO,ADC,PWM(TIMER).
HAL:LCD,LM35(Sensor),DC-Motor.

*Using LM35 Temp sensor:
-Till 30 deg. Fan is OFF.
-Once greater than 30 and up to 59 deg. fan will operate with 25% of its power.
-From 60 deg. to 89 deg. fan will operate with 50% of its power.
-From 90 deg. to 119 deg. fan will operate with 75% of its power.
-From 120 deg. and higher fan will operate with its full power.

*While displaying all info on LCD (Current Temp & Fan state).
*Motor is controlled based on -Fast- PWM signal generated from Timer 0 based on the Temp reading from the LM 35.

*Temp Calculations:
using ADC with 10 bit resolution
Analog volt= Digital value * Step
           = Digital value * (ref. volt / ADC resolution)
           = (Digital value * ref. volt) / ADC resolution // as to prevent error of getting zero when dividing by 1024 first
Analog volt /= 1024; // we got the Analog volt value
Since, 10 mV == 1 deg Cel.
Thus; 
Temp = Analog volt /10; // now we got the temp.

*Timer 0 -Fast- PWM calculation:
Using Non-inverted Mode, with 8 Prescaler.
Tick time = 1 micro-second, with Periodic time = over-flow time = 256 micro-second.
Thus, Duty cycle of 25% = 256/4 = 64;
      Duty cycle of 50% = 256/2 = 128;
      Duty cycle of 75% = 256*(3/4)= 192;
      Duty cycle of 100% = 256;
Assiging the values of the duty cycle to the OCR register to generate a PWM on OC0 pin with the required Duty Cycle.
