#include "Dragon.hpp"
#include "Drakon.hpp"

int main(){
    std::unique_ptr<Monster> dragon = std::make_unique<Dragon>("Smaug", true);
    std::unique_ptr<Monster> drakon = std::make_unique<Drakon>("Fafnir", 3, true);

    std::unique_ptr<Monster> dragon2 = dragon->clone();
    dragon2->setName("Glaurung");

    std::cout << dragon->toString() << std::endl;
    std::cout << drakon->toString() << std::endl;
    std::cout << dragon2->toString() << std::endl;

    std::cout << "Drakon spits poison: " << std::endl;
    dynamic_cast<Drakon*>(drakon.get())->spitPoison();
    
    return 0;
}