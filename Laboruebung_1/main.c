#include <msp430.h> 
#include "hal_general.h"
#include "hal_gpio.h"
#include "hal_ucs.h"
#include "hal_timerB0.h"
#include "hal_timerA1.h"
#include "Driver/driver_general.h"
#include "Driver/driver_aktorik.h"
#include "hal_usbciB1.h"

/**
 * main.c
 */

extern USCIB1_SPICom SPI_Display_var;


void main(void)
{


	HAL_Init();
	Driver_Init();

	while(1)
	{
	    Driver_SetSteering(0);
	    Driver_SetThrottle(50);
	}



}
