#pragma once

#include "Sauce.hpp"

class PlumTomatoSauce : public Sauce {
    public:
        std::string toString() const override { return "Tomato sauce with plum tomatoes"; }
};