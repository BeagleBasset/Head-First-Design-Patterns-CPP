#pragma once

#include<iostream>
#include<string>
#include<memory>

class TheaterLights{
    public:
        TheaterLights(std::string description) : description(description) {}
        void on() { std::cout << description << " on" << std::endl; }
        void off() { std::cout << description << " off" << std::endl; }
        std::string toString() { return description; }
        void dim(int level) { std::cout << description << " diming to " << level << "%"  << std::endl; }
    private:
        std::string description;
};