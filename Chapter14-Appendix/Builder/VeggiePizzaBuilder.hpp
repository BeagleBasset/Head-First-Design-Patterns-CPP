#pragma once

#include "PizzaBuilder.hpp"

class VeggiePizzaBuilder : public PizzaBuilder {
    public:
        VeggiePizzaBuilder() : PizzaBuilder() { name = "Veggie Lovers Pizza";}
        PizzaBuilder& addCheese() override {
            toppings.push_back("parmesan");
            return *this;
        }
        PizzaBuilder& addSauce() override {
            toppings.push_back("sauce");
            return *this;
        }
        PizzaBuilder& addTomatoes() override {
            toppings.push_back("chopped tomatoes");
            return *this;
        }
        PizzaBuilder& addGarlic() override {
            toppings.push_back("garlic");
            return *this;
        }
        PizzaBuilder& addOlives() override {
            toppings.push_back("green olives");
            return *this; 
        }
        PizzaBuilder& addSpinach() override { 
            toppings.push_back("spinach");
            return *this; 
        }
        PizzaBuilder& addPepperoni() override { return *this; }
        PizzaBuilder& addSausage() override { return *this;}
};