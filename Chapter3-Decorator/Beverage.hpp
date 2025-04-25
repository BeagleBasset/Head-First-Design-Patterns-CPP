#pragma once

#include <string>

class Beverage {
    public:
        enum class Size { TALL, GRANDE, VENTI };
        Beverage() = default;
        ~Beverage() = default;
        std::string virtual getDescription() { return description; }
        virtual double cost() = 0;
        virtual void setSize(Size s) { size = s; }
        virtual Size getSize() { return size; }
        virtual std::string getSizeString();
    protected:
        std::string description = "Unknown Beverage";
        Size size = Size::GRANDE;
};

inline std::string Beverage::getSizeString() {
	std::string result;
	switch (size) {
		case Size::TALL:
			result = "Tall";
			break;
		case Size::GRANDE:
			result = "Grande";
			break;
		case Size::VENTI:
			result = "Venti";
			break;
		default:
			result = "Unknown size";
			break;
	}
	return result;
}