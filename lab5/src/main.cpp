#include <iostream>
#include <ctime>
#include "IRunnable.hh"
#include "ITablica.hh"
#include "Tablica.hh"
#include "Clock.hh"
using namespace std;
int main()
{
	Clock watch;
	IRunnable *object;
	int rozmiar;
	cin>>rozmiar;	
	Tablica tab(rozmiar);
	object = &tab;
	watch.start(1, rozmiar, object);
	
	return 0;
}
