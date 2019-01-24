#include <msp430.h>
#include "HAL/hal_general.h"
#include "HAL/hal_gpio.h"
#include "HAL/hal_ucs.h"
#include "HAL/hal_timerB0.h"
#include "HAL/hal_timerA1.h"
#include "HAL/hal_usbciB1.h"
#include "HAL/hal_adc12.h"
#include "Driver/driver_general.h"
#include "Driver/driver_aktorik.h"
#include "Driver/driver_lcd.h"
#include "Driver/driver_lookup.h"

#define FULLSPEED_FW 50
#define MED_SPEED_FW 25
#define TURN_RIGHT 100
#define TURN_LEFT -100

//extern ButtonCom pushed;
//extern USCIB1_SPICom transmit;
extern ADC12Com ADC_Sensor;

extern unsigned char updateAdcDisplay;
char distance_left;
char distance_right;
char distance_front;

void main(void)
{


	HAL_Init();
	Driver_Init();





	while(1)
	{



	   if (distance_front >= 70)
	    {
	       Driver_SetSteering(0);
	       Driver_SetThrottle(15);
	    }
	   else if((distance_front <= 70)&& distance_front >=20)
	   {
	       Driver_SetThrottle(10);
	   }
	   else
	   {
	       Driver_SetThrottle(0);
	   }



	    if(updateAdcDisplay == 0)
	    {
	        updateAdcDisplay++;

            /* Print ADc values */
            //

	        unsigned char text[10] = "ADC";
            Driver_LCD_WriteText(text, sizeof(text), 0, 0);

            unsigned char textBat[3] = "Bat";
            Driver_LCD_WriteText(textBat, sizeof(textBat), 1, 0);

            unsigned char textFrt[3] = "Frt";
            Driver_LCD_WriteText(textFrt, sizeof(textFrt), 2, 0);

            unsigned char textRgt[3] = "Rgt";
            Driver_LCD_WriteText(textRgt, sizeof(textRgt), 3, 0);

            unsigned char textLft[3] = "Lft";
            Driver_LCD_WriteText(textLft, sizeof(textLft), 4, 0);

            /*Driver_LCD_WriteUInt(ADC_Sensor.SensorVBat, 1, 40);
            Driver_LCD_WriteUInt(ADC_Sensor.SensorFront, 2, 40);
            Driver_LCD_WriteUInt(ADC_Sensor.SensorRight, 3, 40);
            Driver_LCD_WriteUInt(ADC_Sensor.SensorLeft, 4, 40);*/

            find_sensor_distance ();

            Driver_LCD_WriteUInt(ADC_Sensor.SensorVBat, 1, 40);
            Driver_LCD_WriteUInt(distance_front, 2, 40);
            Driver_LCD_WriteUInt(distance_right, 3, 40);
            Driver_LCD_WriteUInt(distance_left, 4, 40);
	    }

	}



}
void find_sensor_distance ()
{
   char f_index = ADC_Sensor.SensorFront >> 4;
   char r_index = ADC_Sensor.SensorRight >> 4;
   char l_index = ADC_Sensor.SensorLeft >> 4;

   distance_front = LOOKUP_DISTANCE_FRONT[f_index];
   distance_left = LOOKUP_DISTANCE_L[l_index];
   distance_right = LOOKUP_DISTANCE_R[r_index];

}

