/*
 * Ultrasonic_Program.c
 *
 *  Created on: Oct 10, 2020
 *      Author: Omar Fahmy
 */

/* LIB LAYER */
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
/* HAL LAYER */
#include "Ultrasonic_Private.h"
#include "Ultrasonic_Configure.h"
/* MCAL LAYER */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer1/Timer1_Interface.h"
#include "../../MCAL/Global Interrupt/GI_Interface.h"
/* DELAY LIBRARY */
#include <util/delay.h>

/************************************************************************************/
/* 						  PUBLIC FUNCTIONS IMPLEMENTATION  							*/
/************************************************************************************/

u16 GLOB_U16NumOfOverflows;

u8 Ultrasonic_U8Init(void)
{
#if TRIGGER_PORT >= DIO_PORTA && TRIGGER_PORT <= DIO_PORTD
#if TRIGGER_PIN >= DIO_PIN0 && TRIGGER_PIN <= DIO_PIN7
#if TIMER1_PRESCALER == NO_PRESCALER || TIMER1_PRESCALER == PRESCALER_8 || \
	TIMER1_PRESCALER == PRESCALER_64 || TIMER1_PRESCALER == PRESCALER_256 || \
	TIMER1_PRESCALER == PRESCALER_1024
	Timer1_U8Init();
	DIO_U8SetPinDirection(TRIGGER_PORT, TRIGGER_PIN, DIO_PIN_OUTPUT);
	Timer1_U8EnableOVFInterrupt();
	Timer1_U8OVFSetCallBack(Ultrasonic_VidTimer1OVFISR);
	GI_U8Enable();
#else
#error "Invalid timer1 prescaler for ultrasonic sensor"
#endif
#else
#error "Invalid trigger pin configuration"
#endif
#else
#error "Invalid trigger port configuration"
#endif
	return NO_ERROR;
}

u8 Ultrasonic_U8GetDistance(f64* const LOC_F64Distance)
{
	if (LOC_F64Distance != NULL)
	{
		u16 LOC_U16Temp;
		u64 LOC_U64Counts;
		/* Give 10 us trigger pulse on trigger pin */
		DIO_U8SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_PIN_HIGH);
		_delay_us(10);
		DIO_U8SetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_PIN_LOW);
		/* Capture on rising edge */
		Timer1_U8ICEdgeSelect(TIMER1_RISING_EDGE);
		/* wait for a rising edge */
		Timer1_U8CaptureEventPollingOnFlag();
		/* Clear Timer counter */
		Timer1_U8Preload(CLEAR);
		/* Capture on falling edge */
		Timer1_U8ICEdgeSelect(TIMER1_FALLING_EDGE);
		/* Clear Timer overflow count */
		GLOB_U16NumOfOverflows = CLEAR;
		/* wait for a falling edge */
		Timer1_U8CaptureEventPollingOnFlag();
		/* Get the captured value */
		Timer1_U8GetCapturedValue(&LOC_U16Temp);
		/* Get the total counts */
		LOC_U64Counts = LOC_U16Temp + TIMER1_RESOLUTION * GLOB_U16NumOfOverflows;
		/* Get the distance travelled by sound waves */
		*LOC_F64Distance = HALF_THE_TIME * SPEED_OF_LIGHT * LOC_U64Counts * \
		TIMER1_PRESCALER * CONVERT_TO_CM/ CLOCK_FREQUENCY;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}
/************************************************************************************/


/************************************************************************************/
/* 						  PRIVATE FUNCTIONS IMPLEMENTATION  						*/
/************************************************************************************/

void Ultrasonic_VidTimer1OVFISR(void)
{
	GLOB_U16NumOfOverflows++;
}
/************************************************************************************/
