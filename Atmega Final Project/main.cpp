/*
* Atmega Final Project.cpp
*
* Created: 6/17/2021 1:26:45 AM
* Author : duc
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "Lib/LCD.h"
#include "Lib/DHT11.h"
#include "Lib/MQ135.h"
#include "Lib/MQ2.h"

#define DHT_INPUT_PIN	7
#define MQ135_INPUT_PIN	0
#define MQ2_INPUT_PIN	1

int main(void)
{
	LCD lcd;	// Create LCD
	DHT11 dht11(DHT_INPUT_PIN);		// Create DHT
	MQ135 mq135(MQ135_INPUT_PIN);	// Create MQ135
	MQ2 mq2(MQ2_INPUT_PIN);
	
	char data[5];

	// Init functions
	lcd.Init();
	mq135.Init();
	mq2.Init();

	while (1)
	{
		lcd.Clear();
		
		lcd.SetCursor(1, 1);
		lcd.Print("ADC:");
		
		itoa(mq2.ReadADC(), data, 10);
		lcd.SetCursor(1, 6);
		lcd.Print(data);
		
		lcd.SetCursor(2, 1);
		lcd.Print("CO:");
		
		itoa(abs((int)mq2.GetCO()), data, 10);
		lcd.SetCursor(2, 4);
		lcd.Print(data);
		
		_delay_ms(1000);
	}
}