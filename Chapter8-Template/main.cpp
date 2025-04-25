#include "Coffee.hpp"
#include "Tea.hpp"

int main(){

    Tea tea = Tea();
    Coffee coffee = Coffee();

    std::cout << "--------------" << std::endl;
    std::cout << "Making tea..." << std::endl;
    std::cout << "--------------" << std::endl;

    tea.prepareRecipe();

    std::cout << std::endl << "--------------" << std::endl;
    std::cout << "Making coffee..." << std::endl;
    std::cout << "--------------" << std::endl;

    coffee.prepareRecipe();

    return 0;
}