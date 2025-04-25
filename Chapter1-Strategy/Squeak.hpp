#pragma once
#include "QuackBehavior.hpp"

class Squeak : public QuackBehavior
{
public:
	~Squeak() { std::cout << "Squeak deleted..." << std::endl; }
	void quack() override { std::cout << "Squeak" << std::endl; }
};