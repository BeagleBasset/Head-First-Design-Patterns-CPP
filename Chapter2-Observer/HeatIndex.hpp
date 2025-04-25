#pragma once

#include <iostream>
#include "Observer.hpp"
#include "Subject.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class HeatIndex : 
	public Observer, DisplayElement {
public:
	HeatIndex(WeatherData* weatherData)
							{ this->weatherData = weatherData;
							  weatherData->registerObserver(this); }
	~HeatIndex() { weatherData->removeObserver(this); std::cout << "HI deleted" << std::endl; }
	void update(Subject *sbj) override;
	void display() override;
private:
    float computeHeatIndex(const float &temperature, const float &humidity);
	WeatherData* weatherData;
    float heatIndex = 0;
};

inline void HeatIndex::update(Subject *sbj) 
{ 
	auto* wd = dynamic_cast<WeatherData*>(sbj);
	if (wd) {
		heatIndex = computeHeatIndex(wd->getTemperature(), wd->getHumidity());
		display();
	}
}

inline void HeatIndex::display() 
{ 
    std::cout << "Heat Index is " << heatIndex << std::endl;
}

inline float HeatIndex::computeHeatIndex(const float &temperature, const float &humidity)
{
    double index = (double)((16.923 + (0.185212 * temperature) + (5.37941 * humidity) - (0.100254 * temperature * humidity) 
    + (0.00941695 * (temperature * temperature)) + (0.00728898 * (humidity * humidity)) 
    + (0.000345372 * (temperature * temperature * humidity)) - (0.000814971 * (temperature * humidity * humidity)) +
    (0.0000102102 * (temperature * temperature * humidity * humidity)) - (0.000038646 * (temperature * temperature * temperature)) + (0.0000291583 * 
        (humidity * humidity * humidity)) + (0.00000142721 * (temperature * temperature * temperature * humidity)) + 
    (0.000000197483 * (temperature * humidity * humidity * humidity)) - (0.0000000218429 * (temperature * temperature * temperature * humidity * humidity)) +
    0.000000000843296 * (temperature * temperature * humidity * humidity * humidity)) - (0.0000000000481975 * (temperature * temperature * temperature * humidity * humidity * humidity)));

    return index;
}