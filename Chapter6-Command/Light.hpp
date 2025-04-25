#pragma once

#include <iostream>
#include <string>

class Light{
    public:
        Light(std::string location) : location(location) {}
        int getLevel() { return level; }
        void on();
        void off();
        void dim(int lvl);
    private:
        std::string location;
        int level = 0;
};

inline void Light::on()
{
    level = 100;
    std::cout << "Light is on" << std::endl;
}

inline void Light::off()
{
    level = 0;
    std::cout << "Light is off" << std::endl;
}

inline void Light::dim(int lvl)
{
    level = lvl;
    if(level == 0)
        off();
    else
        std::cout << "Light is dimed to " << level << "%" << std::endl;
}