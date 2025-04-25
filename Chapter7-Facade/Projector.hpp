#pragma once

#include "StreamingPlayer.hpp"
#include<iostream>
#include<string>
#include<memory>

class Projector{
    public:
        Projector(std::string description, std::shared_ptr<StreamingPlayer> player)
        : description(description), player(player) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        std::string toString() { return description; }
        void wideScreenMode() { std::cout << description << " in widescreen mode (16x9 aspect ratio)" << std::endl; }
        void tvMode() { std::cout << description << " in tv mode (4x3 aspect ratio)" << std::endl; }
    private:
        std::string description;
        std::shared_ptr<StreamingPlayer> player;
};