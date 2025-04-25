#pragma once

#include "PizzaIngredientFactory.hpp"
#include "Garlic.hpp"
#include "RedPepper.hpp"
#include "FreshClams.hpp"
#include "ReggianoCheese.hpp"
#include "SlicedPepperoni.hpp"
#include "MarinaraSauce.hpp"
#include "Onion.hpp"
#include "ThinCrustDough.hpp"


class NYPizzaIngredientFactory : public PizzaIngredientFactory {
    public:
        std::unique_ptr<Dough> createDough() override { return std::make_unique<ThinCrustDough>(); }
        std::unique_ptr<Sauce> createSauce() override { return std::make_unique<MarinaraSauce>(); }
        std::unique_ptr<Cheese> createCheese() override { return std::make_unique<ReggianoCheese>(); }
        std::vector<std::unique_ptr<Veggies>> createVeggies() override;
        std::unique_ptr<Pepperoni> createPepperoni() override { return std::make_unique<SlicedPepperoni>(); }
        std::unique_ptr<Clams> createClam() override { return std::make_unique<FreshClams>(); } 
};

inline std::vector<std::unique_ptr<Veggies>> NYPizzaIngredientFactory::createVeggies()
{
    std::vector<std::unique_ptr<Veggies>> veggies;
    veggies.push_back(std::make_unique<Garlic>());
    veggies.push_back(std::make_unique<Onion>());
    veggies.push_back(std::make_unique<RedPepper>());
    return veggies;
}
