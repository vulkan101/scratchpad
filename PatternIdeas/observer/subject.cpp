#include "subject.h"
#include "observer.h"

void ISubject::set_int(int i)
{
    for (auto& obs : observers)
        obs->doSomething(i);
}
void ISubject::set_float(float f)
{
    for (auto& obs : observers)
        obs->doSomething(f);
}

void ISubject::addObserver(IObserver* observer)
{
    observers.push_back(observer);
}