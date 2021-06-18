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

#define DHT_INPUTPIN 7
#define ADC_CHANNEL  0


int main(void)
{
	LCD lcd;					// Create LCD
	DHT11 dht11(DHT_INPUTPIN);	// Create DHT
	MQ135 mq135(ADC_CHANNEL);	// Create MQ135
	
	uint8_t temperature, humidity;
	int ppm;
	char data[5];

	// Init functions
	lcd.Init();
	mq135.Init();
	
	while (1)
	{
		lcd.Clear();
		
		lcd.SetCursor(1, 1);
		lcd.Print("PPM:");
		
		//ppm = mq135.GetPPM();
		ppm = mq135.GetPPM();
		
		
		itoa(ppm, data, 10);
		lcd.SetCursor(1, 6);
		lcd.Print(data);
		
		_delay_ms(1000);
	}
}
