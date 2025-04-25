#pragma once

#include "LG.hpp"
#include "Sony.hpp"
#include <string>
#include <memory>

class TVFactory {
    public:
        static std::shared_ptr<TV> createTV(const std::string& brand) {
            if (brand == "LG") {
                return std::make_shared<LG>();
            } else if (brand == "Sony") {
                return std::make_shared<Sony>();
            } else {
                return nullptr; 
            }
        }
};