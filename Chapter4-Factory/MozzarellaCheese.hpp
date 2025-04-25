#pragma once

#include "Cheese.hpp"

class MozzarellaCheese : public Cheese {
    public:
        std::string toString() const override { return "Shredded Mozzarella"; }
};