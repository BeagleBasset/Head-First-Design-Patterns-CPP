#pragma once

#include "Command.hpp"
#include "CeilingFan.hpp"

class CeilingFanHighCommand : public Command {
    public:
        CeilingFanHighCommand(CeilingFan& ceilingFan) : ceilingFan(ceilingFan) {}
        void execute() override;
        void undo();
    private:
        CeilingFan& ceilingFan;
        int prevSpeed = ceilingFan.OFF;  
};

inline void CeilingFanHighCommand::execute() 
{
    prevSpeed = ceilingFan.getSpeed();
    ceilingFan.high();
}

inline void CeilingFanHighCommand::undo()
{
    switch (prevSpeed)
    {
    case ceilingFan.HIGH:
        ceilingFan.high();
        break;
    case ceilingFan.MEDIUM:
        ceilingFan.medium();
        break;
    case ceilingFan.LOW:
        ceilingFan.low();
        break;
    default:
        ceilingFan.off();
        break;
    }
}