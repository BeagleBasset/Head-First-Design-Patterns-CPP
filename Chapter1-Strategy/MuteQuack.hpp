#pragma once
#include "QuackBehavior.hpp"

class MuteQuack : public QuackBehavior
{
public:
	~MuteQuack() { std::cout << "MuteQuack deleted..." << std::endl; }
	void quack() override { std::cout << "<< Silence >>" << std::endl; }
};