#pragma once
#include <string>

class Clams {
    public: 
        virtual ~Clams() = default;
        virtual std::string toString() const = 0;
};