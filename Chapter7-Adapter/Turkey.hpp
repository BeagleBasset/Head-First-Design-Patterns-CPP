#pragma once

class Turkey{
    public:
        Turkey() = default;
        ~Turkey() = default;
        virtual void gobble() = 0;
        virtual void fly() = 0;
};