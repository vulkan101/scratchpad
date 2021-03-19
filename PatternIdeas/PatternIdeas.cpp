#include "PatternIdeas.h"
#include "observer/observer.h"
#include "observer/derived_observers.h"
#include "observer/subject.h"

using namespace std;
using var = std::variant<int, float, std::string>;
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


	LambdaSubject LSubject;
	var test(5.3f);
	B.doSomething(test);

	auto la = [&A](var variable) { A.doSomething(variable);  };
	auto lb = [&B](var variable) { B.doSomething(variable);  };
	auto idA = LSubject.addObserver(la);
	auto idB = LSubject.addObserver(lb);

	LSubject.set_float(111);
	LSubject.set_int(65.2f);


	return 0;
}
