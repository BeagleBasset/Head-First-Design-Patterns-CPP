#pragma once

#include "Command.hpp"
#include "CeilingFan.hpp"

class CeilingFanOffCommand : public Command {
    public:
        CeilingFanOffCommand(CeilingFan& ceilingFan) : ceilingFan(ceilingFan) {}
        void execute() override;
        void undo();
    private:
        CeilingFan& ceilingFan;
        int prevSpeed = ceilingFan.OFF;  
};

inline void CeilingFanOffCommand::execute() 
{
    prevSpeed = ceilingFan.getSpeed();
    ceilingFan.off();
}

inline void CeilingFanOffCommand::undo()
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