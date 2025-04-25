#pragma once

#include "Sauce.hpp"

class MarinaraSauce : public Sauce {
    public:
        std::string toString() const override { return "Marinara Sauce"; }
};