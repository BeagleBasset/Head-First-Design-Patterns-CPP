#pragma once

#include "Amplifier.hpp"
#include <string>
#include <iostream>
#include <memory>

// Foward declaration
class Amplifier;

class Tuner {
    public:
        Tuner(std::string description, std::shared_ptr<Amplifier> amplifier) 
        : description(description), amplifier(amplifier) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        void setAm() { std::cout << description << " setting AM mode" << std::endl; }
        void setFm() { std::cout << description << " setting FM mode" << std::endl; }
        std::string toString() { return description; }
        void setFrequency(double freq);
    private:
        std::string description;
        std::shared_ptr<Amplifier> amplifier;
        double frequency = 0.0f;
};

inline void Tuner::setFrequency(double freq)
{
    frequency = freq;
    std::cout << description << " setting frequency to " << frequency << std::endl;
}