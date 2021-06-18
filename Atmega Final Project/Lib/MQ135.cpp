/*
* MQ135.cpp
*
* Created: 6/18/2021 2:25:00 PM
* Author: duc
*/

// Reference: https://github.com/apassiou/mq135_atmega32


#include "MQ135.h"

uint16_t MQ135::ReadADC()
{
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */
	ADCSRA |= (1<<ADSC);			/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	_delay_us(10);
	return ADCW;					// Return ADC value
}

MQ135::MQ135()
{
	this->channel = 0;
}

MQ135::MQ135(uint8_t channel)
{
	this->channel = channel;
}

MQ135::~MQ135()
{
}

void MQ135::Init()
{
	DDRA = 0x00;		/* DDRA mode: input */
	ADCSRA = 0x87;		/* Enable ADC, fr/128  */
	ADMUX = 0x40;		/* Vref: Avcc, ADC channel: 0 */
}

int MQ135::GetResistance()
{
	uint16_t adcValue = ReadADC();
	float result = ((1023./(float)adcValue) - 1.)*RLOAD;
	return FLOAT_TO_INT(result);
}

int MQ135::GetRZero()
{
	float result = GetResistance() * pow((ATMOCO2/PARA), (1./PARB));
	return FLOAT_TO_INT(result);
}

int MQ135::GetPPM()
{
	float result = PARA * pow((GetResistance()/RZERO), -PARB);
	return FLOAT_TO_INT(result);
}
