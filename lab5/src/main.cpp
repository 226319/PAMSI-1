#include <iostream>
#include <ctime>
#include "IRunnable.hh"
#include "ITablica.hh"
#include "Tablica.hh"
#include "Clock.hh"
#include "MergeSort.hh"



#define ROZMIAR 10

using namespace std;
int main()
{
	
	Tablica tab(ROZMIAR);

	srand(time(NULL));
	
	for ( unsigned int i = 0; i < tab.Rozmiar(); ++i ) {	
		tab(i) = rand() % 101;
	}


	std::cerr << tab;
	
	std::cerr << std::endl;



	MergeSort(tab, 0, tab.Rozmiar()-1);



	std::cerr << tab;
	
	std::cerr << std::endl;




	/*
	
		
		
	Clock watch;
	IRunnable *object;
	
	cin>>rozmiar;	
	Tablica tab(rozmiar);
	object = &tab;
	watch.start(1, rozmiar, object);
*/	
	return 0;
}
