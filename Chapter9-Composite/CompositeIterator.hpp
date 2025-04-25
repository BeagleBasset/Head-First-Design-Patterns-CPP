#pragma once

#include "Iterator.hpp"
#include "MenuComponent.hpp"
#include <stack>
#include <memory>

class CompositeIterator : public Iterator<MenuComponent> {
    public:
        CompositeIterator(std::unique_ptr<Iterator<MenuComponent>> iterator)
            : stack_() { stack_.push(std::move(iterator)); }
        MenuComponent* next() override;
        bool hasNext() const override { return !stack_.empty(); }
        void remove() override;
    private:
        std::stack<std::unique_ptr<Iterator<MenuComponent>>> stack_;
};

inline MenuComponent* CompositeIterator::next() 
{
    if (!hasNext()) {
        return nullptr;
    }

    auto currentIterator = std::move(stack_.top());
    stack_.pop();
    MenuComponent* component = currentIterator->next();

    if (currentIterator->hasNext()) {
        stack_.push(std::move(currentIterator));
    }

    auto childIterator = component->createIterator();
    if (childIterator) {
        stack_.push(std::move(childIterator));
    }

    return component;
}

inline void CompositeIterator::remove() 
{
    if (stack_.empty()) 
        throw std::runtime_error("No elements to remove");
    
    auto currentIterator = std::move(stack_.top());
    stack_.pop();
    MenuComponent* component = currentIterator->next();
    
    if (component) 
        component->removeFromParent();
    
    auto childIterator = component->createIterator();
    if (childIterator) 
        stack_.push(std::move(childIterator));
}


