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

void LambdaSubject::set_int(int i)
{
    var myval(i);
    for (auto& itr : _observers)
        itr.second(myval);
}



void LambdaSubject::set_float(float f)
{
    var myval(f);
    for (auto& itr : _observers)
        itr.second(myval);
}

uint32_t LambdaSubject::addObserver(callback cb)
{
    _observers.emplace(++_fn_id, std::move(cb));
    return _fn_id;
}
