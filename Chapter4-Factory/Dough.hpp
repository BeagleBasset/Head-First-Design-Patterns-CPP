#pragma once
#include <string>

class Dough {
    public: 
        virtual ~Dough() = default;
        virtual std::string toString() const = 0;
};