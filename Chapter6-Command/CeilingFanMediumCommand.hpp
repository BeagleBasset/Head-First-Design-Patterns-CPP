#pragma once

#include "Command.hpp"
#include "CeilingFan.hpp"

class CeilingFanMediumCommand : public Command {
    public:
        CeilingFanMediumCommand(CeilingFan& ceilingFan) : ceilingFan(ceilingFan) {}
        void execute() override;
        void undo();
    private:
        CeilingFan& ceilingFan;
        int prevSpeed = ceilingFan.OFF;  
};

inline void CeilingFanMediumCommand::execute() 
{
    prevSpeed = ceilingFan.getSpeed();
    ceilingFan.medium();
}

inline void CeilingFanMediumCommand::undo()
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