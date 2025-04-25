#pragma once

#include "Cheese.hpp"

class ReggianoCheese : public Cheese {
    public:
        std::string toString() const override { return "Reggiano Cheese"; }
};