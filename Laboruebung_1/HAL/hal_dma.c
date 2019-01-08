/*
 * hal_dma.c
 *
 *  Created on: 07.01.2019
 *      Author: Steffi
 */

#include "HAL/hal_dma.h"
#include "HAL/hal_adc12.h"
#include <msp430.h>
#include "HAL/hal_usbciB1.h"
#include "HAL/hal_gpio.h"

extern ADC12Com ADC_Sensor;

void HAL_DMA_Init(void)
{
   DMA0CTL |= DMAEN; //DMA enable
   DMA0CTL &= ~ DMASRCBYTE; //transmit word
   DMA0CTL |= DMADSTINCR_3; //increment destination address
   DMA0CTL |= DMASRCINCR_3; //increment source address
   DMA0CTL &= ~ DMADSTBYTE; //word
   DMA0CTL &= ~ DMASRCBYTE; //word
   DMA0CTL |= DMAIE; //interrupt enable
   DMACTL0 |= DMA0TSEL_24;

   DMA0SA = &ADC12MEM0;
   DMA0DA = & ADC_Sensor.SensorRight;
   DMA0SZ = 4; //numer of words/bytes
}
/*
#pragma vector = DMA_VECTOR
__interrupt void DMA_ISR(void)
{

    ADC_Sensor.Status.B.ADCrdy = 1;
    ADC12CTL0 |= ADC12ENC; // turn off to do ADC setup
   // ADC12CTL0 &= ~ADC12ENC; // turn off to do ADC setup

}
*/
