#pragma once 
#include "observer.h"

class BasicObserver : public IObserver
{
public:
    BasicObserver(std::string name) : IObserver(name) {}
    using IObserver::doSomething;
    

    void doSomething(int i) override;
    void doSomething(float f) override;
};

class FancyObserver : public IObserver
{
public:
    FancyObserver(std::string name) : IObserver(name) {}
    using IObserver::doSomething;

    void doSomething(int i) override;
    void doSomething(float f) override;
};