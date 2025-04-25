#pragma once

#include "CaffeineBeverage.hpp"
#include <string>
#include <algorithm>
#include <cctype>

class Coffee : public CaffeineBeverage {
    public:
        void brew() override { std::cout << "Dripping Coffee through filter" << std::endl; }
        void addCondiments() override { std::cout << "Adding Sugar and Milk" << std::endl; }
        bool customerWantsCondiments() override;
    private:
        std::string getUserInput();
};

inline bool Coffee::customerWantsCondiments()
{
    std::string answer = getUserInput();
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return !answer.empty() && answer[0] == 'y';
}

inline std::string Coffee::getUserInput()
{
    std::string answer;

    std::cout << "Would you like milk and sugar with your coffee (y/n)? " << std::endl;

    std::getline(std::cin, answer);

    if (std::cin.fail()) {
        std::cerr << "IO error trying to read your answer" << std::endl;
        return "no";
    }

    return answer;
}