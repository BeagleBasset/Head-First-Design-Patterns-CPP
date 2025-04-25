#pragma once

#include "Pizza.hpp"
#include <memory>

class PizzaBuilder {
    public:
        PizzaBuilder() : name("Default Pizza") {}
        void setName(const std::string& pizzaName) { name = pizzaName; }
        virtual PizzaBuilder& addCheese() = 0;
        virtual PizzaBuilder& addSauce() = 0;
        virtual PizzaBuilder& addTomatoes() = 0;
        virtual PizzaBuilder& addGarlic() = 0;
        virtual PizzaBuilder& addOlives() = 0;
        virtual PizzaBuilder& addSpinach() = 0;
        virtual PizzaBuilder& addPepperoni() = 0;
        virtual PizzaBuilder& addSausage() = 0;
        std::shared_ptr<Pizza> build();
    protected:
        std::string name;
        std::vector<std::string> toppings;
};

inline std::shared_ptr<Pizza> PizzaBuilder::build() 
{
    auto pizza = std::make_shared<Pizza>();
    pizza->setName(name);
    pizza->addToppings(toppings);
    return pizza;
}