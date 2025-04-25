#pragma once

#include <iostream>
#include "Observer.hpp"
#include "Subject.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class ForecastDisplay : 
	public Observer, DisplayElement {
public:
	ForecastDisplay(WeatherData* weatherData)
							{ this->weatherData = weatherData;
							  weatherData->registerObserver(this); }
	~ForecastDisplay() { weatherData->removeObserver(this); }
	void update(Subject *sbj) override;
	void display() override;
private:
	WeatherData* weatherData;
	float currentPressure = 29.92f;
	float prevPressure	  = 0;
};

inline void ForecastDisplay::update(Subject *sbj) 
{ 
	auto* wd = dynamic_cast<WeatherData*>(sbj);
	if (wd) {
		prevPressure = currentPressure;
		currentPressure = wd->getPressure();
		display();
	}
}

inline void ForecastDisplay::display() 
{ 
    std::cout << "Forcast: ";
    if (currentPressure > prevPressure)
        std::cout << "Improving weather on the way!" << std::endl;
    else if (currentPressure == prevPressure)
        std::cout << "Forcast: More of the same" << std::endl;
    else if (currentPressure < prevPressure)
        std::cout << "Forcast: Watch out for cooler, rainy weather" << std::endl;
}