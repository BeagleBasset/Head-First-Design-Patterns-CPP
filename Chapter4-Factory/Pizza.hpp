#pragma once

#include "Dough.hpp"
#include "Sauce.hpp"
#include "Cheese.hpp"
#include "Veggies.hpp"
#include "Pepperoni.hpp"
#include "Clams.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <optional>

class Pizza {
    public:
        virtual ~Pizza() = default;
        virtual void prepare() = 0;
        virtual void bake() const { std::cout << "Bake for 25 minutes at 350" << std::endl; }
        virtual void cut() const { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
        virtual void box() const { std::cout << "Place pizza in official PizzaStore box" << std:: endl; }
        void setName(std::string n) { name = n; }
        std::string getName() { return name; }
        std::string toString();
    protected:
        std::string name;
        std::optional<std::string> dough;
        std::optional<std::string> sauce;
        std::optional<std::string> cheese;
        std::vector<std::string> veggies;
        std::optional<std::string> clam;
        std::optional<std::string> pepperoni;

};

inline std::string Pizza::toString()
{
    std::stringstream result;
    result << "---- " << name << " ----\n";

    if (dough) {
        result << *dough << "\n";
    }
    if (sauce) {
        result << *sauce << "\n";
    }
    if (cheese) {
        result << *cheese << "\n";
    }
    if (!veggies.empty()) {
        for (size_t i = 0; i < veggies.size(); ++i) {
            result << veggies[i];
            if (i < veggies.size() - 1) {
                result << ", ";
            }
        }
        result << "\n";
    }
    if (clam) {
        result << *clam << "\n";
    }
    if (pepperoni) {
        result << *pepperoni << "\n";
    }

    return result.str();
}
