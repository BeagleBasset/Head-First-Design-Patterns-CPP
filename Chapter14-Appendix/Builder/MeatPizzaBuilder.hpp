#pragma once

#include "PizzaBuilder.hpp"

class MeatPizzaBuilder : public PizzaBuilder {
    public:
        MeatPizzaBuilder() : PizzaBuilder() { name = "Meat Lovers Pizza";}
        PizzaBuilder& addCheese() override {
            toppings.push_back("mozzarella");
            return *this;
        }
        PizzaBuilder& addSauce() override {
            toppings.push_back("NY style sauce");
            return *this;
        }
        PizzaBuilder& addTomatoes() override {
            toppings.push_back("sliced tomatoes");
            return *this;
        }
        PizzaBuilder& addGarlic() override {
            toppings.push_back("garlic");
            return *this;
        }
        PizzaBuilder& addOlives() override { return *this; }
        PizzaBuilder& addSpinach() override { return *this; }
        PizzaBuilder& addPepperoni() override {
            toppings.push_back("pepperoni");
            return *this;
        }
        PizzaBuilder& addSausage() override {
            toppings.push_back("sausage");
            return *this;
        }
};