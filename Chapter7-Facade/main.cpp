#include "HomeTheaterFacade.hpp"

int main(){
    std::shared_ptr<Amplifier> amp = std::make_shared<Amplifier>("Amplifier");
    std::shared_ptr<Tuner> tuner = std::make_shared<Tuner>("AM/FM Tuner", amp);
    std::shared_ptr<StreamingPlayer> player = std::make_shared<StreamingPlayer>("Streaming Player", amp);
    std::shared_ptr<CdPlayer> cd = std::make_shared<CdPlayer>("CD Player", amp);
    std::shared_ptr<Projector> projector = std::make_shared<Projector>("Projector", player);
    std::shared_ptr<TheaterLights> lights = std::make_shared<TheaterLights>("Theater Ceiling Lights");
    std::shared_ptr<Screen> screen = std::make_shared<Screen>("Theater Screen");
    std::shared_ptr<PopcornPopper> popper = std::make_shared<PopcornPopper>("Popcorn Popper");

    std::shared_ptr<HomeTheaterFacade> homeTheater =
        std::make_shared<HomeTheaterFacade>(amp, tuner, player,
                                projector, lights, screen, popper);

    homeTheater->watchMovie("Swan Lake");
    homeTheater->endMovie();

    homeTheater->listenToRadio(89.5);
    homeTheater->endRadio();

    return 0;
}