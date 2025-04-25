#pragma once

class Command {
    public:
        Command() = default;
        ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
};