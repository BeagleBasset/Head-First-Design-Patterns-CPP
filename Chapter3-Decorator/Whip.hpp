#pragma once

#include "CondimentDecorator.hpp"
#include "Beverage.hpp"


class Whip : public CondimentDecorator {
    public:
        Whip(std::unique_ptr<Beverage> b) : CondimentDecorator(std::move(b)) { }
        std::string getDescription() { return beverage->getDescription() + ", Whip"; }
        double cost() override;
};

inline double Whip::cost() {
	double cost = beverage->cost();
	switch (beverage->getSize()) {
		case Size::TALL:
			cost += 0.05;
			break;
		case Size::GRANDE:
			cost += 0.10;
			break;
		case Size::VENTI:
			cost += 0.15;
			break;
		default:
			break;
	}
	return cost;
}
