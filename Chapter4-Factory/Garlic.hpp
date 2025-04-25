#pragma once

#include "Veggies.hpp"

class Garlic : public Veggies {
    public:
        std::string toString() const override { return "Garlic"; }
};