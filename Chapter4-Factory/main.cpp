#include "NYPizzaStore.hpp"
#include "ChicagoPizzaStore.hpp"


int main(){
    std::unique_ptr<PizzaStore> nyStore = std::make_unique<NYPizzaStore>();
    std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();
    
    std::unique_ptr<Pizza> pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->toString() << std::endl;

    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->toString() << std::endl;

    pizza = nyStore->orderPizza("clam");
    std::cout << "Ethan ordered a " << pizza->toString() << std::endl;

    pizza = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza->toString() << std::endl;

    pizza = nyStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a " << pizza->toString() << std::endl;

    pizza = chicagoStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a " << pizza->toString() << std::endl;

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Ethan ordered a " << pizza->toString() << std::endl;

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza->toString() << std::endl;

    return 0;
}