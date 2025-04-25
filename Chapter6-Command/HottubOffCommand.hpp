#pragma once

#include "Command.hpp"
#include "Hottub.hpp"

class HottubOffCommand : public Command {
    public:
        HottubOffCommand(Hottub& hottub) : hottub(hottub) {}
        void undo() { hottub.on(); }
        void execute() override;
    private:
        Hottub& hottub;

};

inline void HottubOffCommand::execute()
{
    hottub.setTemperature(98);
    hottub.off();
}