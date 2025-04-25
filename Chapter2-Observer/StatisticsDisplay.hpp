#pragma once

#include <iostream>
#include "Observer.hpp"
#include "Subject.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class StatisticsDisplay : 
	public Observer, DisplayElement {
public:
	StatisticsDisplay(WeatherData* weatherData)
							{ this->weatherData = weatherData;
							  weatherData->registerObserver(this); }
	~StatisticsDisplay() { weatherData->removeObserver(this); }
	void update(Subject *sbj) override;
	void display() override;
private:
	WeatherData* weatherData;
    float minTemp = 200.0f;
    float maxTemp = 0;
    float tempSum = 0;
    int numberOfReadings = 0;
};

inline void StatisticsDisplay::update(Subject *sbj) 
{ 
	auto* wd = dynamic_cast<WeatherData*>(sbj);
	if (wd) {
		auto temp = wd->getTemperature();
		tempSum += temp;
		++numberOfReadings;
		if (temp < minTemp)
			minTemp = temp;
		if (temp > maxTemp)
			maxTemp = temp;
		display();
	}
}

inline void StatisticsDisplay::display() 
{ 
	std::cout << "Avg/Max/Min Temperature = " <<
		tempSum / numberOfReadings << "/" << maxTemp << "/" << minTemp << std::endl;
}