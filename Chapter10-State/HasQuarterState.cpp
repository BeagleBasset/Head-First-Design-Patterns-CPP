#include "HasQuarterState.hpp"
#include "GumballMachine.hpp"
#include <iostream>
#include <cstdlib>

HasQuarterState::HasQuarterState(std::shared_ptr<GumballMachine> gumballMachine) : gumballMachine(gumballMachine) {}
void HasQuarterState::insertQuarter()  { std::cout << "You can't insert another quarter" << std::endl; }
void HasQuarterState::dispense()  { std::cout << "No gumball dispensed" << std::endl; }
void HasQuarterState::refill()  {  }
void HasQuarterState::HasQuarterState::ejectQuarter() 
{
    std::cout << "Quarter returned" << std::endl;
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank() {
    std::cout << "You turned..." << std::endl;
    int winner = std::rand() % 10;
    if ((winner == 0) && (gumballMachine->getCount() > 1)) {
        gumballMachine->setState(gumballMachine->getWinnerState());
    } else {
        gumballMachine->setState(gumballMachine->getSoldState());
    }
}

std::string HasQuarterState::toString() const  { return "waiting for turn of crank"; }