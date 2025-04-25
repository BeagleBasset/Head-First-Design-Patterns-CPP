#pragma once
#include <iostream>

class FlyBehavior
{
public:
	virtual ~FlyBehavior() { std::cout << "FlyBehavior deleted..." << std::endl; }
	virtual void fly() = 0;
};