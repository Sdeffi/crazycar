
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


ButtonCom pushed;

USCIB1_SPICom transmit;
ADC12Com ADC_Sensor;

void HAL_Init()
{
    HAL_Wdt_Init();
    HAL_PMM_Init();
    HAL_GPIO_Init();
    HAL_UCS_Init();
    HAL_TimerB0_Init();
    HAL_TimerA1_Init();
    HAL_USCIB1_Init();
    __enable_interrupt();   //am Schluss
}
