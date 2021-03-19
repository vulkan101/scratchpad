#pragma once 
#include <vector>

class IObserver;
 
class ISubject
{
public:
    void set_int(int i);
    void set_float(float f);
    
    void addObserver(IObserver* observer);
    std::vector<IObserver*> observers;
};