//----------------------------------
// This class is the invoker
//----------------------------------

#pragma once

#include "Command.hpp"
#include "NoCommand.hpp"
#include<iostream>
#include<vector>
#include<string>
#include<memory>

class RemoteControl {
    public:
        RemoteControl();
        void setCommand(int slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand);
        void onButtonWasPushed(int slot);
        void offButtonWasPushed(int slot);
        void undoButtonWasPushed() { undoCommand->undo(); }
        std::string toString();
    private:
        std::vector<std::shared_ptr<Command>> onCommands;
        std::vector<std::shared_ptr<Command>> offCommands;
        std::shared_ptr<Command> undoCommand;
};

inline RemoteControl::RemoteControl()
{
    onCommands.resize(7);
    offCommands.resize(7);

    std::shared_ptr<Command> noCommand = std::make_shared<NoCommand>();
    for(int i = 0; i < 7; ++i)
    {
        onCommands[i] = noCommand;
        offCommands[i] = noCommand;
    }
    undoCommand = noCommand;
}

inline void RemoteControl::setCommand(int slot, std::shared_ptr<Command> onCommand, std::shared_ptr<Command> offCommand)
{
    onCommands[slot] = onCommand;
    offCommands[slot] = offCommand;
}

inline void RemoteControl::onButtonWasPushed(int slot)
{
    onCommands[slot]->execute();
    undoCommand = onCommands[slot];
}

inline void RemoteControl::offButtonWasPushed(int slot)
{
    offCommands[slot]->execute();
    undoCommand = offCommands[slot];
}

inline std::string RemoteControl::toString()
{
    std::string status = "\n------ Remote Control -------\n";
    for (int i = 0; i < onCommands.size(); ++i)
    {
        status += "[slot " + std::to_string(i) + "] " 
                  + typeid(*onCommands[i]).name() + "    " 
                  + typeid(*offCommands[i]).name() + "\n";
    }
    status += "[undo] " + std::string(typeid(*undoCommand).name()) + "\n";
    return status;
}
