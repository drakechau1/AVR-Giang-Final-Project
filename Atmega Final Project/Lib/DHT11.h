/*
* DHT11.h
*
* Created: 6/17/2021 11:29:41 PM
* Author: duc
*/


#ifndef __DHT11_H__
#define __DHT11_H__

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>

#define DHT_DDR DDRD
#define DHT_PORT PORTD
#define DHT_PIN PIND


class DHT11
{
private:
	uint8_t DHT_INPUTPIN;
	void Request();
	void Response();
	bool Checksum(uint8_t buffer[]);

public:
	uint16_t Temperature, Humidity;

	DHT11();
	DHT11(uint8_t dht_inputPin);
	~DHT11();
	void Calculate();
};

#endif
