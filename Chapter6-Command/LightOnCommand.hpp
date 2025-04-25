#pragma once

#include "Command.hpp"
#include "Light.hpp"

class LightOnCommand : public Command {
    public:
        LightOnCommand(Light& light) : light(light) {}
        void execute() override { light.on(); }
        void undo() { light.off(); }
    private:
        Light& light;
};