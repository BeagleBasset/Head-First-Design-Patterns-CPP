#pragma once
#include <string>

class Sauce {
    public: 
        virtual ~Sauce() = default;
        virtual std::string toString() const = 0;
};