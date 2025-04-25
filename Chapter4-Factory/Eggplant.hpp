#pragma once

#include "Veggies.hpp"

class Eggplant : public Veggies {
    public: 
        std::string toString() const override { return "Eggplant"; }
};