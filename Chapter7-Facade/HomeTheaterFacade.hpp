#pragma once

#include "Amplifier.hpp"
#include "Tuner.hpp"
#include "StreamingPlayer.hpp"
#include "CDPlayer.hpp"
#include "Projector.hpp"
#include "TheaterLights.hpp"
#include "Screen.hpp"
#include "PopcornPopper.hpp"
#include "HomeTheaterFacade.hpp"

class HomeTheaterFacade {
    public:
        HomeTheaterFacade(std::shared_ptr<Amplifier> amp, std::shared_ptr<Tuner> tuner,
            std::shared_ptr<StreamingPlayer> player, std::shared_ptr<Projector> projector,
            std::shared_ptr<TheaterLights> lights, std::shared_ptr<Screen> screen, 
            std::shared_ptr<PopcornPopper> popper )
            : amp(amp), tuner(tuner), player(player), projector(projector), lights(lights),
              screen(screen), popper(popper) {}

        void watchMovie(std::string movie);
        void endMovie();
        void listenToRadio(double frequency);
        void endRadio();
    private:
        std::shared_ptr<Amplifier> amp;
        std::shared_ptr<Tuner> tuner;
        std::shared_ptr<StreamingPlayer> player;
        std::shared_ptr<Projector> projector;
        std::shared_ptr<TheaterLights> lights;
        std::shared_ptr<Screen> screen;
        std::shared_ptr<PopcornPopper> popper;
};

inline void HomeTheaterFacade::watchMovie(std::string movie)
{
    std::cout << "Get ready to watch a movie..." << std::endl;
    popper->on();
    popper->pop();
    lights->dim(10);
    screen->down();
    projector->on();
    projector->wideScreenMode();
    amp->on();
    amp->setStreamingPlayer(player);
    amp->setSurroundSound();
    amp->setVolume(5);
    player->on();
    player->play(movie);
}

inline void HomeTheaterFacade::endMovie() 
{
    std::cout << "Shutting movie theater down..." << std::endl;
    popper->off();
    lights->on();
    screen->up();
    projector->off();
    amp->off();
    player->stop();
    player->off(); 
}

inline void HomeTheaterFacade::listenToRadio(double frequency)
{
    std::cout << "Tuning in the airwaves..." << std::endl;
    tuner->on();
    tuner->setFrequency(frequency);
    amp->on();
    amp->setVolume(5);
    amp->setTuner(tuner);
}

inline void HomeTheaterFacade::endRadio()
{
    std::cout << "Shutting down the tuner..." << std::endl;
    tuner->off();
    amp->off();
}