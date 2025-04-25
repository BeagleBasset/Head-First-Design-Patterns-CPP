#pragma once

#include "CaffeineBeverage.hpp"
#include <string>
#include <algorithm>
#include <cctype>

class Tea : public CaffeineBeverage {
    public:
        void brew() override { std::cout << "Steeping the Tea" << std::endl; }
        void addCondiments() override { std::cout << "Adding Lemon" << std::endl; }
        bool customerWantsCondiments() override;
    private:
        std::string getUserInput();
};

inline bool Tea::customerWantsCondiments()
{
    std::string answer = getUserInput();
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return !answer.empty() && answer[0] == 'y';
}

inline std::string Tea::getUserInput()
{
    std::string answer;

    std::cout << "Would you like lemon with your Tea (y/n)? " << std::endl;

    std::getline(std::cin, answer);

    if (std::cin.fail()) {
        std::cerr << "IO error trying to read your answer" << std::endl;
        return "no";
    }

    return answer;
}