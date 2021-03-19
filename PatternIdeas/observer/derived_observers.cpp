#include "derived_observers.h"
#include <iostream>
void BasicObserver::doSomething(int i)
{
    intval = i;
    std::cout << name << " set int val to " << intval << "\n";
}
void BasicObserver::doSomething(float f)
{
    floatval = f;
    std::cout << name << " set float val to " << floatval << "\n";
}

void FancyObserver::doSomething(int i)
{
    intval = i;
    std::cout << name << " set int val to " << intval << " in a fancy way\n";
}
void FancyObserver::doSomething(float f)
{
    floatval = f;
    std::cout << name << " set float val to " << floatval << " in a fancy way\n";
}