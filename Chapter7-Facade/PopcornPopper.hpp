#pragma once

#include<iostream>
#include<string>

class PopcornPopper{
    public:
        PopcornPopper(std::string description) : description(description) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        std::string toString() { return description; }
        void pop() { std::cout << description << " popping popcorn!" << std::endl; }
    private:
        std::string description;
};