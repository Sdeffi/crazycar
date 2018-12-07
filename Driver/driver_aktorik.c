/*
 * driver_aktorik.c
 *
 *  Created on: 28.10.2018
 *      Author: reibensc17
 */

#include <msp430.h>
#include "driver_aktorik.h"
#include "hal_timerA1.h"


volatile unsigned impulses = 0;


void Driver_SetSteering(int perc)
{
    TA1CCR2 = STEERING_MIDDLE + 10 * perc;

}


void Driver_SteeringInit()
{
    Driver_SetSteering(0);
}

void Driver_SetThrottle(int throttle)
{
    TA1CCR1 =  THROTTLE_STOP + 250 * throttle;
}

void Driver_ThrottleInit()
{
    TA1CCR1 = THROTTLE_BW_MAX;
    TA1CCTL0 = CCIE; //enable impulse counter interrupt
    impulses = 0;
    while(impulses < 140)
        ;

    TA1CCR1 = THROTTLE_BW_MIN;
    impulses = 0;
    while(impulses < 140)
        ;

    TA1CCR1 = THROTTLE_FW_MIN;
    impulses = 0;
    while(impulses < 140)
        ;

    TA1CCR1 = THROTTLE_FW_MAX;
    impulses = 0;
    while(impulses < 140)
        ;

    TA1CCR1 = THROTTLE_STOP;
    impulses = 0;
    while(impulses < 2)
        ;
    TA1CCTL0 &= ~CCIE; //disable impulse counter interrupt
    TA1CCR1 = 0;
}
