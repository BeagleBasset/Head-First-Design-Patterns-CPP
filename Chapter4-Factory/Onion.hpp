#pragma once

#include "Veggies.hpp"

class Onion : public Veggies {
    public:
        std::string toString() const override { return "Onion"; }
};