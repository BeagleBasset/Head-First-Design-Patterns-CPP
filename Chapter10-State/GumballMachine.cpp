#include "State.hpp"
#include "SoldOutState.hpp"
#include "NoQuarterState.hpp"
#include "HasQuarterState.hpp"
#include "SoldState.hpp"
#include "WinnerState.hpp"
#include "GumballMachine.hpp"
#include <iostream>


 GumballMachine::GumballMachine(int numberGumballs) : count(numberGumballs) {}

 void GumballMachine::refill(int numberGumballs) {
    count += numberGumballs;
    std::cout << "The gumball machine was just refilled; its new count is: " << count << std::endl;
    state->refill();
}

 void GumballMachine::turnCrank() {
    state->turnCrank();
    state->dispense();
}

 void GumballMachine::releaseBall() {
    if (count != 0) {
        count--;
    }
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
}

 std::string GumballMachine::toString() const {
    std::string result = "Mighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2025\nInventory: " + std::to_string(count) + " gumball";
    if (count != 1) {
        result += "s";
    }
    result += "\nMachine is " + state->toString() + "\n";
    return result;
}
void GumballMachine::insertQuarter() { state->insertQuarter(); }
void GumballMachine::ejectQuarter() { state->ejectQuarter(); }
void GumballMachine::setState(std::shared_ptr<State> newState) { state = newState; }
std::shared_ptr<State> GumballMachine::getState() const { return state; }
std::shared_ptr<State> GumballMachine::getSoldOutState() const { return soldOutState; }
std::shared_ptr<State> GumballMachine::getNoQuarterState() const { return noQuarterState; }
std::shared_ptr<State> GumballMachine::getHasQuarterState() const { return hasQuarterState; }
std::shared_ptr<State> GumballMachine::getSoldState() const { return soldState; }
std::shared_ptr<State> GumballMachine::getWinnerState() const { return winnerState; }
int GumballMachine::getCount() const { return count; }
void GumballMachine::init() {
    auto self = shared_from_this();
    soldOutState = std::make_shared<SoldOutState>(self);
    noQuarterState = std::make_shared<NoQuarterState>(self);
    hasQuarterState = std::make_shared<HasQuarterState>(self);
    soldState = std::make_shared<SoldState>(self);
    winnerState = std::make_shared<WinnerState>(self);

    if (count > 0) {
        state = noQuarterState;
    } else {
        state = soldOutState;
    }
}


