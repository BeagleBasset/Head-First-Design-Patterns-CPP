#pragma once

#include<iostream>
#include<string>

class CeilingFan {
    public:
        CeilingFan(std::string location) { this->location = location; }
        void high();
        void medium();
        void low();
        void off();
        int getSpeed() { return speed; }
        static const int HIGH = 3;
        static const int MEDIUM = 2;
        static const int LOW = 1;
        static const int OFF = 0;
    private:
        int speed = OFF;
        std::string location;
};

inline void CeilingFan::high()
{
    speed = HIGH;
    std::cout << location << " ceiling fan is on high" << std::endl;
}

inline void CeilingFan::medium()
{
    speed = MEDIUM;
    std::cout << location << " ceiling fan is on medium" << std::endl;
}

inline void CeilingFan::low()
{
    speed = LOW;
    std::cout << location << " ceiling fan is on low" << std::endl;
}

inline void CeilingFan::off()
{
    speed = OFF;
    std::cout << location << " ceiling fan is off" << std::endl;
}