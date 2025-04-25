#pragma once

#include "Clams.hpp"

class FrozenClams : public Clams {
    public:
        std::string toString() const override { return "Frozen Clams from Chesapeake Bay"; }
};