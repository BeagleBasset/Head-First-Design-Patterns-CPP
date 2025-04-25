#pragma once
#include "Duck.hpp"
#include "FlyWithWings.hpp"
#include "Quack.hpp"
class MallardDuck : public Duck {
public:
	MallardDuck() {
		flyBehavior		= std::make_unique<FlyWithWings>();
		quackBehavior	= std::make_unique<Quack>();
	}
	~MallardDuck() { std::cout << "MallardDuck deleted..." << std::endl; }
	void display() override { std::cout << "I'm a real Mallard duck" << std::endl; }
};
