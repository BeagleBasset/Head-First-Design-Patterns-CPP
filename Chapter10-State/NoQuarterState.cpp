#include "GumballMachine.hpp"
#include "NoQuarterState.hpp"
#include <iostream>
#include <string>

NoQuarterState::NoQuarterState(std::shared_ptr<GumballMachine> gumballMachine) : gumballMachine(gumballMachine) {}
void NoQuarterState::ejectQuarter() { std::cout << "You haven't inserted a quarter" << std::endl; }
void NoQuarterState::turnCrank() { std::cout << "You turned, but there's no quarter" << std::endl; }
void NoQuarterState::dispense()  { std::cout << "You need to pay first" << std::endl; }
void NoQuarterState::refill() {}
std::string NoQuarterState::toString() const { return "waiting for quarter"; }
void NoQuarterState::insertQuarter() 
{
    std::cout << "You inserted a quarter" << std::endl;
    gumballMachine->setState(gumballMachine->getHasQuarterState());
}