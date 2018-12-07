/*
 * driver_aktorik.h
 *
 *  Created on: 28.10.2018
 *      Author: reibensc17
 */

#ifndef DRIVER_DRIVER_AKTORIK_H_
#define DRIVER_DRIVER_AKTORIK_H_

#define STEERING_LEFT 2750
#define STEERING_MIDDLE 3750
#define STEERING_RIGHT 4750

#define THROTTLE_FW_MAX 10000
#define THROTTLE_FW_MIN 7500
#define THROTTLE_BW_MAX 2500
#define THROTTLE_BW_MIN 5000
#define THROTTLE_STOP 6250


void Driver_SetSteering(int perc);
void Driver_SteeringInit();

void Driver_SetThrottle(int throttle);
void Driver_ThrottleInit();



#endif /* DRIVER_DRIVER_AKTORIK_H_ */
