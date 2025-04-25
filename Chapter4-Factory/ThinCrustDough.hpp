#pragma once

#include "Dough.hpp"

class ThinCrustDough : public Dough {
    public:
        std::string toString() const override { return "Thin Crust Dough"; }
};