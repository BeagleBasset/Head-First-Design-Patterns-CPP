#pragma once

#include "Iterator.hpp"
#include "MenuItem.hpp"
#include <list>
#include <vector>

class PancakeHouseMenuIterator : public Iterator<MenuItem> {
	public:
		PancakeHouseMenuIterator(std::list<MenuItem> &i) :
			items(i), iter(items.begin()) { }
		MenuItem* next() override { return &*iter++; }
		bool hasNext() const override { return iter != items.cend(); }
		void remove() override { throw std::runtime_error("Unsupported operation"); }
	private:
		std::list<MenuItem> &items;
		mutable std::list<MenuItem>::iterator iter;
};