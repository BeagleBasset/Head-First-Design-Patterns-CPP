#pragma once

#include "Amplifier.hpp"
#include <iostream>
#include <string>
#include <memory>

class CdPlayer {
    public:
        CdPlayer(std::string description, std::shared_ptr<Amplifier> amplifier)
        : description(description), amplifier(amplifier) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        std::string toString() { return description; }
        void eject() { std::cout << description << " eject" << std::endl; }
        void pause() { std::cout << description << " paused \"" << title << "\"" << std::endl; }
        void stop(); 
        void play(std::string title);
        void play(int track);
    private:
        std::string description;
        std::string title;
        int currentTrack;
        std::shared_ptr<Amplifier> amplifier;
};

inline void CdPlayer::play(std::string title)
{
    this->title = title;
    currentTrack = 0;
    std::cout << description << " playing \"" << title << "\"" << std::endl; 
}

inline void CdPlayer::play(int track)
{
    if(title.empty())
        std::cout << description << " can't play track " << track << " no CD inserted" << std::endl; 
    else
    {
        currentTrack = track;
        std::cout << description << " is playing track " << currentTrack << "\"" << std::endl; 
    }
}

inline void CdPlayer::stop()
{
    currentTrack = 0;
    std::cout << description << " stopped" << std::endl; 
}