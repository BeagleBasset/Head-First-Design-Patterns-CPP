#pragma once

#include "Tree.hpp"
#include "DeciduousTree.hpp"
#include "ConiferTree.hpp"
#include <memory>
#include <stdexcept>
#include <string>

class TreeFactory {
    public:
        TreeFactory();
        std::shared_ptr<Tree> getTree(const std::string& type);
    private:
        std::shared_ptr<Tree> d;
        std::shared_ptr<Tree> c;
};

inline TreeFactory::TreeFactory() 
{
    d = std::make_shared<DeciduousTree>();
    c = std::make_shared<ConiferTree>();
}

inline std::shared_ptr<Tree> TreeFactory::getTree(const std::string& type) {
    if (type == "deciduous") {
        return d;
    } else if (type == "conifer") {
        return c;
    } else {
        throw std::invalid_argument("Invalid kind of tree");
    }
}