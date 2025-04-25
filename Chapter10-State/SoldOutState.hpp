#pragma once

#include "State.hpp"
#include <memory>
#include <string>

class GumballMachine; // Forward declaration

class SoldOutState : public State {
    public:
        SoldOutState(std::shared_ptr<GumballMachine> gumballMachine);
        void insertQuarter();
        void ejectQuarter() override;
        void turnCrank() override;
        void dispense() override;
        void refill() override;
        std::string toString() const override;
    private:
        std::shared_ptr<GumballMachine> gumballMachine;
};    

