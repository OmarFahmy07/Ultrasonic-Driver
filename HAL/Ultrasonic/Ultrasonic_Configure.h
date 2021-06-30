/*
 * Ultrasonic_Configure.h
 *
 *  Created on: Oct 10, 2020
 *      Author: Omar Fahmy
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_CONFIGURE_H_
#define HAL_ULTRASONIC_ULTRASONIC_CONFIGURE_H_

/*****************************************************************************/
/*      					OPTIONS FOR TRIGGER PORT:			             */
/*       		DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD			     */
/*****************************************************************************/
#define TRIGGER_PORT				DIO_PORTA
/*****************************************************************************/


/*****************************************************************************/
/*      					OPTIONS FOR TRIGGER PIN:		                 */
/*       		   DIO_PIN0 - DIO_PIN1 - DIO_PIN2 - DIO_PIN3 			     */
/*       		   DIO_PIN4 - DIO_PIN5 - DIO_PIN6 - DIO_PIN7 			     */
/*****************************************************************************/
#define TRIGGER_PIN					DIO_PIN0
/*****************************************************************************/

/*****************************************************************************/
/* 						OPTIONS FOR TIMER1 PRESCALER 					 	 */
/*        		  NO_PRESCALER - PRESCALER_8 - PRESCALER_64	     			 */
/*	       				PRESCALER_256 - PRESCALER_1024 					 	 */
/*****************************************************************************/
#define TIMER1_PRESCALER			PRESCALER_8
/*****************************************************************************/

/*****************************************************************************/
/* 					 SYSTEM OSCILLATOR CLOCK FREQUENCY					 	 */
/*****************************************************************************/
#define CLOCK_FREQUENCY				8000000UL
/*****************************************************************************/


#endif /* HAL_ULTRASONIC_ULTRASONIC_CONFIGURE_H_ */
