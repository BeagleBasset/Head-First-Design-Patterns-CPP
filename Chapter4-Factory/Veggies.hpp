#pragma once
#include <string>

class Veggies {
    public: 
        virtual ~Veggies() = default;
        virtual std::string toString() const = 0;
};

