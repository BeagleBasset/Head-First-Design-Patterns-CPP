#pragma once

#include "Iterator.hpp"
#include "MenuItem.hpp"
#include <array>

class DinerMenuIterator : public Iterator<MenuItem> {
    public:
        DinerMenuIterator(MenuItem* items, int size)
        : items(items), size(size), position(0) {}
        MenuItem* next () override;
        bool hasNext() const override;
        void remove() override { throw std::runtime_error("Unsupported operation"); }
    private:
        MenuItem* items;
        int size;
        int position;
};

inline MenuItem* DinerMenuIterator::next()
{
    return &items[position++];
}

inline bool DinerMenuIterator::hasNext() const
{
    return size > position;
}