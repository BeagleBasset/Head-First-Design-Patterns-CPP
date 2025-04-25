#pragma once

#include "MenuComponent.hpp"
#include "CompositeIterator.hpp"
#include "ListIterator.hpp"
#include "NullIterator.hpp"
#include <list>
#include <iostream>

class Menu : public MenuComponent {
    public:
        virtual ~Menu() = default;
        Menu(const std::string& name, const std::string& description) 
            : name(name), description(description) {}
        void add(std::shared_ptr<MenuComponent> component) override {
            menuComponents.push_back(component);
        }
        void remove(std::shared_ptr<MenuComponent> component) override {
            menuComponents.remove(component);
        }
        std::shared_ptr<MenuComponent> getChild(int index) const override;
        std::string getName() const override { return name; }
        std::string getDescription() const override { return description; }
        std::unique_ptr<Iterator<MenuComponent>> createIterator() const  override;
        void print() const override;
    private:
        std::string name;
        std::string description;
        std::list<std::shared_ptr<MenuComponent>> menuComponents;
};

inline std::shared_ptr<MenuComponent> Menu::getChild(int index) const {
    auto it = std::next(menuComponents.begin(), index);
    return (it != menuComponents.end()) ? *it : nullptr;
}

inline std::unique_ptr<Iterator<MenuComponent>> Menu::createIterator() const {
    if(menuComponents.empty()) {
        return std::make_unique<NullIterator>();
    } else {
        // Ha van lista, akkor visszaadhatsz pl. egy ListIterator-t (ha van olyanod)
        return std::make_unique<ListIterator>(menuComponents.begin(), menuComponents.end());
    }
}

inline void Menu::print() const {
    std::cout << std::endl << getName() << ", " << getDescription() << std::endl;
    std::cout << "---------------------" << std::endl;
    for (const auto& component : menuComponents) {
        component->print();
    }
}