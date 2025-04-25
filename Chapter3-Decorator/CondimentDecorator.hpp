#pragma once

#include "Beverage.hpp"
#include <string>
#include <memory>

class CondimentDecorator : public Beverage {
    public:
        CondimentDecorator(std::unique_ptr<Beverage> b) : beverage(std::move(b)) { }
        std::string getDescription() override { return "Unkown Beverage"; }
        void setSize(Size s) override { beverage->setSize(s); }
        Beverage::Size getSize() override { return beverage->getSize(); }
        std::string getSizeString() override { return beverage->getSizeString(); }
    protected:
        std::unique_ptr<Beverage> beverage = nullptr;
};