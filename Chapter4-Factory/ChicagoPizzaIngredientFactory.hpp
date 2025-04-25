#pragma once

#include "PizzaIngredientFactory.hpp"
#include "BlackOlives.hpp"
#include "Eggplant.hpp"
#include "FrozenClams.hpp"
#include "MozzarellaCheese.hpp"
#include "SlicedPepperoni.hpp"
#include "PlumTomatoSauce.hpp"
#include "Spinach.hpp"
#include "ThickCrustDough.hpp"


class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
    public:
        std::unique_ptr<Dough> createDough() override { return std::make_unique<ThickCrustDough>(); }
        std::unique_ptr<Sauce> createSauce() override { return std::make_unique<PlumTomatoSauce>(); }
        std::unique_ptr<Cheese> createCheese() override { return std::make_unique<MozzarellaCheese>(); }
        std::vector<std::unique_ptr<Veggies>> createVeggies() override;
        std::unique_ptr<Pepperoni> createPepperoni() override { return std::make_unique<SlicedPepperoni>(); }
        std::unique_ptr<Clams> createClam() override { return std::make_unique<FrozenClams>(); } 
};

inline std::vector<std::unique_ptr<Veggies>> ChicagoPizzaIngredientFactory::createVeggies()
{
    std::vector<std::unique_ptr<Veggies>> veggies;
    veggies.push_back(std::make_unique<BlackOlives>());
    veggies.push_back(std::make_unique<Spinach>());
    veggies.push_back(std::make_unique<Eggplant>());
    return veggies;
}
