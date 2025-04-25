#pragma once

#include "RemoteControl.hpp"

class GenericRemote : public RemoteControl {
    public:
        GenericRemote(std::shared_ptr<TVFactory> tvfactory) : RemoteControl(std::move(tvfactory)) {}
        void nextChannel();
        void prevChannel();
};

inline void GenericRemote::nextChannel() {
    int currentChannel = getChannel();
    setChannel(currentChannel + 1);
}

inline void GenericRemote::prevChannel() {
    int currentChannel = getChannel();
    setChannel(currentChannel - 1);
}