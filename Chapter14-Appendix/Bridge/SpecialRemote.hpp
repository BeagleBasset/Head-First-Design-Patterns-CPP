#pragma once

#include "RemoteControl.hpp"

class SpecialRemote : public RemoteControl {
    public:
        SpecialRemote(std::shared_ptr<TVFactory> tvfactory) : RemoteControl(std::move(tvfactory)) {}
        void up();
        void down();
};

inline void SpecialRemote::up() {
    int channel = getChannel();
    setChannel(channel + 1);
}

inline void SpecialRemote::down() {
    int channel = getChannel();
    setChannel(channel - 1);
}