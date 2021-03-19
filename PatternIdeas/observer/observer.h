#pragma once
#include <string>
#include <variant>
#include <functional>
using var = std::variant<int, float, std::string>;
using callback = std::function<void(var)>;

class IObserver
{
public:
    IObserver(std::string name) : name(name) {}
    std::string name;

    void doSomething(var v)
    {
        if (std::holds_alternative<int>(v))
            doSomething(std::get<int>(v));
        else if (std::holds_alternative<float>(v))
            doSomething(std::get<float>(v));
    }
    virtual void doSomething(int i)=0;
    virtual void doSomething(float f)=0;

    int intval = 0;
    float floatval = 0;
};

