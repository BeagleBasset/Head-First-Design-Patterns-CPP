#pragma once

#include <chrono>
#include <ctime>

class Tree {
public:
    virtual ~Tree() = default;
    virtual void display(int x, int y) = 0;
    virtual bool isWithinRange(const std::tm& date); 

};

inline bool Tree::isWithinRange(const std::tm& date)
{
    int month = date.tm_mon + 1; 
    return (month > 2) && (month < 11);
}