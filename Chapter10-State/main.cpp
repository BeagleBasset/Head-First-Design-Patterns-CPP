#include "GumballMachine.hpp"
#include <iostream>
#include <memory>

int main() {
    auto gumballMachine = std::make_shared<GumballMachine>(10);
    gumballMachine->init();
    std::cout << gumballMachine->toString() << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << gumballMachine->toString() << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << gumballMachine->toString() << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << gumballMachine->toString() << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << gumballMachine->toString() << std::endl;
    
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << gumballMachine->toString() << std::endl;
    
    return 0;
}