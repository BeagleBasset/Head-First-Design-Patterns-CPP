#pragma once

#include "Command.hpp"
#include <vector>
#include <memory>

class MacroCommand : public Command {
    public:
        MacroCommand(std::vector<std::shared_ptr<Command>> commands) : commands(std::move(commands)) {}
        void execute() override;
        void undo();
    private:
    std::vector<std::shared_ptr<Command>> commands;
};

inline void MacroCommand::execute()
{
    for(auto& command : commands )
        command->execute();
}

inline void MacroCommand::undo()
{
    for(auto it = commands.rbegin(); it != commands.rend(); ++it)
        (*it)->undo();
}