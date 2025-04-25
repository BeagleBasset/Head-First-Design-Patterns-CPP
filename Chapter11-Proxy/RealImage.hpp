#pragma

#include "Image.hpp"
#include <iostream>
#include <string>

class RealImage : public Image {
public:
    RealImage(const std::string& filename) : filename(filename) { loadFromDisk(); }
    void display() override { std::cout << "Displaying image: " << filename << std::endl; }
    private:
    std::string filename;
    void loadFromDisk() { std::cout << "Loading image: " << filename << std::endl; }
};