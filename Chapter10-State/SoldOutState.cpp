#include "GumballMachine.hpp"
#include "SoldOutState.hpp"
#include <iostream>
#include <string>

SoldOutState::SoldOutState(std::shared_ptr<GumballMachine> gumballMachine) : gumballMachine(gumballMachine) {}
void SoldOutState::insertQuarter() { std::cout << "You can't insert a quarter, the machine is sold out" << std::endl; }
void SoldOutState::ejectQuarter()  { std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl; }
void SoldOutState::turnCrank() { std::cout << "You turned, but there are no gumballs" << std::endl; }
void SoldOutState::dispense()  { std::cout << "No gumball dispensed" << std::endl; }
void SoldOutState::SoldOutState::refill() 
{
        gumballMachine->refill(10);
        gumballMachine->setState(gumballMachine->getNoQuarterState());
}
std::string SoldOutState::toString() const  { return "sold out"; }
