/*
 * driver_general.c
 *
 *  Created on: 28.10.2018
 *      Author: reibensc17
 */
#include <msp430.h>
#include "driver_general.h"
#include "Driver/driver_aktorik.h"
#include "driver_lcd.h"


void Driver_Init()
{
    //Driver_SteeringInit();
    //Driver_ThrottleInit();
    Driver_LCD_Init();

}


