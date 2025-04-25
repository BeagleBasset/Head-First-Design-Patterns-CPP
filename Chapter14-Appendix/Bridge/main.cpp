#include "SpecialRemote.hpp"
#include "GenericRemote.hpp"
#include <iostream>

int main(){
    std::shared_ptr<TVFactory> tvFactory = std::make_shared<TVFactory>();
    std::shared_ptr<SpecialRemote> remoteSony = std::make_shared<SpecialRemote>(tvFactory);
    std::cout << "Connect your remote to the TV" << std::endl;
    remoteSony->setTV("Sony");
    remoteSony->on();
    remoteSony->up();
    remoteSony->down();
    remoteSony->off();

    std::shared_ptr<GenericRemote> remoteLG = std::make_shared<GenericRemote>(tvFactory);
    std::cout << "Connect your remote to the TV" << std::endl;
    remoteLG->setTV("LG");
    remoteLG->on();
    remoteLG->nextChannel();
    remoteLG->prevChannel();
    remoteLG->off();
    
    return 0;
}