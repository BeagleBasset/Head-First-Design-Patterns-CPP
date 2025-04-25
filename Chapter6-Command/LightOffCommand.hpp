#pragma once

#include "Command.hpp"
#include "Light.hpp"

class LightOffCommand : public Command {
    public:
        LightOffCommand(Light& light) : light(light) {}
        void execute() override { light.off(); }
        void undo() { light.on(); }
    private:
        Light& light;
};