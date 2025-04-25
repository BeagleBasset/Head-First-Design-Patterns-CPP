#pragma once

#include "CondimentDecorator.hpp"
#include "Beverage.hpp"


class Mocha : public CondimentDecorator {
    public:
        Mocha(std::unique_ptr<Beverage> b) : CondimentDecorator(std::move(b)) { }
        std::string getDescription() { return beverage->getDescription() + ", Mocha"; }
        double cost() override;
};

inline double Mocha::cost() {
	double cost = beverage->cost();
	switch (beverage->getSize()) {
		case Size::TALL:
			cost += 0.15;
			break;
		case Size::GRANDE:
			cost += 0.20;
			break;
		case Size::VENTI:
			cost += 0.25;
			break;
		default:
			break;
	}
	return cost;
}
