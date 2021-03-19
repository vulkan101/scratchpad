#include "PatternIdeas.h"
#include "observer/observer.h"
#include "observer/derived_observers.h"
#include "observer/subject.h"

using namespace std;
using var = std::variant<int, float, std::string>;

namespace Observers
{
	std::vector<std::shared_ptr<IObserver>> created;

}
void createObservers()
{
	Observers::created.push_back(std::make_shared<BasicObserver>("SharedA"));
	Observers::created.push_back(std::make_shared<FancyObserver>("SharedB"));
}
void addObservers(LambdaSubject &subject)
{
	for (auto &obs : Observers::created)
	{
		// note we don't take a reference of obs. copying it means the closure
		// maintains a strong ref to the observer
		auto la = [obs](var variable) { obs->doSomething(variable);  };
		subject.addObserver(la);
	}
}
void clearObservers()
{
	Observers::created.clear();
}
int main()
{	
	// main needs to know about derived classes but ISubject doesn't
	BasicObserver A("Observer A");
	FancyObserver B("Observer B");
	ISubject Subject;
	std::cout << "<<< Adding basic class based observers >>>\n\n";
	Subject.addObserver(&A);
	Subject.addObserver(&B);

	Subject.set_float(5.0f);
	Subject.set_int(10);


	LambdaSubject LSubject;

	std::cout << "\n<<< Adding in scope lambda observers >>>\n";
	auto la = [&A](var variable) { A.doSomething(variable);  };
	auto lb = [&B](var variable) { B.doSomething(variable);  };
	auto idA = LSubject.addObserver(la);
	auto idB = LSubject.addObserver(lb);

	LSubject.set_float(111);
	LSubject.set_int(65.2f);
	std::cout << "\n<<< Adding out of scope shared lambda observers >>>\n";
	createObservers();
	addObservers(LSubject);
	LSubject.set_float(222);
	LSubject.set_int(165.2f);
	std::cout << "\n<<< Clearing list of shared lambda observers >>>\n";
	// because the lambda copies the shared_ptr, clearing the 
	// list of observers in Observers:: doesn't affect the lambdas
	clearObservers(); 
	LSubject.set_float(333);
	LSubject.set_int(15.2f);

	return 0;
}
