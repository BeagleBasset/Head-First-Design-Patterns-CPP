#pragma once

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

class ClamPizza : public Pizza {
    public:
        ClamPizza(std::unique_ptr<PizzaIngredientFactory> ingFact) : ingredientFactory(std::move(ingFact)) {}
        void prepare() override;
        std::unique_ptr<PizzaIngredientFactory> ingredientFactory = nullptr;
};

inline void ClamPizza::prepare()
{
    std::cout << "Preparing " << name << std::endl;
    dough = ingredientFactory->createDough()->toString();
    sauce = ingredientFactory->createSauce()->toString();
    cheese = ingredientFactory->createCheese()->toString();
    clam = ingredientFactory->createClam()->toString();
}