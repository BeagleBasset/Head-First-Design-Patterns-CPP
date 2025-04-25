#include "GumballMachine.hpp"
#include "WinnerState.hpp"
#include <iostream>
#include <string>

WinnerState::WinnerState(std::shared_ptr<GumballMachine> gumballMachine) : gumballMachine(gumballMachine) {}
void WinnerState::ejectQuarter()  { std::cout << "Sorry, you already turned the crank" << std::endl; }
void WinnerState::turnCrank()  { std::cout << "Turning twice doesn't get you another gumball!" << std::endl; }
void WinnerState::refill()  {  }
void WinnerState::WinnerState::dispense() {
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() == 0) {
        gumballMachine->setState(gumballMachine->getSoldOutState());
    } else {
        gumballMachine->releaseBall();
        std::cout << "YOU'RE A WINNER! You get two gumballs for your quarter" << std::endl;
        if (gumballMachine->getCount() > 0) {
            gumballMachine->setState(gumballMachine->getNoQuarterState());
        } else {
            std::cout << "Oops, out of gumballs!" << std::endl;
            gumballMachine->setState(gumballMachine->getSoldOutState());
        }
    }
}
std::string WinnerState::toString() const { return "dispensing a gumball and a winner gumball"; }
void WinnerState::insertQuarter() 
{
    std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}
