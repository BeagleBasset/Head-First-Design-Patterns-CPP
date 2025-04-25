#include "TreeFactory.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::vector<std::pair<int, int>> deciduousLocations = {{1, 1}, {33, 50}, {100, 90}};
    std::vector<std::pair<int, int>> coniferLocations = {{10, 87}, {24, 76}, {2, 64}};

    try {
        TreeFactory treeFactory;
        std::shared_ptr<Tree> d = treeFactory.getTree("deciduous");
        std::shared_ptr<Tree> c = treeFactory.getTree("conifer");

        for (const auto& location : deciduousLocations) {
            d->display(location.first, location.second);
        }
        for (const auto& location : coniferLocations) {
            c->display(location.first, location.second);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}