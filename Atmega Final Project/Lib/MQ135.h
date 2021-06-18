/*
* MQ135.h
*
* Created: 6/18/2021 2:25:00 PM
* Author: duc
*/


#ifndef __MQ135_H__
#define __MQ135_H__

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

/// Parameters for calculating ppm from sensor resistance
#define PARA 116.6020682
#define PARB 2.769034857
#define ATMOCO2 412.55		// Atmospheric CO2 level for calibration purposes. As of September 2020 https://www.co2.earth/
#define RLOAD 22.0			//Resistor put on the MQ135 instead of original 1K its now 22K
#define RZERO 60.52

// Macros
#define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

class MQ135
{
	private:
	uint8_t channel;
	uint16_t ReadADC();
	public:
	MQ135();
	MQ135(uint8_t channel);
	~MQ135();
	void Init();
	int GetResistance();
	int GetRZero();
	int GetPPM();
	
};

#endif //__MQ135_H__
