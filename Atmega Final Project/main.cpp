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

int main(void)
{
	LCD lcd;					// Khoi tao LCD
	DHT11 dht11(DHT_INPUTPIN);	// Khoi tao DHT
	
	uint8_t temperature, humidity;
	char data[5];

	lcd.Init();

	while (1)
	{
		lcd.Clear();
		lcd.SetCursor(1,1);
		lcd.Print("Temp:");
		lcd.SetCursor(2,1);
		lcd.Print("Humi:");
		
		dht11.Calculate();
		temperature = dht11.GetTemperature();
		humidity = dht11.GetHumidity();
		
		
		itoa(temperature, data, 10);
		lcd.SetCursor(1, 6);
		lcd.Print(data);
		
		itoa(humidity, data, 10);
		lcd.SetCursor(2, 6);
		lcd.Print(data);
		
		_delay_ms(1000);
	}
}

