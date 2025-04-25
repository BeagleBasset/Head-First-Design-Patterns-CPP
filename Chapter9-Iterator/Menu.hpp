#pragma once

#include "Iterator.hpp"


template <typename T>
class Menu {
    public:
        virtual ~Menu() = default;
        virtual Iterator<T>* createIterator() = 0;
};