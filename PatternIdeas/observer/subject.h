#pragma once 
#include <vector>
#include<functional>
#include <map>

#include <variant>

class IObserver;
 
class ISubject
{
public:
    virtual void set_int(int i);
    virtual void set_float(float f);
    
    void addObserver(IObserver* observer);    
    std::vector<IObserver*> observers;
};


using var = std::variant<int, float, std::string>;
using callback = std::function<void(var)>;

class LambdaSubject : public ISubject
{
public:
    void set_int(int i) override;
    void set_float(float f) override;

    uint32_t addObserver(callback cb);
protected:
    uint32_t _fn_id=0;    
    std::map<uint32_t, callback> _observers;
    
};