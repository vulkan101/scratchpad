#pragma once
#include <string>
class IObserver
{
public:
    IObserver(std::string name) : name(name) {}
    std::string name;
    virtual void doSomething(int i)=0;
    virtual void doSomething(float f)=0;

    int intval = 0;
    float floatval = 0;
};

