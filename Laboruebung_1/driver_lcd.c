/*
 * driver_lcd.c
 *
 *  Created on: 07.11.2018
 *      Author: reibensc17
 */
#include "driver_lcd.h"
#include <msp430.h>
#include "hal_usbciB1.h"
#include "hal_gpio.h"

extern USCIB1_SPICom transmit;

void Driver_LCD_WriteCommand(unsigned char *data, unsigned char data_length)
{
    unsigned char i;
    while(transmit.Status.B.TxSuc == 0);
    LCD_COMMAND;
    for(i=0; i<data_length; i++)
    {
        transmit.TxData.Data[i] = *data;
        data++;
    }
    transmit.TxData.len = data_length;
    transmit.TxData.cnt = 0;
    HAL_USCIB1_Transmit();
}


void Driver_LCD_Init()
{
    unsigned char reset_cmds[9] = {LCD_RST, LCD_BIAS, ADC_SEL_NORMAL, COMMON_RESERVE, RES_RATIO, ELEC_VOL_MODE, ELEC_VOL_VALUE, POWER_CONT, DISPLAY_ON};

    P9OUT &= ~LCD_RESET;
    __delay_cycles(100000);  //wait
    P9OUT |= LCD_RESET;

    Driver_LCD_WriteCommand(reset_cmds,
           sizeof(reset_cmds)/sizeof(unsigned char));
    while(transmit.Status.B.TxSuc == 0)
        ;
    //__delay_cycles(100000);

}


void Driver_LCD_Clear()
{
    unsigned char clear_cmd;

    unsigned char page;

    for(page = 0; page < NO_PAGES; page++)
    {


    }


}




