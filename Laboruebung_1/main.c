#include <msp430.h>
#include "HAL/hal_general.h"
#include "HAL/hal_gpio.h"
#include "HAL/hal_ucs.h"
#include "HAL/hal_timerB0.h"
#include "HAL/hal_timerA1.h"
#include "HAL/hal_usbciB1.h"
#include "Driver/driver_general.h"
#include "Driver/driver_aktorik.h"


/**
 * main.c
 */
extern ButtonCom pushed;
extern USCIB1_SPICom transmit;


void main(void)
{


	HAL_Init();
	Driver_Init();

	/*while(1)
	{
	    Driver_SetSteering(-100);
	    Driver_SetThrottle(50);
	}*/



}
