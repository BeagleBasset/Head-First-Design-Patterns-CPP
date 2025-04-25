#pragma once

#include "TV.hpp"
#include "Command.hpp"

class TVOffCommand : public Command {
    public:
        TVOffCommand(TV& tv) : tv(tv) {}
        void execute() override { tv.off(); }
        void undo() { tv.on(); }
    private:
    TV& tv;
};