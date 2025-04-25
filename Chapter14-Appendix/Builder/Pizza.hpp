#pragma once

#include <string>
#include <vector>
#include <iostream>

class Pizza {
    public:
        void addToppings(std::vector<std::string> toppings) { this->toppings = toppings; }
        void bake() { std::cout << "Bake for 25 minutes at 350 degrees." << std::endl; }
        void cut() { std::cout << "Cutting the pizza into diagonal slices." << std::endl; }
        void box() { std::cout << "Place pizza in official PizzaStore box." << std::endl; }
        void setName(std::string name) { this->name = name; }
        void prepare();
        std::string toString();
    private:
        std::string name;
        std::vector<std::string> toppings;
};

inline void Pizza::prepare() 
{
    std::cout << "Preparing " << name << std::endl;
    std::cout << "Tossing dough..." << std::endl;
    std::cout << "Adding sauce..." << std::endl;
    std::cout << "Adding toppings: " << std::endl;
    for (const auto& topping : toppings) {
        std::cout << "   " << topping << std::endl;
    }
}

inline std::string Pizza::toString() 
{
    std::string result = "---- " + name + " ----\n";
    for (const auto& topping : toppings) {
        result += topping + "\n";
    }
    return result;
}