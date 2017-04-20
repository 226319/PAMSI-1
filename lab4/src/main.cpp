#include <iostream>
#include <ctime>
#include "IRunnable.hh"
#include "IList.hh"
#include "List.hh"
#include "IQueue.hh"
#include "Queue.hh"
#include "IStack.hh"
#include "Stack.hh"
#include "Clock.hh"
using namespace std;
int main()
{
	Clock watch;
	List lista;
	Stack stos;
	Queue kolejka;
	IRunnable *object;
	int rozmiar;
	cin>>rozmiar;
	object = &stos;
	watch.start(10, rozmiar, object);
	
	return 0;
}
