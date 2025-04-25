#pragma once

#include "Clams.hpp"

class FreshClams : public Clams {
    public:
        std::string toString() const override { return "Fresh Clams from Long Island Sound"; }
};