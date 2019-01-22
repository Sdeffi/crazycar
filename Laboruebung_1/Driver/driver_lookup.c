/*
 * driver_lookup.c
 *
 *  Created on: 18.01.2019
 *      Author: Steffi
 */

#include <msp430.h>


#include "HAL/hal_general.h"
#include "HAL/hal_pmm.h"
#include "HAL/HAL_Wdt.h"
#include "HAL/hal_gpio.h"
#include "HAL/hal_ucs.h"
#include "HAL/hal_usbciB1.h"
#include "HAL/hal_adc12.h"
#include "HAL/hal_timerB0.h"
#include "HAL/hal_timerA1.h"
#include "DRIVER/driver_lookup.h"

extern ADC12Com ADC_Sensor;

int findSensorValueRight()
{
    int i= 0;
    while ((ADC_Sensor.SensorRight< LOOKUP_ADC_SIDE[i])&& i<200)
    {

        i++;
    }return LOOKUP_DISTANCE_SIDE[i];

}

int findSensorValueLeft()
{
    int i= 0;
    while ((ADC_Sensor.SensorLeft< LOOKUP_ADC_SIDE[i])&& i<200)
    {

        i++;
    }return LOOKUP_DISTANCE_SIDE[i];

}

int findSensorValueFront()
{
    int i= 0;
    while ((ADC_Sensor.SensorFront< LOOKUP_ADC_FRONT[i])&& i<200)
    {

        i++;
    }return LOOKUP_DISTANCE_FRONT[i];

}

