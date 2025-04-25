#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

class CheesePizza : public Pizza {
    public:
        CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingFact) : ingredientFactory(std::move(ingFact)) {}
        void prepare() override;
        std::unique_ptr<PizzaIngredientFactory> ingredientFactory = nullptr;
};

inline void CheesePizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough()->toString();
    sauce = ingredientFactory->createSauce()->toString();
    cheese = ingredientFactory->createCheese()->toString();
}