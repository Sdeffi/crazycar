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
    TB0CTL |= TBSSEL_2;
    TB0CTL |= ID_3;
    TB0CTL |= MC_1;

    TB0CCTL0 = 0x00;
    TB0CCTL0 &= ~CAP;
    TB0CCTL0 |= CCIE;

    TB0EX0 = 0x00;
    TB0EX0 |= TBIDEX_7;

    TB0CCR0 = 9766;

}

#pragma vector=TIMERB0_VECTOR
__interrupt void TimerB0(void)
{
   P8OUT ^= LCD_BL;
   TB0CCTL0 &= ~CCIFG;

}
