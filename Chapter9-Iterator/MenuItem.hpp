#pragma once

#include <string>

class MenuItem {
    public:
        MenuItem() = default;
        MenuItem( std::string name,
                  std::string description,
                  bool vegetarian,
                  double price)
        : name(name), description(description),
          vegetarian(vegetarian), price(price) {}
        std::string getName() const { return name; }
        std::string getDescription() const { return description; }
        double getPrice() const { return price; }
        bool isVegetarian() const { return vegetarian; }
        std::string toString() const { return (name + ", $" + std::to_string(price) + "\n   " + description); }
    private:
        std::string name;
        std::string description;
        bool vegetarian = false;
        double price = 0.00f;
};