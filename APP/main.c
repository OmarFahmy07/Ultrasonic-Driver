/*
 * main.c
 *
 *  Created on: Oct 10, 2020
 *      Author: Omar Fahmy
 */

#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Ultrasonic/Ultrasonic_Interface.h"

int main(void)
{
	f64 distance;
	LCD_U8Init();
	Ultrasonic_U8Init();

	LCD_U8SendString("Dist. = ");
	LCD_U8SetPosition(LCD_FIRST_ROW, LCD_FIFTEENTH_COLUMN);
	LCD_U8SendString("cm");

	while(1)
	{
		Ultrasonic_U8GetDistance(&distance);
		LCD_U8SetPosition(LCD_FIRST_ROW, LCD_NINTH_COLUMN);
		LCD_U8SendNumber(distance);
	}
}
