#pragma once
#include "Monster.hpp"
#include <iostream>

class Dragon : public Monster {
public:
    Dragon(const std::string& name, bool hasWings);
    std::unique_ptr<Monster> clone() const override { return std::make_unique<Dragon>(*this);}
};

inline Dragon::Dragon(const std::string& name, bool hasWings)
    : Monster(name) 
{
    this->hasWings = hasWings;
}