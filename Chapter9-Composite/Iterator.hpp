#pragma once

#include "MenuItem.hpp"

class MenuComponent;

template <typename T>
class Iterator {
	public:
		virtual ~Iterator() = default;
		virtual T* next() = 0;
		virtual bool hasNext() const = 0;
		virtual void remove() = 0;
};