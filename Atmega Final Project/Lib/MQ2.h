/*
* MQ2.h
*
* Created: 6/19/2021 12:56:49 PM
* Author: duc
*/

// Reference:
//		https://github.com/labay11/MQ-2-sensor-library
//		http://www.hocavr.com/2018/06/bai-6-chuyen-oi-adc.html

#ifndef __MQ2_H__
#define __MQ2_H__

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

# define RL_VALUE 5.0				// define the load resistance on the board, in kilo ohms
# define RO_CLEAN_AIR_FACTOR 9.83	// given constant

// reads 10 times the sensor every 50ms and takes the average
# define CALIBARAION_SAMPLE_TIMES 10
# define CALIBRATION_SAMPLE_INTERVAL 50

// reads 5 times the sensor every 50ms and takes the average
# define READ_SAMPLE_TIMES 5
# define READ_SAMPLE_INTERVAL 50

// VREF ADC MODE
#define AREF_MODE 0
#define AVCC_MODE (1<<REFS0)
#define INT_MODE (1<<REFS0)|(1<<REFS1)
#define ADC_VREF_TYPE AVCC_MODE

class MQ2
{
	private:
	uint8_t adc_channel;
	float Ro;

	float MQRead();
	float MQCalibration();
	float MQResistanceCalculation(int raw_adc);
	bool CheckCalibration();
	
	public:
	MQ2();
	MQ2(uint8_t mq2_inputpin);
	~MQ2();
	void Init();
	void Close();
	float GetLPG();
	float GetCO();
	float GetSmoke();
	float GetRo();
	uint16_t ReadADC();
	
};

#endif //__MQ2_H__
