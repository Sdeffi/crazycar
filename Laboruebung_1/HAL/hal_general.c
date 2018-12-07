
#include <msp430.h>


#include "hal_general.h"
#include "hal_pmm.h"
#include "HAL_Wdt.h"
#include "hal_gpio.h"
#include "hal_ucs.h"
#include "hal_usbciB1.h"
#include "hal_adc12.h"

//ButtonCom x;

USCIB1_SPICom SPI_Display_var;
ADC12Com ADC_Sensor;

void HAL_Init()
{
    HAL_Wdt_Init();
    HAL_PMM_Init();
    HAL_GPIO_Init();
    HAL_UCS_Init();
    HAL_TimerB0_Init();
    HAL_TimerA1_Init();
    __enable_interrupt();   //am Schluss
}