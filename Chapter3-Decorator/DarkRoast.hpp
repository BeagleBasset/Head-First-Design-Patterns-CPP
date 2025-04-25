#pragma once

#include "Beverage.hpp"

class DarkRoast : public Beverage {
    public:
        DarkRoast() { description = "DarkRoast"; }
        double cost() { return 0.99; }
};