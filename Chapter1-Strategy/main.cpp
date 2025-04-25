#include "MallardDuck.hpp"
#include "ModelDuck.hpp"

int main() {
	MallardDuck mallardduck;
	ModelDuck	modelduck;
	mallardduck.display();
	mallardduck.performFly();
	mallardduck.performQuack();
	modelduck.display();
	modelduck.performQuack();
	modelduck.performFly();
	modelduck.setFlyBehavior(std::make_unique<FlyRocketPowered>());
	modelduck.performFly();
	std::getchar();
	return 0;
}