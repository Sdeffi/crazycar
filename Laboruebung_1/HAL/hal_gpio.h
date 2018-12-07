/*
 * hal_gpio.h
 *
 *  Created on: 02.10.2018
 *      Author: reibensc17
 */



#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_





#endif /* HAL_GPIO_H_ */

void HAL_GPIO_Init();

#define RPM_SENSOR BIT3 //ein
#define RPM_SENSOR_DIR BIT4 //ein
#define I2C_INT_MOTION BIT5 //aus
#define START_BUTTON BIT6   //ein
#define STOP_BUTTON BIT7    //ein

// --- Port 2 ---

#define DEBUG_TXD BIT0  //ein
#define DEBUG_RXD BIT1  //aus
#define AUX_PIN_1 BIT2  //ein/aus
#define AUX_PIN_2 BIT3  //ein/aus
#define AUX_PIN_3 BIT4  //ein/aus
#define AUX_PIN_4 BIT5  //ein/aus
#define I2C_SDA_MOTION BIT6 //ein/aus
#define I2C_SCL_MOTION BIT7 //aus

// --- Port 3 ---

#define THROTTLE BIT2
#define STEERING BIT3
#define SMCLK BIT4  //ein
#define DISTANCE_FRONT_EN BIT7  //aus

// --- Port 4 ---

#define LINE_FOLLOW_2 BIT3  //ein
#define LINE_FOLLOW_1 BIT4  //ein
#define LINE_FOLLOW_3 BIT5  //ein
#define LINE_FOLLOW_4 BIT6  //ein
#define LINE_FOLLOW_5 BIT7  //ein

// --- Port 6 ---

#define DISTANCE_RIGHT BIT0  //ein
#define DISTANCE_LEFT BIT1  //ein
#define DISTANCE_FRONT BIT2  //ein
#define VBAT_MEASURE BIT3  //ein
#define DISTANCE_LEFT_EN BIT4  //aus

// --- Port 7 ---

#define XT2IN BIT2  //ein
#define XT2OUT BIT3 //aus

// --- Port 8 ---

#define LCD_BL BIT0 //aus
#define LCD_SPI_CS BIT1 //aus
#define UART_TXD_AUX BIT2 //aus
#define UART_RXD_AUX BIT3 //ein
#define LCD_SPI_CLK BIT4 //aus
#define LCD_SPI_MOSI BIT5 //aus
#define LCD_SPI_MISO BIT6 //ein
#define LCD_DATACMD BIT7 //aus

// --- Port 9 ---

#define LCD_RESET BIT0 //aus
#define DISTANCE_RIGHT_EN BIT7 //aus

// --- Makros ---

#define LCD_ON (P8OUT |= LCD_BL)
#define LCD_OFF (P8OUT &= ~LCD_BL)

#define LCD_CS_HIGH (P8OUT |= LCD_SPI_CS)
#define LCD_CS_LOW (P8OUT &= ~LCD_SPI_CS)


typedef struct {
    unsigned char active;    //TRUE 1 / FALSE 0
    unsigned char button;   //Button number
}ButtonCom;



