#pragma once

#include "Dough.hpp"
#include "Sauce.hpp"
#include "Cheese.hpp"
#include "Veggies.hpp"
#include "Pepperoni.hpp"
#include "Clams.hpp"
#include <memory>
#include <vector>

class PizzaIngredientFactory {
    public:
        virtual std::unique_ptr<Dough> createDough() = 0;
	    virtual std::unique_ptr<Sauce> createSauce() = 0;
	    virtual std::unique_ptr<Cheese> createCheese() = 0;
	    virtual std::vector<std::unique_ptr<Veggies>> createVeggies() = 0;
	    virtual std::unique_ptr<Pepperoni> createPepperoni() = 0;
	    virtual std::unique_ptr<Clams> createClam() = 0;

};