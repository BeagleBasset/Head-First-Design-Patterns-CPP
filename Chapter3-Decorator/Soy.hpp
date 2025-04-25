#pragma once

#include "CondimentDecorator.hpp"
#include "Beverage.hpp"


class Soy : public CondimentDecorator {
    public:
        Soy(std::unique_ptr<Beverage> b) : CondimentDecorator(std::move(b)) { }
        std::string getDescription() { return beverage->getDescription() + ", Soy"; }
        double cost() override;
};

inline double Soy::cost() {
	double cost = beverage->cost();
	switch (beverage->getSize()) {
		case Size::TALL:
			cost += 0.10;
			break;
		case Size::GRANDE:
			cost += 0.15;
			break;
		case Size::VENTI:
			cost += 0.20;
			break;
		default:
			break;
	}
	return cost;
}
