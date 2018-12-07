/*
 * hal_timerA1.c
 *
 *  Created on: 25.10.2018
 *      Author: reibensc17
 */

#include "hal_timerA1.h"
#include <msp430.h>
#include "hal_gpio.h"


void HAL_TimerA1_Init()
{
    TA1CTL = 0x00;
    TA1CTL |= MC_1; //UP MODE
    TA1CTL |= TASSEL_2;  //Quelle = Submaster clk

    TA1CCTL2 |= OUTMOD_7;   //Reset/Set
    TA1CCTL1 |= OUTMOD_7;   //Reset/Set

    TA1CCTL0 &= ~CAP; // compare mode

    TA1CCR0 = 41667;
    TA1CCR1 = 10000;
    TA1CCR2 = 0;



}

extern volatile unsigned impulses;

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1A0_ISR(void)
{
    impulses++;
}

