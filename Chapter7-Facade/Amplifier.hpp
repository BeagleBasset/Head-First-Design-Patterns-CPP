#pragma once

#include "Tuner.hpp"
#include "StreamingPlayer.hpp"
#include<string>
#include<iostream>
#include<memory>

class Amplifier {
    public:
        Amplifier(std::string description) : description(description) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        void setStereoSound() { std::cout << description << " stereo mode on" << std::endl; }
        void setSurroundSound() { std::cout << description << " surround sound on (5 speakers, 1 subwoofer)" << std::endl; }
        void setVolume(int level) { std::cout << description << " setting volume to " << level << std::endl; }
        void setTuner(std::shared_ptr<Tuner> tuner) { std::cout << description << " setting tuner to " << tuner->toString() << std::endl; }
        std::string toString() { return description; }
        void setStreamingPlayer(std::shared_ptr<StreamingPlayer> pl);
    private:
        std::string description;
        std::shared_ptr<Tuner> tuner;
        std::shared_ptr<StreamingPlayer> player;
};

inline void Amplifier::setStreamingPlayer(std::shared_ptr<StreamingPlayer> pl)
{
    player = pl;
    std::cout << description << " setting Streaming player to " << player->toString() << std::endl;
}