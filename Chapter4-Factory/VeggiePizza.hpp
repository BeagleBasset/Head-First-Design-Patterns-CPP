#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

class VeggiePizza : public Pizza {
    public:
        VeggiePizza(std::unique_ptr<PizzaIngredientFactory> ingFact) : ingredientFactory(std::move(ingFact)) {}
        void prepare() override;
        std::unique_ptr<PizzaIngredientFactory> ingredientFactory = nullptr;
};

inline void VeggiePizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough()->toString();
    sauce = ingredientFactory->createSauce()->toString();
    cheese = ingredientFactory->createCheese()->toString();
    auto veggieObjs = ingredientFactory->createVeggies();
    veggies.clear();
    for (const auto& veg : veggieObjs) {
        veggies.push_back(veg->toString());
    }
}