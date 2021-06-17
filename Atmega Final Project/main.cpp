/*
* Atmega Final Project.cpp
*
* Created: 6/17/2021 1:26:45 AM
* Author : duc
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <avr/io.h>
#include "Lib/LCD.h"
#include "Lib/DHT11.h"

int main(void)
{
	LCD lcd;	// Khoi tao LCD

	lcd.Init();
	lcd.Clear();

	lcd.MoveCursor(1,5);
	lcd.Print("Hello");

	while (1)
	{
		
	}
}

