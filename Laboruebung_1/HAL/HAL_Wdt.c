/*
 * HAL_Wdt.c
 *
 *  Created on: 02.10.2018
 *      Author: reibensc17
 */


#include <msp430.h>


void HAL_Wdt_Init()
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

}


