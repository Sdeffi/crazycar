/*
 * hal_adc12.h
 *
 *  Created on: 28.11.2018
 *      Author: reibensc17
 */

#ifndef HAL_ADC12_H_
#define HAL_ADC12_H_

void HAL_ADC12_Init(void);



#endif /* HAL_ADC12_H_ */

typedef struct {

    union{
        unsigned char R;
        struct {
            unsigned char ADCrdy:1; //Bit = 1 wenn Daten übertragen wurden
            unsigned char dummy:7;
        }B;
    }Status;

    unsigned short ADCBuffer[4];        //Speicherplatz der ADC werte

/*   Oder:
    unsigned short SensorLeft;
    unsigned short SensorRight;
    unsigned short SensorFront;
    unsigned short VBat;
*/
}ADC12Com;
