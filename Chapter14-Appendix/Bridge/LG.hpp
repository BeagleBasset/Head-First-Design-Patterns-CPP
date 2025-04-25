#pragma once

#include "TV.hpp"
#include <iostream>

class LG : public TV {
    public:
        void on() override { std::cout << "Turning on the LG TV" << std::endl; }
        void off() override { std::cout << "Turning off the LG TV" << std::endl; }
        int getChannel() override { return channel; }
        void tuneChannel(int channel) override;
    private:
        int channel = 0;
};

inline void LG::tuneChannel(int channel) {
    this->channel = channel;
    std::cout << "Tuning the LG TV to channel " << channel << std::endl;
}