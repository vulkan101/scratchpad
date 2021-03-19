#include "PatternIdeas.h"
#include "observer/observer.h"
#include "observer/derived_observers.h"
#include "observer/subject.h"
using namespace std;

int main()
{	
	// main needs to know about derived classes but ISubject doesn't
	BasicObserver A("Observer A");
	FancyObserver B("Observer B");
	ISubject Subject;
	Subject.addObserver(&A);
	Subject.addObserver(&B);

	Subject.set_float(5.0f);
	Subject.set_int(10);

	return 0;
}
