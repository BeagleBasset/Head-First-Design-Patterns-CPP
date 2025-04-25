#pragma once

#include "MenuComponent.hpp"
#include "NullIterator.hpp"
#include <string>
#include <iostream>

class MenuItem : public MenuComponent {
    public:
        MenuItem() = default;
        MenuItem( std::string name,
                  std::string description,
                  bool vegetarian,
                  double price)
        : name(name), description(description),
          vegetarian(vegetarian), price(price) {}
        std::string getName() const override { return name; }
        std::string getDescription() const override { return description; }
        double getPrice() const override { return price; }
        bool isVegetarian() const override { return vegetarian; }
        std::unique_ptr<Iterator<MenuComponent>> createIterator() const override {
            return std::make_unique<NullIterator>();
        }
        void print() const override;
    private:
        std::string name;
        std::string description;
        bool vegetarian = false;
        double price = 0.00f;
};

inline void MenuItem::print() const 
{
    std::cout << " " << getName();
    if (isVegetarian()) 
        std::cout << " (v)";
    std::cout << ", " << getPrice() << std::endl << "   -- " << getDescription() << std::endl;
}