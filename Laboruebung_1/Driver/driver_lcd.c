/*
 * driver_lcd.c
 *
 *  Created on: 07.11.2018
 *      Author: reibensc17
 */
#include "driver_lcd.h"
#include <msp430.h>
#include "HAL/hal_usbciB1.h"
#include "HAL/hal_gpio.h"

extern USCIB1_SPICom transmit;


void Driver_LCD_WriteCommand(unsigned char *data, unsigned char data_length)
{
    unsigned char i;
    while(transmit.Status.B.TxSuc == 0);
    LCD_COMMAND;
    for(i=0; i<data_length; i++)
    {
        transmit.TxData.Data[i]= *data;
        data++;
    }
    transmit.TxData.len = data_length;
    transmit.TxData.cnt = 0;
    HAL_USCIB1_Transmit();
}


void Driver_LCD_Init()
{
   unsigned char reset_cmds[9] = {LCD_RST, LCD_BIAS, ADC_SEL_NORMAL, COMMON_RESERVE, RES_RATIO, ELEC_VOL_MODE, ELEC_VOL_VALUE, POWER_CONT, DISPLAY_ON};

   LCD_ON;

   LCD_RESET_LOW;
   __delay_cycles(500000);
   LCD_RESET_HIGH;

   Driver_LCD_WriteCommand(reset_cmds,9);
   while(transmit.Status.B.TxSuc == 0);
}

void Driver_LCD_SetPosition(unsigned char page, unsigned char col)
{

}
