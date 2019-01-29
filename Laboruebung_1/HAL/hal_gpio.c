/*
 * hal_gpio.c
 *
 *  Created on: 02.10.2018
 *      Author: reibensc17
 */

// --- Port 1 ---

#include <msp430.h>
#include "HAL/hal_gpio.h"
#include "HAL/hal_general.h"

extern ButtonCom pushed;
int go = 0;

void HAL_GPIO_Init()
{
//*** Eingang / Ausgang ***
    P1DIR = 0xff;
    P1DIR &= ~RPM_SENSOR;
    P1DIR &= ~RPM_SENSOR_DIR;
    P1DIR &= ~START_BUTTON;
    P1DIR &= ~STOP_BUTTON;

    P1REN |= START_BUTTON;      //Pullup/down enable
    P1REN |= STOP_BUTTON;

    P1IE |= START_BUTTON;
    P1IE |= STOP_BUTTON;    //Interrupt möglich
    P1IES |= START_BUTTON;
    P1IES |= STOP_BUTTON;// Flankentriggerung auf steigende Flanke

    P1OUT |= START_BUTTON;      //PULL UP
    P1OUT |= STOP_BUTTON;




    P2DIR = 0xff;
    P2DIR &= ~DEBUG_TXD;
    P2DIR &= ~AUX_PIN_1;
    P2DIR &= ~AUX_PIN_2;
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

    /* Use SPI block on these pins: */
    P8SEL |= LCD_SPI_CLK;
    P8SEL |= LCD_SPI_MOSI;
    P8SEL |= LCD_SPI_MISO;

    P9DIR = 0xff;

}

#pragma vector=PORT1_VECTOR
__interrupt void ISR_P1 (void)
{
    switch(P1IFG)
    {
    case START_BUTTON:
        //LCD_ON;    //LCD ein
        go = 1; //Startbutton gedrückt, losfahren
        P1IFG &= ~START_BUTTON;
        pushed.active = 1;
        pushed.button = 1;
        break;

    case STOP_BUTTON:
          //LCD_OFF; //LCD aus
         go = 0;    //Stoppbutton gedrückt, stehen bleiben
         P1IFG &= ~STOP_BUTTON;
         pushed.active = 1;
         pushed.button = 0;
         break;

    default:
        P1IFG = 0x00;
        break;
    }
}
/*#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
   P1OUT ^= BIT6;                        // Toggle P1.6
   P1IFG &=~BIT3;                        // P1.3 IFG cleared


}*/


