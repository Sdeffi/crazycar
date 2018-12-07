#include <msp430.h> 
#include "hal_general.h"
#include "hal_gpio.h"
#include "hal_ucs.h"
#include "hal_timerB0.h"
#include "hal_timerA1.h"
#include "Driver/driver_general.h"
#include "Driver/driver_aktorik.h"

/**
 * main.c
 */

extern ADC12Com sensor_x;


void main(void)
{


	HAL_Init();
	Driver_Init();

	while(1)
	{
	    Driver_SetSteering(100);
	    Driver_SetThrottle(-100);
	}
/*
	
    float x = 7.351;
    float y = 3.012;
    float z = 0.0;

    int a = 5;
    int b = 9;
    int c = 0;

	while(1)
	{
	    LCD_ON;
	    c = a * b; //38 us
	    LCD_OFF;

	    LCD_ON;
	    z = x * y;  //348.0 us
	    LCD_OFF;
	}
*/



}
