#pragma once

#include "Command.hpp"
#include "CeilingFan.hpp"

class CeilingFanLowCommand : public Command {
    public:
        CeilingFanLowCommand(CeilingFan& ceilingFan) : ceilingFan(ceilingFan) {}
        void execute() override;
        void undo();
    private:
        CeilingFan& ceilingFan;
        int prevSpeed = ceilingFan.OFF;  
};

inline void CeilingFanLowCommand::execute() 
{
    prevSpeed = ceilingFan.getSpeed();
    ceilingFan.low();
}

inline void CeilingFanLowCommand::undo()
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