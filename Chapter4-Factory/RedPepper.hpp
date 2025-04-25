#pragma once

#include "Veggies.hpp"

class RedPepper : public Veggies {
    public:
        std::string toString() const override { return "Red Pepper"; }
};