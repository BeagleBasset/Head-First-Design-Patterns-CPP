#pragma once

#include "Veggies.hpp"

class BlackOlives : public Veggies {
    public: 
        std::string toString() const override { return "Black Olives"; }
};