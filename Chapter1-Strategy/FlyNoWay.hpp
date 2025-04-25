#pragma once
#include "FlyBehavior.hpp"

class FlyNoWay : public FlyBehavior {
public:
	~FlyNoWay() { std::cout << "FlyNoWay deleted..." << std::endl; }
	void fly() override { std::cout << "I can't fly" << std::endl; }
};