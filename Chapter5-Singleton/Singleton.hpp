#pragma once

#include <iostream>
#include <string>

class Singleton {
    public:
        static Singleton& getInstance();
        void sayHello(int threadId) { std::cout << "Hello from thread #" << threadId 
                                      << "! Singleton instance lives at address: " << this << std:: endl; }
    private:
        Singleton() { std::cout << "I'm a thread-safe Singleton - the one and only instance! " << std::endl 
                                    << "Constructor called..." << std::endl; }
        ~Singleton() { std::cout << "Good bye! Have a nice day!" << std::endl; }
        // Forbid copy
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

inline Singleton& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}
