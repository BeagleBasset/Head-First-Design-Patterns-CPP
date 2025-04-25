#pragma once

#include<iostream>
#include<string>

class Screen{
    public:
        Screen(std::string description) : description(description) {}
        void up() { std::cout << description << " going up" << std::endl; }
        void down() { std::cout << description << " going down" << std::endl; }
        std::string toString() { return description; }
    private:
        std::string description;
};