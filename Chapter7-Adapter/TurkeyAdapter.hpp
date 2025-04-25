#pragma once

#include "Duck.hpp"
#include "Turkey.hpp"
#include<memory>

class TurkeyAdapter : public Duck {
    public:
        TurkeyAdapter(std::shared_ptr<Turkey> turkey) : turkey(turkey) {}
        void quack() override { turkey->gobble(); }
        void fly() override;
    private:
        std::shared_ptr<Turkey> turkey;
};

inline void TurkeyAdapter::fly()
{
    for(int i =0; i < 5; ++i)
        turkey->fly();
}
