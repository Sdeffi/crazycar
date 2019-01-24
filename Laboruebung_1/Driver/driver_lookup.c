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
//int sensor_value_front= 0;
//int sensor_value_left = 0;
char distance_right;
char distance_front;
char distance_left;


/*int findSensorValueRight()
{
    int i= 0;
    int sensor_value_right= 0;


    while ((ADC_Sensor.SensorRight< LOOKUP_ADC_SIDE[i])&& (i<200))
    {

        i++;
    }return LOOKUP_DISTANCE_SIDE[i];

    //sensor_value_right=LOOKUP_DISTANCE_SIDE[i];

}


int findSensorValueLeft()
{
    int i= 0;


    while ((ADC_Sensor.SensorLeft< LOOKUP_ADC_SIDE[i])&& i<200)
    {

        i++;
    }return LOOKUP_DISTANCE_SIDE[i];

    //sensor_value_left=LOOKUP_DISTANCE_SIDE[i];
}

int findSensorValueFront()
{
    int i= 0;


    while ((ADC_Sensor.SensorFront< LOOKUP_ADC_FRONT[i])&& i<200)
    {

        i++;
    }return LOOKUP_DISTANCE_FRONT[i];

    //sensor_value_front= LOOKUP_DISTANCE_FRONT[i];
}
*/
void find_sensor_distance ()
{
   char f_index = ADC_Sensor.SensorFront >> 4;
   char r_index = ADC_Sensor.SensorRight >> 4;
   char l_index = ADC_Sensor.SensorLeft >> 4;

   distance_front = LOOKUP_DISTANCE_FRONT[f_index];
   distance_left = LOOKUP_DISTANCE_L[l_index];
   distance_right = LOOKUP_DISTANCE_R[r_index];

}

