#pragma once

#include<iostream>

class Stereo {
    public:
        Stereo(std::string location) : location(location) {}
        void on() { std::cout << location << " stereo is on" << std::endl; }
        void off() { std::cout << location << " stereo is off" << std::endl; }
        void setCD() { std::cout << location << " stereo is set for CD input" << std::endl; }
        void setDVD() { std::cout << location << " stereo is set for DVD input" << std::endl; }
        void setRadio() { std::cout << location << " stereo is set for Radio input" << std::endl; }
        void setVolume(int volume);
    private:
    std::string location;
};

inline void Stereo::setVolume(int volume)
{
    if(volume < 1)
        volume = 1;
    else if (volume > 11)
        volume = 11;
    std::cout << location << " Stereo volume set to " << volume << std::endl;
}