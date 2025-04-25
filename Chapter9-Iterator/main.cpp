#include "DinerMenu.hpp"
#include "PancakeHouseMenu.hpp"
#include "Waitress.hpp"

int main()
{
	auto pancakeHouseMenu = PancakeHouseMenu();
	auto dinerMenu = DinerMenu();

	auto waitress = Waitress(&pancakeHouseMenu, &dinerMenu);

	waitress.printMenu();
	
	return 0;
}