#pragma once

#include "Veggies.hpp"

class Spinach : public Veggies {
    public: 
        std::string toString() const override { return "Spinach"; }
};