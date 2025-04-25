#pragma once

#include<iostream>

class Hottub {
    public:
        Hottub() = default;
        void on()  { ison = true; }
        void off() { ison = false;}
        void circulate();
        void jetsOn();
        void jetsOff();
        void setTemperature(int temp);
    private:
        bool ison = false;
        int temerature = 0;
};

inline void Hottub::circulate()
{
    if(ison)
        std::cout << "Hottub is bubbling!" << std::endl;
}

inline void Hottub::jetsOn()
{
    if(ison)
        std::cout << "Hottub jets are on" << std::endl;
}

inline void Hottub::jetsOff()
{
    if(ison)
        std::cout << "Hottub jets are off" << std::endl;
}

inline void Hottub::setTemperature(int temp) 
{
    if(temp > temerature)
        std::cout << "Hottub is heating to a steaming " << temp << " degrees" << std::endl;
    else
        std::cout << "Hottub is cooling to " << temp << " degrees" << std::endl;
    temerature = temp;   
}