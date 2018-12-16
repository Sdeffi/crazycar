/*
 * driver_lcd.h
 *
 *  Created on: 07.11.2018
 *      Author: reibensc17
 */



#ifndef DRIVER_LCD_H_
#define DRIVER_LCD_H_

void Driver_LCD_WriteCommand(unsigned char *data, unsigned char data_length);
void Driver_LCD_Init(void);

#define LCD_DATA (P8OUT |= (P8OUT|LCD_DATACMD))
#define LCD_COMMAND (P8OUT |= (P8OUT&~LCD_DATACMD))

#define SET_PAGE 0xB0
#define LAST_PAGE 0xB7
#define MSB_COL_ADDR 0x10
#define LSB_COL_ADDR 0x00
#define NO_PAGES 8
#define NO_COLUMS 132



#define LCD_RST 0xE2
#define LCD_BIAS 0xA3
#define ADC_SEL_NORMAL 0xA0
#define COMMON_RESERVE 0xC8
#define RES_RATIO 0x24
#define ELEC_VOL_MODE 0x81
#define ELEC_VOL_VALUE 0x0F //Kontrast Einstellung
#define POWER_CONT 0x2F
#define DISPLAY_ON 0xAF





#endif /* DRIVER_LCD_H_ */
