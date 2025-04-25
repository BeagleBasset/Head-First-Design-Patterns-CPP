#pragma once

#include "DinerMenu.hpp"
#include "DinerMenuIterator.hpp"
#include "Iterator.hpp"
#include "PancakeHouseMenu.hpp"
#include "PancakeHouseMenuIterator.hpp"
#include <iostream>
#include <memory>

class Waitress {
	public:
		Waitress(PancakeHouseMenu *phm, DinerMenu *dm) :
			pancakeHouseMenu(phm), dinerMenu(dm) {}
		void printMenu() const;
		void printMenu(Iterator<MenuItem> *iteator) const;
	private:
		PancakeHouseMenu *pancakeHouseMenu;
		DinerMenu *dinerMenu;
};

inline void Waitress::printMenu() const
{
		auto pancakeIterator = pancakeHouseMenu->createIterator();
		auto dinerIterator = dinerMenu->createIterator();

		std::cout << "MENU" << std::endl << "----" << std::endl << "BREAKFAST" << std::endl;
		printMenu(pancakeIterator.get());
		std::cout << std::endl << "LUNCH" << std::endl;
		printMenu(dinerIterator.get());
}

inline void Waitress::printMenu(Iterator<MenuItem> *iteator) const
{
	while (iteator->hasNext()) {
		auto menuItem = iteator->next();
		std::cout << menuItem->getName() << ", ";
		std::cout << menuItem->getPrice() << " -- ";
		std::cout << menuItem->getDescription() << std::endl;
	}
}