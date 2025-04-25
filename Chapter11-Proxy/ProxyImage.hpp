#pragma once

#include "Image.hpp"
#include "RealImage.hpp"
#include <string>

class ProxyImage : public Image {
    public:
        ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}
        ~ProxyImage() { delete realImage; }
        void display() override;
        private:
        std::string filename;
        RealImage* realImage;
};

inline void ProxyImage::display() {
    if (realImage == nullptr) {
        realImage = new RealImage(filename);
    }
    realImage->display();
}