#pragma once

#include "Tree.hpp"
#include <iostream>
#include <ctime>

class DeciduousTree : public Tree {
public:
    void display(int x, int y) override;
};

inline void DeciduousTree::display(int x, int y)
{
    std::cout << "Deciduous tree is located at " << x << ", " << y << std::endl;
        
    std::tm now = {};
    time_t t = time(nullptr);
#ifdef _WIN32
    localtime_s(&now, &t); // Windows
#else
    localtime_r(&t, &now); // Linux/macOS
#endif

    if (!this->isWithinRange(now)) 
        std::cout << "The tree currently has no leaves" << std::endl; 
}