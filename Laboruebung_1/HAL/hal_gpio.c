/*
 * hal_gpio.c
 *
 *  Created on: 02.10.2018
 *      Author: reibensc17
 */

// --- Port 1 ---

#include <msp430.h>
#include "hal_gpio.h"



void HAL_GPIO_Init()
{
//*** Eingang / Ausgang ***
    P1DIR = 0xff;
    P1DIR &= ~RPM_SENSOR;
    P1DIR &= ~RPM_SENSOR_DIR;
    P1DIR &= ~START_BUTTON;
    P1DIR &= ~STOP_BUTTON;

    P1REN |= START_BUTTON;
    P1REN |= STOP_BUTTON;

    P2DIR = 0xff;
    P2DIR &= ~DEBUG_TXD;
    P2DIR &= ~AUX_PIN_1;
    P2DIR &= ~AUX_PIN_2; //Ein neuer Komentar
    P2DIR &= ~AUX_PIN_3;
    P2DIR &= ~AUX_PIN_4;
    P2DIR &= ~I2C_SDA_MOTION;

    P3DIR = 0xff;
    //P3DIR &= ~SMCLK;

    P3SEL |= SMCLK;
    P3SEL |= THROTTLE;
    P3SEL |= STEERING;

    P4DIR = 0xff;
    P4DIR &= ~LINE_FOLLOW_2;
    P4DIR &= ~LINE_FOLLOW_1;
    P4DIR &= ~LINE_FOLLOW_3;
    P4DIR &= ~LINE_FOLLOW_4;
    P4DIR &= ~LINE_FOLLOW_5;

    P5DIR = 0xff;

    P6DIR = 0xff;
    P6DIR &= ~DISTANCE_RIGHT;
    P6DIR &= ~DISTANCE_LEFT;
    P6DIR &= ~DISTANCE_FRONT;
    P6DIR &= ~VBAT_MEASURE;
    P6DIR |= DISTANCE_LEFT_EN;

    P7DIR = 0xff;
    P7SEL |= XT2IN;
    P7SEL |= XT2OUT;
    UCSCTL6 &= ~XT2BYPASS;


    P8DIR = 0xff;
    P8DIR &= ~UART_RXD_AUX;
    P8DIR &= ~LCD_SPI_MISO;

    P9DIR = 0xff;



// *** Interrupts ***

    P1IE = 0x00;
    /*
    P1IE |= START_BUTTON;
    P1IE |= STOP_BUTTON;

    P1IES |= START_BUTTON;
    P1IES |= STOP_BUTTON;
    */



}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
   P1OUT ^= BIT6;                        // Toggle P1.6
   P1IFG &=~BIT3;                        // P1.3 IFG cleared


}
