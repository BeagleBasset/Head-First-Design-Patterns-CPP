#include "TurkeyAdapter.hpp"
#include "Turkey.hpp"
#include "Duck.hpp"
#include "MallardDuck.hpp"
#include "WildTurkey.hpp"
#include "SuperDrone.hpp"
#include "Drone.hpp"
#include "DroneAdapter.hpp"
#include<iostream>
#include<memory>

void testDuck(std::shared_ptr<Duck> duck)
{
    duck->quack();
    duck->fly();
}

int main(){
    std::shared_ptr<Duck> duck = std::make_shared<MallardDuck>();

    std::shared_ptr<Turkey> turkey = std::make_shared<WildTurkey>();
    std::shared_ptr<Duck> turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "The Duck says..." << std::endl;
    testDuck(duck);

    std::cout << "The TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);

    // Challange

    std::shared_ptr<Drone> drone = std::make_shared<SuperDrone>();
    std::shared_ptr<Duck> droneAdapter = std::make_shared<DroneAdapter>(drone);
    std::cout << "The Drone says..." << std::endl;
    testDuck(droneAdapter);

    return 0;
}

