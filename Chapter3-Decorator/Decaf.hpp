#pragma once

#include "Beverage.hpp"

class Decaf : public Beverage {
    public:
        Decaf() { description = "Decaf"; }
        double cost() { return 1.05; }
};