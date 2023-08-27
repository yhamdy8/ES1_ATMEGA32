In this project a Digital StopWatch is created running in real time, Based on Timer 1. And three Push Buttons which are RESET, PAUSE and RESUME, based on EXternal INTerrupt Pins.

//Timer 1 Calculations:
Selecting Prescaler 8 with system clock of 8MHz, giving us 1 micro-second.
Using Timer 1 -16 Bit- Counting up to 2(pow)16== 65536.
Selecting a number which when be divide by 1 second gives us a whole(int) number, thus; selecting 50000.
when dividing the required time by Compare match time == (1) / (500000 * 10(pow)-6) == 20.
Thus, ISR of Comp Match A is needed to be accessed 20 times to increment 1 second in real time.

//Configuration of EXt pins:
Pins are set to be OUTPUT with PULLUP,, sensing FALLING EDGE to activate.
