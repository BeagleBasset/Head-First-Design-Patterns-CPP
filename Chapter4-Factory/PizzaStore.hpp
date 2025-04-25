#pragma once

#include "Pizza.hpp"

class PizzaStore{
    public:
       virtual std::unique_ptr<Pizza> orderPizza(std::string type);
    protected:
        virtual std::unique_ptr<Pizza> createPizza(std::string item) = 0;
};

inline std::unique_ptr<Pizza> PizzaStore::orderPizza(std::string type)
{
    auto pizza = createPizza(type);
    if (pizza) {
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
    }
    return pizza;
}