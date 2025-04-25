#pragma once

#include "MenuItem.hpp"

template <typename T>
class Iterator {
	public:
		virtual ~Iterator() = default;
		virtual T* next() = 0;
		virtual bool hasNext() const = 0;
};