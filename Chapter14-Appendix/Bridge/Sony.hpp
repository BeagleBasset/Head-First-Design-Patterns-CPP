#pragma once

#include "TV.hpp"
#include <iostream>

class Sony : public TV {
    public:
        void on() override { std::cout << "Turning on the Sony TV" << std::endl; }
        void off() override { std::cout << "Turning off the Sony TV" << std::endl; }
        int getChannel() override { return station; }
        void tuneChannel(int channel) override;
    private:
        int station = 0;
};

inline void Sony::tuneChannel(int channel) {
    station = channel;
    std::cout << "Tuning the Sony TV to channel " << station << std::endl;
}