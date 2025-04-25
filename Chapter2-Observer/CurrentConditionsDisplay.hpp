#pragma once

#include <iostream>
#include "Observer.hpp"
#include "Subject.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class CurrentConditionsDisplay : 
	public Observer, DisplayElement {
public:
	CurrentConditionsDisplay(WeatherData* weatherData)
							{ this->weatherData = weatherData;
							  weatherData->registerObserver(this); }
	~CurrentConditionsDisplay() { weatherData->removeObserver(this); }
	void update(Subject *sbj) override;
	void display() override;
private:
	WeatherData* weatherData;
	float temperature = 0;
	float humidity	  = 0;
};

inline void CurrentConditionsDisplay::update(Subject *sbj) 
{ 
	auto* wd = dynamic_cast<WeatherData*>(sbj);
	if (wd) {
		temperature = wd->getTemperature();
		humidity = wd->getHumidity();
		display();
	}
}

inline void CurrentConditionsDisplay::display() 
{ 
	std::cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << std::endl; 
}