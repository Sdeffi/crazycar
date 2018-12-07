/*
 * hal_timerB0.c
 *
 *  Created on: 24.10.2018
 *      Author: reibensc17
 */
#include "hal_timerB0.h"
#include <msp430.h>
#include "hal_gpio.h"

void HAL_TimerB0_Init()
{
    TB0CTL = 0x00;
    TB0CTL |= TBSSEL_2; //SMCLK
    TB0CTL |= ID_3;     //   /4
    TB0CTL |= MC_1;     //Up mode
    TB0CTL |= TBCLR;    //TBR, the clock divider logic (the divider setting remains unchanged), and the count direction

    TB0CCTL0 = 0x00;
    TB0CCTL0 &= ~CAP;       //compare mode

    TB0CCTL1 |= OUTMOD_7;   //reset/set mode



    TB0EX0 = 0x0000;   //No exp. input divider

    TB0CCR0 = 10417;   //2.5MHz / 10417 = 240 Hz
    TB0CCR1 = 1; // short impulse used for trigger instead of interrupt

}

/*
#pragma vector=TIMERB0_VECTOR
__interrupt void TimerB0(void)
{
   P8OUT ^= LCD_BL;
   TB0CCTL0 &= ~CCIFG;

}
*/
