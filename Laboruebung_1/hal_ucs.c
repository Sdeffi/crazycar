/*
 * hal_ucs.c
 *
 *  Created on: 24.10.2018
 *      Author: reibensc17
 */

#include <msp430.h>

void HAL_UCS_Init()
{
    UCSCTL6 &= ~XT2OFF; //auf 0 setzen -> einschalten
    UCSCTL3 |= SELREF_2; //FFL auf REFOCLK referenz clock
    UCSCTL4 |= SELA_2; //ACLK auf REFOCLK setzen

    while(SFRIFG1 & OFIFG) //warten bis alle Fehler Flags nicht mehr gesetzt werden
    {
        UCSCTL7 &= ~(XT2OFFG + DCOFFG + XT1HFOFFG + XT1LFOFFG);
        SFRIFG1 &= ~OFIFG;
    }

    UCSCTL6 |= XT2DRIVE_2;
    UCSCTL4 |= SELS_5;
    UCSCTL4 |= SELM_5;
    UCSCTL5 |= DIVS_3;
}


