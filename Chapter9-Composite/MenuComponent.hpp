#pragma once

#include "Iterator.hpp"
#include <string>
#include <stdexcept>
#include <memory>

template <typename T>
class Iterator;

class MenuComponent {
    public:
        virtual ~MenuComponent() = default;
    
        virtual void add(std::shared_ptr<MenuComponent> component) {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual void remove(std::shared_ptr<MenuComponent> component) {
            throw std::runtime_error("Unsupported operation");
        }

        virtual void removeFromParent() {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual std::shared_ptr<MenuComponent> getChild(int index) const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual std::string getName() const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual std::string getDescription() const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual double getPrice() const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual bool isVegetarian() const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual void print() const {
            throw std::runtime_error("Unsupported operation");
        }
    
        virtual std::unique_ptr<Iterator<MenuComponent>> createIterator() const {
            throw std::runtime_error("Unsupported operation");
        }
    };