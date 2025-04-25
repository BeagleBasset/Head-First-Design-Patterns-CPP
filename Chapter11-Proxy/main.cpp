#include "ProxyImage.hpp"
#include "Image.hpp"

int main() {
    Image* image = new ProxyImage("Joseph_Mallord_William_Turner_-_Fishermen_at_Sea.jpg");

    image->display();
    image->display();

    delete image;
    return 0;
}