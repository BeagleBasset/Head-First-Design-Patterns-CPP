#include "Singleton.hpp"
#include <thread>

void worker(int id) 
{
    Singleton& s = Singleton::getInstance();
    s.sayHello(id);
}

int main() 
{
    const int numThread = 5;
    std::thread threads[numThread];

    for(int i = 0; i < numThread; ++i)
    {
        threads[i] = std::thread(worker, i);
    }

    for(int i = 0; i < numThread; ++i)
    {
        threads[i].join();
    }

    return 0;
}