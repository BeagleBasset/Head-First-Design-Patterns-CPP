#pragma once

#include "TV.hpp"
#include "Command.hpp"

class TVOnCommand : public Command {
    public:
        TVOnCommand(TV& tv) : tv(tv) {}
        void execute() override { tv.on(); }
        void undo() { tv.off(); }
    private:
    TV& tv;
};