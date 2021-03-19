#include "observer.h"

#include <iostream>

// nothing to see here.. moved to derived
callback IObserver::provide_callback()
{    
    return [this](var variable) { doSomething(variable);  };
}