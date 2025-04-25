#pragma once

#include "Dough.hpp"

class ThickCrustDough : public Dough {
    public:
        std::string toString() const override { return "ThickCrust style extra thick crust dough"; }
};