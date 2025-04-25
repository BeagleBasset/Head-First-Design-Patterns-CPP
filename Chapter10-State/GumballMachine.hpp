#pragma once

#include <memory>
#include <string>

class State;
class SoldOutState;
class NoQuarterState;
class HasQuarterState;
class SoldState;
class WinnerState;    

class GumballMachine : public std::enable_shared_from_this<GumballMachine> {
    public:
        GumballMachine(int numberGumballs);
        void init();
        void insertQuarter(); 
        void ejectQuarter(); 
        void setState(std::shared_ptr<State> newState);
        std::shared_ptr<State> getState() const;
        std::shared_ptr<State> getSoldOutState() const;
        std::shared_ptr<State> getNoQuarterState() const;
        std::shared_ptr<State> getHasQuarterState() const;
        std::shared_ptr<State> getSoldState() const;
        std::shared_ptr<State> getWinnerState() const;
        int getCount() const;
        void refill(int numberGumballs);
        void turnCrank();
        void releaseBall();
        std::string toString() const;
    private:
        std::shared_ptr<State> soldOutState;
        std::shared_ptr<State> noQuarterState;
        std::shared_ptr<State> hasQuarterState;
        std::shared_ptr<State> soldState;
        std::shared_ptr<State> winnerState;
        std::shared_ptr<State> state = soldOutState;
        int count = 0;
};


