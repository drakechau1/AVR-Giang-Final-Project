/*
* Atmega Final Project.cpp
*
* Created: 6/17/2021 1:26:45 AM
* Author : duc
*/


#define F_CPU 8000000UL

#include <avr/io.h>
#include "Lib/LCD.h"

int main(void)
{
	LCD lcd;	// Kh?i t?o LCD object

	lcd.Init();
	lcd.Clear();

	while (1)
	{
	}
}

