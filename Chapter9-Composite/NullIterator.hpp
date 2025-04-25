#pragma once

#include "Iterator.hpp"
#include "MenuComponent.hpp"

class NullIterator : public Iterator<MenuComponent> {
    public:
        NullIterator() = default;
        MenuComponent* next() override { return nullptr; }
        bool hasNext() const override { return false; }
        void remove() override { throw std::invalid_argument("NullIterator::remove(): Unsupported Operation"); }
};