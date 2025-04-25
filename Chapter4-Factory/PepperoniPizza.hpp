#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

class PepperoniPizza : public Pizza {
    public:
        PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> ingFact) : ingredientFactory(std::move(ingFact)) {}
        void prepare() override;
        std::unique_ptr<PizzaIngredientFactory> ingredientFactory = nullptr;
};

inline void PepperoniPizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough()->toString();
    sauce = ingredientFactory->createSauce()->toString();
    cheese = ingredientFactory->createCheese()->toString();
    pepperoni = ingredientFactory->createPepperoni()->toString();
    auto veggieObjs = ingredientFactory->createVeggies();
    veggies.clear();
    for (const auto& veg : veggieObjs) {
        veggies.push_back(veg->toString());
    }
}