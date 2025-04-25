#pragma once
#include  <iostream>

class QuackBehavior
{
public:
	virtual ~QuackBehavior() { std::cout << "QuackBehavior deleted..." << std::endl; }
	virtual void quack() = 0;
};