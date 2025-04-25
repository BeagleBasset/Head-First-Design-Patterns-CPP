#pragma once
#include "QuackBehavior.hpp"

class Quack : public QuackBehavior
{
public:
	~Quack() { std::cout << "Quack deleted..." << std::endl; }
	void quack() override { std::cout << "Quack" << std::endl; }
};