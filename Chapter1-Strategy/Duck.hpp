#pragma once
#include <iostream>
#include <memory>
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

class Duck
{
public:
	Duck() { }
	virtual ~Duck() { std::cout << "Duck deleted..." << std::endl; }
	virtual void display() = 0;
	void performQuack() { quackBehavior->quack(); }
	void performFly() { flyBehavior->fly(); }
	void swim() { std::cout << "All ducks float, even decoys!" << std::endl; }
	void setFlyBehavior(std::unique_ptr<FlyBehavior> fb) { flyBehavior = std::move(fb); }
	void setQuackBehavior(std::unique_ptr<QuackBehavior> qb) { quackBehavior = std::move(qb); }
protected:
	std::unique_ptr<FlyBehavior> flyBehavior;
	std::unique_ptr<QuackBehavior> quackBehavior;
};
