/*
 * hal_usbciB1.h
 *
 *  Created on: 29.10.2018
 *      Author: reibensc17
 */

#define CLK_FREQUENZY 100000

#ifndef HAL_USBCIB1_H_
#define HAL_USBCIB1_H_

void HAL_USCIB1_Init(void);
void HAL_USCIB1_Transmit(void);


typedef struct {

    union{
        unsigned char R;
        struct {
            unsigned char TxSuc:1; //Bit 1 wenn Daten übertragen worden sind
            unsigned char dummy:7;
        }B;

    }Status;

    struct {
        unsigned char len; // Länge der Daten in Bytes die übertragen werden
        unsigned char cnt; //Index auf momentan übertragene Daten
        unsigned char Data[256]; // Tx Daten Array

    }TxData;

    struct {
        unsigned char len; //Länge der empfangenen Daten
        unsigned char Data[265]; // Rx Daten Array

    }RxData;
}USCIB1_SPICom;


#endif /* HAL_USBCIB1_H_ */

