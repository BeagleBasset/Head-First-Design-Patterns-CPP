#pragma once

#include "PizzaStore.hpp"
#include "ChicagoPizzaIngredientFactory.hpp"
#include "CheesePizza.hpp"
#include "VeggiePizza.hpp"
#include "ClamPizza.hpp"
#include "PepperoniPizza.hpp"

class ChicagoPizzaStore : public PizzaStore {
    protected:
        std::unique_ptr<Pizza> createPizza(std::string item) override;
};

inline std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(std::string item)
{
    std::unique_ptr<Pizza> pizza = nullptr;
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory =
    std::make_unique<ChicagoPizzaIngredientFactory>();
    if(item == "cheese") 
    {
        pizza = std::make_unique<CheesePizza>(std::move(ingredientFactory));
        pizza->setName("Chicago Style Cheese Pizza");
    }
    else if(item == "veggie") 
    {
        pizza = std::make_unique<VeggiePizza>(std::move(ingredientFactory));
        pizza->setName("Chicago Style Veggie Pizza");
    }
    else if(item == "clam") 
    {
        pizza = std::make_unique<ClamPizza>(std::move(ingredientFactory));
        pizza->setName("Chicago Style Clam Pizza");
    }
    else if(item == "pepperoni") 
    {
        pizza = std::make_unique<PepperoniPizza>(std::move(ingredientFactory));
        pizza->setName("Chicago Style Pepperoni Pizza");
    }
    return pizza;

}