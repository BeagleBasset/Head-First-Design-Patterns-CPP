#pragma once

#include "MenuComponent.hpp"
#include <iostream>
#include <memory>

class Waitress {
	public:
		Waitress(std::shared_ptr<MenuComponent> allMenus) : allMenus(std::move(allMenus)) {}
		~Waitress() = default;
		void printMenu() const { allMenus->print(); }
		void printVegetarianMenu() const;
	private:
		std::shared_ptr<MenuComponent> allMenus;
				
};

inline void Waitress::printVegetarianMenu() const
{
	std::unique_ptr<Iterator<MenuComponent>> iterator = allMenus->createIterator();
	std::cout << std::endl << "VEGETARIAN MENU" << std::endl << "---" << std::endl;
	while (iterator->hasNext()) {
		auto menuComponent = iterator->next();
		try {
			if (menuComponent->isVegetarian()) {
				menuComponent->print();
			}
		} catch (const std::runtime_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
