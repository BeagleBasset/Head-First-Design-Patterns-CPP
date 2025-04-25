#pragma once
#include "FlyBehavior.hpp"

class FlyRocketPowered : public FlyBehavior {
public:
	~FlyRocketPowered() { std::cout << "FlyRocketPowered deleted..." << std::endl; }
	void fly() override { std::cout << "I'm flying with a rocket!" << std::endl; }
};