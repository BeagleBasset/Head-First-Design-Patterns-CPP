#include "VeggiePizzaBuilder.hpp"
#include "MeatPizzaBuilder.hpp"

int main() {
    auto veggieBuilder = std::make_shared<VeggiePizzaBuilder>();
    auto veggie = veggieBuilder->addCheese()
        .addSauce()
        .addTomatoes()
        .addGarlic()
        .addOlives()
        .addSpinach()
        .build();
    veggie->prepare();
    veggie->bake();
    veggie->cut();
    veggie->box();
    std::cout << veggie->toString() << std::endl;

    auto meatBuilder = std::make_shared<MeatPizzaBuilder>();
    auto meat = meatBuilder->addCheese()
        .addSauce()
        .addTomatoes()
        .addGarlic()
        .addPepperoni()
        .addSausage()
        .build();
    meat->prepare();
    meat->bake();
    meat->cut();
    meat->box();
    std::cout << meat->toString() << std::endl;
    
    return 0;
}