#pragma once

#include "MenuItem.hpp"
#include "DinerMenuIterator.hpp"
#include <memory>
#include <array>
#include <string>
#include <iostream>

class DinerMenu {
    public:
        DinerMenu();
        void addItem(std::string name, std::string description,
                     bool vegetarian, double price);
        MenuItem* getMenuItems() { return menuItems.data(); }
        std::unique_ptr<Iterator<MenuItem>> createIterator() { return std::make_unique<DinerMenuIterator>(menuItems.data(), MAX_SIZE); }
        std::string getMenuDescription() const { return menuDescription; }
    private:
        static constexpr int MAX_SIZE = 6;
        int numberOfItems = 0;
        std::array<MenuItem, MAX_SIZE> menuItems{};
        std::string menuDescription = "Objectville Diner Menu";
};

inline DinerMenu::DinerMenu()
{
    addItem("Vegetarian BLT",
        "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
    addItem("BLT",
        "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    addItem("Soup of the day",
        "Soup of the day, with a side of potato salad", false, 3.29);
    addItem("Hotdog",
        "A hot dog, with sauerkraut, relish, onions, topped with cheese",
        false, 3.05);
    addItem("Steamed Veggies and Brown Rice",
        "Steamed vegetables over brown rice", true, 3.99);
    addItem("Pasta",
        "Spaghetti with Marinara Sauce, and a slice of sourdough bread",
        true, 3.89);
}

inline void DinerMenu::addItem(std::string name, std::string description,
                                bool vegetarian, double price)
{
    auto menuItem = MenuItem(name, description, vegetarian, price);
	if (numberOfItems >= MAX_SIZE)
		std::cerr << "Sorry, menu is full! Can't add item to menu" << std::endl;
	else
		menuItems[numberOfItems++] = menuItem;
}
