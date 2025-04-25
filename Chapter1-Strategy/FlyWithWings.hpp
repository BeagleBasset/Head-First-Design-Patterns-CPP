#pragma once
#include "FlyBehavior.hpp"

class FlyWithWings : public FlyBehavior {
public:
	~FlyWithWings() { std::cout << "FlyWithWings deleted..." << std::endl; }
	void fly() override { std::cout << "I'm flying!!" << std::endl; }
};