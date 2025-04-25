#pragma once

#include "State.hpp"
#include <memory>
#include <string>

class GumballMachine; // Forward declaration

class SoldState : public State {
    public:
        SoldState(std::shared_ptr<GumballMachine> gumballMachine);
        void insertQuarter() override;
        void dispense() override;
        void ejectQuarter() override;
        void turnCrank() override;
        void refill() override;
        std::string toString() const override;
    private:
        std::shared_ptr<GumballMachine> gumballMachine;
};

