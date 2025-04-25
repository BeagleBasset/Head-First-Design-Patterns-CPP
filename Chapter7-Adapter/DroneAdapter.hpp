#pragma once

#include "Duck.hpp"
#include "Drone.hpp"
#include<memory>

class DroneAdapter : public Duck {
    public:
        DroneAdapter(std::shared_ptr<Drone> drone) : drone(drone) {}
        void quack() override { drone->beep(); }
        void fly() override;
    private:
        std::shared_ptr<Drone> drone;
};

inline void DroneAdapter::fly()
{
    drone->spin_rotors();
    drone->take_off();
}