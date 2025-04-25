#pragma once

#include "Drone.hpp"
#include<iostream>

class SuperDrone : public Drone {
    public:
        void beep() override { std::cout << "Beep beep bepp" << std::endl; }
        void spin_rotors() override { std::cout << "Rotors are spinning" << std::endl; }
        void take_off() override { std::cout << "Taking off" << std::endl; }
};