#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <sstream>


class Monster {
    public:
        virtual ~Monster() = default;
        virtual std::unique_ptr<Monster> clone() const = 0;

        void setName(const std::string& name) { this->name = name; }

        virtual std::string toString() const {
            std::stringstream ss;
            ss << "I'm a monster named " << name << " with " << numHeads << " head(s). ";
            if (canBreatheFire) ss << "I can breathe fire. ";
            if (eatsChildren) ss << "I eat children. ";
            if (hasWings) ss << "I have wings. ";
            return ss.str();
        }

    protected:
        std::string name;
        bool eatsChildren = true;
        bool hasWings = false;
        int numHeads = 1;
        bool canBreatheFire = false;

        Monster(const std::string& name) : name(name) {}
        Monster(const Monster&) = default; 
};