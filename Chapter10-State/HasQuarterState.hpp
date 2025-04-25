#pragma once

#include "State.hpp"
#include <memory>
#include <string>

class GumballMachine; // Forward declaration

class HasQuarterState : public State {
    public:
        HasQuarterState(std::shared_ptr<GumballMachine> gumballMachine);
        void insertQuarter() override;
        void dispense() override;
        void refill() override;
        std::string toString() const override;
        void ejectQuarter() override;
        void turnCrank() override;
    private:
        std::shared_ptr<GumballMachine> gumballMachine;
};

