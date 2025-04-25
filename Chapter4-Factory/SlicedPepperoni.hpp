#pragma once

#include "Pepperoni.hpp"

class SlicedPepperoni : public Pepperoni {
    public:
        std::string toString() const override { return "Sliced Pepperoni"; }
};