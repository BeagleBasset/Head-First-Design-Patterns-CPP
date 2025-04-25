#pragma once

#include "Command.hpp"

class NoCommand : public Command {
    public:
        NoCommand() = default;
        ~NoCommand() = default;
        void execute() override {}
        void undo() {}
};