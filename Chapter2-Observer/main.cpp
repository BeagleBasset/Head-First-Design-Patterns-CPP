#include "WeatherData.hpp"
#include "CurrentConditionsDisplay.hpp"
#include "StatisticsDisplay.hpp"
#include "ForecastDisplay.hpp"
#include "HeatIndex.hpp"
#include <iostream>
#include <memory>

int main() {
	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentDisplay = new CurrentConditionsDisplay(weatherData);
	ForecastDisplay* forecastDisplay 	     = new ForecastDisplay(weatherData);
	StatisticsDisplay* statisticsDisplay	 = new StatisticsDisplay(weatherData);
	HeatIndex* heatIndex					 = new HeatIndex(weatherData);
	weatherData->setMeasurements(80, 65, 30.4f);
	weatherData->setMeasurements(82, 70, 29.2f);
	weatherData->setMeasurements(78, 90, 29.2f);
	delete currentDisplay;
    delete weatherData;
	delete forecastDisplay;
	delete statisticsDisplay;
	delete heatIndex;
	std::getchar();
	return 0;
}