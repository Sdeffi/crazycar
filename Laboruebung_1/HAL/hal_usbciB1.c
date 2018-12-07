/*
 * hal_usbciB1.c
 *
 *  Created on: 29.10.2018
 *      Author: reibensc17
 */

#include <msp430.h>
#include "hal_usbciB1.h"
#include "hal_gpio.h"

extern USCIB1_SPICom SPI_Display_var;

void HAL_USCIB1_Init(void)
{

    UCB1CTL1 |= UCSWRST; // software reset enable

    UCB1IE |= UCRXIE; // RX Interrupt enable

    UCB1CTL0 &= ~UCCKPH; // Clock Phase: 0
    UCB1CTL0 |= UCCKPL; // Clock Polarity: 1
    UCB1CTL0 |= UCMSB; // MSB first
    UCB1CTL0 &= ~UC7BIT; // 8 bit
    UCB1CTL0 |= UCMST; // Master Mode

    UCB1CTL1 |= UCSSEL_3;  // Source = submaster clk

    UCB1BR0 = 25;   // USCBR = 25 = 2.5 MHz / 100 kHz
    UCB1BR1 = 0;


    UCB1CTL1 &= ~UCSWRST; // software reset disable

}


void HAL_USCIB1_Transmit(void)
{
    LCD_CS_LOW;

    SPI_Display_var.TxData.cnt = 0;

    UCB1TXBUF = SPI_Display_var.TxData.Data[SPI_Display_var.TxData.cnt];
}

#pragma vector= USCI_B1_VECTOR
__interrupt void ISR_USCI_B1_VECTOR(void){
    LCD_CS_HIGH;

    if(SPI_Display_var.TxData.cnt < SPI_Display_var.TxData.len){


    }





}

