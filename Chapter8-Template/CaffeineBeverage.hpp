#pragma once

#include<iostream>

class CaffeineBeverage {
    public:
        virtual void brew() = 0;
        virtual void addCondiments() = 0;
        void boilWater() { std::cout << "Boiling water" << std::endl; }
        void pourInCup() { std::cout << "Pouring into cup" << std::endl; }
        virtual bool customerWantsCondiments() { return true; }
        void prepareRecipe();
};

inline void CaffeineBeverage::prepareRecipe()
{
    boilWater();
    brew();
    pourInCup();
    if (customerWantsCondiments())
        addCondiments();
}