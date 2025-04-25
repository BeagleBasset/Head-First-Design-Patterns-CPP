#pragma once

#include "Turkey.hpp"
#include<iostream>

class WildTurkey : public Turkey {
    public:
        void gobble() override { std::cout << "Gobble gobble" << std::endl; }
        void fly() override { std::cout << "I'm flying a short distance" << std::endl; }
};