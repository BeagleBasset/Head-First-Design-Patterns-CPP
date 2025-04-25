#pragma once

#include "Amplifier.hpp"
#include <iostream>
#include <string>
#include <memory>

// Foward declaration
class Amplifier;

class StreamingPlayer{
    public:
        StreamingPlayer(std::string description, std::shared_ptr<Amplifier> amplifier)
        : description(description), amplifier(amplifier) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        void pause() { std::cout << description << " paused \"" << movie << "\"" << std::endl; }
        void setTwoChannelAudio() { std::cout << description << " set two channel audio" << std::endl; }
        void setSurroundAudio() { std::cout << description << " set surround audio" << std::endl; }
        std::string toString() { return description; }
        void play(std::string mov);
        void play(int chapter);
        void stop();
    private:
        std::string description;
        std::string movie;
        int currentChapter = 0;
        std::shared_ptr<Amplifier> amplifier;
};

inline void StreamingPlayer::play(std::string mov)
{
    movie = mov;
    currentChapter = 0;
    std::cout << description << " playing \"" << movie << "\"" << std::endl;
}

inline void StreamingPlayer::play(int chapter)
{
    if(movie.empty())
        std::cout << description << " can't play chapter " << chapter << " no movie selected" << std::endl; 
    else
    {
        currentChapter = chapter;
        std::cout << description << " is playing chapter " << currentChapter << " of \"" << movie << "\"" << std::endl; 
    }
}

inline void StreamingPlayer::stop()
{
    currentChapter = 0;
    std::cout << description << " stopped \"" << movie << "\"" << std::endl;
}