#pragma once

#include <string>

class GumballMachine; // Forward declaration

class State {
    public:
        State() = default;
        ~State() = default;
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        virtual void refill() = 0;
        virtual std::string toString() const = 0;
};