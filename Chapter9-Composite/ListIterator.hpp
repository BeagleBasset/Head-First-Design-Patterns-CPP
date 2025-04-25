#pragma once
#include "Iterator.hpp"
#include "MenuComponent.hpp"
#include <list>
#include <memory>

class ListIterator : public Iterator<MenuComponent> {
    public:
        ListIterator(
            std::list<std::shared_ptr<MenuComponent>>::const_iterator begin,
            std::list<std::shared_ptr<MenuComponent>>::const_iterator end
        ) : current(begin), end(end) {}

        MenuComponent* next() override;
        bool hasNext() const override { return current != end; }
        void remove() override { throw std::runtime_error("Remove not supported"); }
    private:
        std::list<std::shared_ptr<MenuComponent>>::const_iterator current;
        std::list<std::shared_ptr<MenuComponent>>::const_iterator end;
};

inline MenuComponent* ListIterator::next() 
{
    if (!hasNext()) return nullptr;
    return (current++)->get(); 
}