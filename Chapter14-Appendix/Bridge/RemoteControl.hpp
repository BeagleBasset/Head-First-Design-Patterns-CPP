#pragma once

#include "TVFactory.hpp"

class RemoteControl {
    public:
        RemoteControl(std::shared_ptr<TVFactory> factory) : tvFactory(std::move(factory)) {}
        void on() { tv->on(); }
        void off() { tv->off(); }
        void setChannel(int channel) { tv->tuneChannel(channel); }
        int getChannel() { return tv->getChannel(); }
        void setTV(const std::string& brand) { tv = tvFactory->createTV(brand); };
    protected:
        std::shared_ptr<TVFactory> tvFactory;
        std::shared_ptr<TV> tv;
};
