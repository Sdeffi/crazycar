/*
 * hal_usbciB1.c
 *
 *  Created on: 29.10.2018
 *      Author: reibensc17
 */

#include <msp430.h>
#include "hal_usbciB1.h"
#include "hal_gpio.h"
#include "hal_general.h"

extern USCIB1_SPICom transmit;
//extern ADC12Com sensor_x;

void HAL_USCIB1_Init(void)
{
    UCB1CTL1 |= UCSWRST; // software reset enable

    UCB1CTL0 = 0; // Clear all bits first
    UCB1CTL0 |= UCSYNC; // Sync-Mode 1:SPI-Mode
    UCB1CTL0 |= UCMST; // Master Mode
    UCB1CTL0 |= UCMSB; // MSB first
    UCB1CTL0 |= UCCKPL; // Clock Polarity: 1
    UCB1CTL0 &= ~UCCKPH; // Clock Phase: 0
    UCB1CTL0 &= ~UC7BIT; // 8 bit

    UCB1CTL1 |= UCSSEL_2;  // Source = submaster clk
    UCB1BR0 = (2500 / CLK_FREQUENZY_KHZ);   // USCBR = 25 = 2.5 MHz / 100 kHz
    UCB1BR1 = 0;

    LCD_CS_HIGH;
    UCB1CTL1 &= ~UCSWRST; // software reset disable
    UCB1IE |= UCRXIE; //Rx interrupt enable
    transmit.Status.B.TxSuc = 1;
}


void HAL_USCIB1_Transmit(void)
{
    LCD_CS_LOW;
    __delay_cycles(100);

    transmit.Status.B.TxSuc = 0;

    transmit.TxData.cnt = 0;
    transmit.RxData.len = 0;

    UCB1TXBUF = transmit.TxData.Data[transmit.TxData.cnt];
}

#pragma vector= USCI_B1_VECTOR
__interrupt void ISR_USCI_B1_VECTOR(void)
{
    if(UCB1IV == 2) //if RX buffer full
    {
        transmit.RxData.Data[transmit.RxData.len]= UCB1RXBUF;
        transmit.RxData.len ++;
        transmit.TxData.cnt ++;

        if(transmit.TxData.cnt < transmit.TxData.len)
        {
            UCB1TXBUF = transmit.TxData.Data[transmit.TxData.cnt]; //Using TX buffer to send
        }
        else
        {
            __delay_cycles(100);
            LCD_CS_HIGH;
            transmit.Status.B.TxSuc = 1;
        }
    }
}

