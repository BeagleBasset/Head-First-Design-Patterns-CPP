#pragma once

#include "MenuItem.hpp"
#include "PancakeHouseMenuIterator.hpp"
#include <list>
#include <memory>
#include <string>

class PancakeHouseMenu {
    public:
        PancakeHouseMenu();
        void addItem(std::string name, std::string description,
                     bool vegetarian, double price);
        std::list<MenuItem> getMenuItems() { return menuItems; }
        std::unique_ptr<Iterator<MenuItem>> createIterator() { return std::make_unique<PancakeHouseMenuIterator>(menuItems); }
        std::string getMenuDescription() const { return menuDescription; }
    private:
        std::list<MenuItem> menuItems = {};
        std::string menuDescription = "Objectville Pancake House Menu";
};

inline PancakeHouseMenu::PancakeHouseMenu()
{
    addItem("K&B's Pancake Breakfast", 
        "Pancakes with scrambled eggs and toast", 
        true,
        2.99);

    addItem("Regular Pancake Breakfast", 
        "Pancakes with fried eggs, sausage", 
        false,
        2.99);

    addItem("Blueberry Pancakes",
        "Pancakes made with fresh blueberries",
        true,
        3.49);

    addItem("Waffles",
        "Waffles with your choice of blueberries or strawberries",
        true,
        3.59);
}

inline void PancakeHouseMenu::addItem(std::string name, std::string description,
                                        bool vegetarian, double price)
{
    auto menuItem = MenuItem(name, description, vegetarian, price);
	menuItems.push_back(menuItem);
}