#pragma once

#include "Command.hpp"
#include "Hottub.hpp"

class HottubOnCommand : public Command {
    public:
        HottubOnCommand(Hottub& hottub) : hottub(hottub) {}
        void undo() { hottub.off(); }
        void execute() override;
    private:
        Hottub& hottub;

};

inline void HottubOnCommand::execute()
{
    hottub.on();
    hottub.setTemperature(104);
    hottub.circulate();
}