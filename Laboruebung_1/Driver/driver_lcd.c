/*
 * driver_lcd.c
 *
 *  Created on: 07.11.2018
 *      Author: reibensc17
 */
#include "driver_lcd.h"
#include "font_table.h"
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
    unsigned char msb_col = col >> 4;
    unsigned char lsb_col = col & 0x0F;

    unsigned char setpos_cmds[3];
    setpos_cmds[0] = SET_PAGE | page;
    setpos_cmds[1] = MSB_COL_ADDR | msb_col;
    setpos_cmds[2] = LSB_COL_ADDR | lsb_col;

    Driver_LCD_WriteCommand(setpos_cmds, 3);
    while(transmit.Status.B.TxSuc == 0);
}

void Driver_LCD_WriteChar(unsigned char writeChar, unsigned char page, unsigned char col)
{
    Driver_LCD_SetPosition(page, col);

    LCD_DATA;
    unsigned char i;
    for(i=0; i<6; i++)
    {
       transmit.TxData.Data[i] = font_table[writeChar][i];
    }
    transmit.TxData.len = 6; //Each character consists of 6 subelements in the font_table
    HAL_USCIB1_Transmit();
    while(transmit.Status.B.TxSuc == 0);
}

void Driver_LCD_WriteText(unsigned char* text, unsigned char len, unsigned char page, unsigned char col)
{
    unsigned int i;
    for(i=0; i<len; i++)
    {
        Driver_LCD_WriteChar(text[i], page, col+(i*6));
    }
}

void Driver_LCD_WriteUInt(unsigned int num, unsigned char page, unsigned char col)
{

    unsigned char cnt =6;
    unsigned char num_str[7] = {0};

    while(num > 0)
    {
        num_str[cnt] = num %10 + '0';
        num = num/10;
        cnt --;
    }


    Driver_LCD_WriteText(num_str,6,page,col);
}

void Driver_LCD_Clear(void)
{
    unsigned char page;

    for(page=0; page<8; page++)
    {
        Driver_LCD_SetPosition(page, 0);

        LCD_DATA;
        unsigned char i;
        for(i=0; i<128; i++)
        {
           transmit.TxData.Data[i] = 0;
        }
        transmit.TxData.len = 128; //Each page has 128 columns
        HAL_USCIB1_Transmit();
    }
}
