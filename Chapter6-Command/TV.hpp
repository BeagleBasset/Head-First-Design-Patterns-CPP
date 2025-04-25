#pragma once

#include<iostream>
#include<string>

class TV {
    public:
        TV(std::string location) : location(location) {}
        void on() { std::cout << location << " TV is on" << std::endl; }
        void off() { std::cout << location << " TV is off" << std::endl; }
        void setInputChannel();
    private:
        std::string location;
        int channel = 0;
};

inline void TV::setInputChannel()
{
    channel = 3;
    std::cout << location << " TV channel is set for DVD" << std::endl;
}