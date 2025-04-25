#pragma once
#include "Duck.hpp"
#include "FlyNoWay.hpp"
#include "Squeak.hpp"
#include "FlyRocketPowered.hpp"

class ModelDuck : public Duck {
public:
	ModelDuck() {
		flyBehavior		= std::make_unique<FlyNoWay>();
		quackBehavior	= std::make_unique<Squeak>();
	}
	~ModelDuck() { std::cout << "ModelDuck deleted..." << std::endl; }
	void display() override { std::cout << "I'm a model duck" << std::endl; }
};