/*
 * hal_dma.c
 *
 *  Created on: 07.01.2019
 *      Author: Steffi
 */

#include "HAL/hal_dma.h"
#include <msp430.h>
#include "HAL/hal_usbciB1.h"
#include "HAL/hal_gpio.h"


void HAL_DMA_Init(void)
{
   DMA0CTL |= DMAEN; //DMA enable
   DMA0CTL &= ~ DMASRCBYTE; //transmit word
   DMA0CTL |= DMADSTINCR_3; //increment destination address
   DMA0CTL |= DMASRCINCR_3; //increment source address
   DMA0CTL &= ~ DMADSTBYTE; //word
   DMA0CTL &= ~ DMASRCBYTE; //word
   DMA0CTL |= DMAIE; //interrupt enable


   DMA0SA |= ADC12MEM0;
   DMA0TSEL_24

}
