#pragma once
#include "Subject.hpp"
#include "Observer.hpp"

class WeatherData : public Subject
{
public:
	WeatherData() = default;

	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);
	float getTemperature()	const { return temperature; }
	float getHumidity()		const { return humidity; }
	float getPressure()		const { return pressure; }
private:
	float temperature = 0;
	float humidity	  = 0;
	float pressure	  = 0;
};

inline void WeatherData::measurementsChanged() 
{
	setChanged();
	notifyObservers();
}

inline void WeatherData::setMeasurements(float temperature, float humidity, float pressure) 
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged();
}