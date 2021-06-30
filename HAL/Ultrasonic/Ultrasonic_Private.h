/*
 * Ultrasonic_Private.h
 *
 *  Created on: Oct 10, 2020
 *      Author: Omar Fahmy
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_
#define HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_

/************************************************************************************/
/* 						   DISTANCE CALCULATION MACROS								*/
/************************************************************************************/
#define SPEED_OF_LIGHT					343UL
#define HALF_THE_TIME					0.5
#define TIMER1_RESOLUTION 				65536
#define CLEAR							0
#define CONVERT_TO_CM					100
/************************************************************************************/


/************************************************************************************/
/* 							  TIMER1 PRESCALERS 								    */
/************************************************************************************/
#define NO_PRESCALER					1
#define PRESCALER_8						8
#define PRESCALER_64					64
#define PRESCALER_256					256UL
#define PRESCALER_1024					1024UL
/************************************************************************************/


/************************************************************************************/
/* 						   PRIVATE FUNCTIONS PROTOTYPES								*/
/************************************************************************************/

/************************************************************************************/
/* Description: Interrupt Service Routine (ISR) for timer1 overflow			  	    */
/* Input      : nothing 		                                                    */
/* Output     : nothing		                                                        */
/************************************************************************************/
extern void Ultrasonic_VidTimer1OVFISR(void);
/************************************************************************************/

#endif /* HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_ */
