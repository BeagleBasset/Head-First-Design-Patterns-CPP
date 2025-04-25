#pragma once

#include "State.hpp"
#include <memory>
#include <string>

class GumballMachine; // Forward declaration

class WinnerState : public State {
    public:
        WinnerState(std::shared_ptr<GumballMachine> gumballMachine);
        void insertQuarter() override;
        void dispense() override;
        void ejectQuarter() override;
        void turnCrank() override;
        void refill() override;
        std::string toString() const override;
    private:
        std::shared_ptr<GumballMachine> gumballMachine;
};
