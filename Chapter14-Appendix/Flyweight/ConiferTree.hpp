#pragma once

#include "Tree.hpp"
#include <iostream>

class ConiferTree : public Tree {
    public:
        void display(int x, int y) override {
            std::cout << "Displaying Conifer Tree at (" << x << ", " << y << ")" << std::endl;
        }
};