#pragma once

class TV {
    public:
        TV() = default;
        ~TV() = default;
        virtual void on() = 0;
        virtual void off() = 0;
        virtual void tuneChannel(int channel) = 0;
        virtual int getChannel() = 0;
};