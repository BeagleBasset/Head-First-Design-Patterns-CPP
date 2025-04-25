#pragma once

#include "Beverage.hpp"

class HouseBlend : public Beverage {
    public:
        HouseBlend() { description = "HouseBlend Coffee"; }
        double cost() { return 0.89; }
};