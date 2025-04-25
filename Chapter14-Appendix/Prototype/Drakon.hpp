#pragma once
#include "Monster.hpp"
#include <iostream>

class Drakon : public Monster {
public:
    Drakon(const std::string& name, int numHeads, bool canBreatheFire);
    void spitPoison() { std::cout << name << " spits poison" << std::endl; }
    std::unique_ptr<Monster> clone() const override { return std::make_unique<Drakon>(*this);}
};

inline Drakon::Drakon(const std::string& name, int numHeads, bool canBreatheFire)
    : Monster(name) 
{
    this->numHeads = numHeads;
    this->canBreatheFire = canBreatheFire;
}