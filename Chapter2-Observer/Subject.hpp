#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "Observer.hpp"

class Subject {
public:
	Subject() = default;
	virtual ~Subject() = default;
	void registerObserver(Observer* observer) { observers.push_back(observer); };
	void removeObserver(Observer* observer);
	void notifyObservers();
protected:
	void setChanged()	{ this->changed = true; };
	void clearChanged() { this->changed = false; };
	bool hasChanged()	{ return this->changed; };
private:
	std::vector<Observer*> observers;
	bool changed = false;

};

inline void Subject::removeObserver(Observer* observer) 
{ 
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end()); 
}

inline void Subject::notifyObservers() 
{ 
	if (hasChanged()) {
        for (auto& observer : observers) {
            observer->update(this);  // Observer update hívása
        }
        clearChanged();
    }
}