#pragma once

#include "Stereo.hpp"
#include "Command.hpp"

class StereoOffCommand : public Command {
    public:
        StereoOffCommand(Stereo& stereo) : stereo(stereo) {}
        void execute() override { stereo.off(); }
        void undo() { stereo.on(); }
    private:
    Stereo& stereo;
};