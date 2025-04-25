#pragma once

#include "Stereo.hpp"
#include "Command.hpp"

class StereoOnCommand : public Command {
    public:
        StereoOnCommand(Stereo& stereo) : stereo(stereo) {}
        void execute() override { stereo.on(); }
        void undo() { stereo.off(); }
    private:
    Stereo& stereo;
};