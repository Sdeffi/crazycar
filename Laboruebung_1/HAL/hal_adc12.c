/*
 * hal_adc12.c
 *
 *  Created on: 28.11.2018
 *      Author: reibensc17
 */
#include <msp430.h>
#include "hal_adc12.h"

extern ADC12Com ADC_Sensor;

void HAL_ADC12_Init(void)
{

    REFCTL0 &= ~REFMSTR; // to adjust reference voltage
    //REFCTL0 |= REFVSEL_3; // 2.5V (generator)
    //REFCTL0 = REFON | REFOUT;

    ADC12CTL0 &= ~ADC12ENC; // turn off to do ADC setup

    ADC12CTL0 = ADC12SHT0_15 | ADC12MSC | ADC12REF2_5V | ADC12REFON | ADC12ON ; //msc: multiple sample and conversation      ;1024 ADC12CLK cycles

    //
    // shs: triggering on our own timerB
    // shp: sample and hold pulse mode: rising edge
    // ssel: sm clock
    // conseq: repeat sequence of channels

    ADC12CTL1 = ADC12CSTARTADD_0 | ADC12SHS_0 | ADC12SHP | ADC12DIV_0 | ADC12SSEL_3 | ADC12CONSEQ_1;

    ADC12CTL2 = ADC12TCOFF | ADC12RES_2 | ADC12SR | ADC12REFBURST; //ref: 12 bit, sr: low sample rate, burst: turn off ref only during sample and conv.





    ADC12MCTL0 = ADC12SREF_1 | ADC12INCH_0; // end of sequence
    ADC12MCTL1 = ADC12SREF_1 | ADC12INCH_1;
    ADC12MCTL2 = ADC12SREF_1 | ADC12INCH_2;
    ADC12MCTL3 = ADC12SREF_1 | ADC12INCH_3 | ADC12EOS;  //eos -> end of sequence
    // Not enabled, DMA transfer

    ADC12IE = (1 << 3); // Enable interrupt on ADC12IFG3

    ADC12CTL0 |= ADC12ENC;  //starting conversation enable

}

#pragma vector = ADC12_VECTOR // ADC12 IV
__interrupt void ADC12_ISR(void)
{

    switch(ADC12IV)
    {
    case 0: break;  //no interrupt
    case 2: break;  //ADC overflow
    case 4: break;  //ADC timing overflow
    case 6: //ADC12IFG0
    case 8: //ADC12IFG1
    case 10: //ADC12IFG2
    case 12: //ADC12IFG3
       ADC_Sensor.SensorRight = ADC12MEM0;
       ADC_Sensor.SensorLeft = ADC12MEM1;
       ADC_Sensor.SensorFront = ADC12MEM2;
       ADC_Sensor.SensorVBat = ADC12MEM3;
       ADC_Sensor.Status.B.ADCrdy = 1;
        break;
    case 14: break; //ADC12IFG4
    case 16: break; //ADC12IFG5
    case 18: break; //ADC12IFG6
    case 20: break; //ADC12IFG7
    case 22: break; //ADC12IFG8
    case 24: break; //ADC12IFG9
    case 26: break; //ADC12IFG10
    case 28: break; //ADC12IFG11
    case 30: break; //ADC12IFG12
    case 32: break; //ADC12IFG13
    case 34: break; //ADC12IFG14
    case 36: break; //ADC12IFG15
    default: break;
    }

}







