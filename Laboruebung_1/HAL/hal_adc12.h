/*
 * hal_adc12.h
 *
 *  Created on: 28.11.2018
 *      Author: reibensc17
 */

#ifndef HAL_ADC12_H_
#define HAL_ADC12_H_

void HAL_ADC12_Init(void);



typedef struct {

    union{
        unsigned char R;
        struct {
            unsigned char ADCrdy:1; //Bit = 1 wenn Daten übertragen wurden
            unsigned char dummy:7;
        }B;
    }Status;

    unsigned short SensorLeft;
    unsigned short SensorRight;
    unsigned short SensorFront;
    unsigned short SensorVBat;

}ADC12Com;

#endif /* HAL_ADC12_H_ */
