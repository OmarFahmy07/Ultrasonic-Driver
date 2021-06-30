/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Oct 10, 2020
 *      Author: Omar Fahmy
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/************************************************************************************/
/* 								FUNCTIONS PROTOTYPE					 				*/
/************************************************************************************/

/************************************************************************************/
/* Description: initializes the ultrasonic sensor			  						*/
/* Input      : nothing 		                                                    */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 Ultrasonic_U8Init(void);
/************************************************************************************/

/************************************************************************************/
/* Description: returns the distance read by the ultrasonic in centimeters			*/
/* Input      : pointer to a variable to receive the value in                       */
/* Output     : error checking                                                      */
/************************************************************************************/
extern u8 Ultrasonic_U8GetDistance(f64* const LOC_F64Distance);
/************************************************************************************/

#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
