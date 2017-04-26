#include <iostream>
#include <ctime>
#include <cmath>
#include "IRunnable.hh"
#include "ITablica.hh"
#include "Tablica.hh"
#include "Clock.hh"
#include "MergeSort.hh"
#include "MSTest.hh"
#include "Funkcje.hh"

#define ROZMIAR 10
#define MAKS_WYK 8
#define LICZBA_REALIZACJI 20
#define TYP_DANYCH 3

using namespace std;
int main()
{

		
	Clock watch;

	for ( int i = 1; i <= TYP_DANYCH; ++i ) {

			std::cout << "Typ Danych: " << i << std::endl;

		for ( int idx = 1; idx < MAKS_WYK; ++idx) {
			int rozmiar = pow(ROZMIAR,idx);	
			MSTest SortTest(rozmiar);

			PrzygotujDane(rozmiar,1);
			SortTest.PrzygotujDoTestu();
			std::cout << rozmiar << std::endl;
			watch.start(LICZBA_REALIZACJI,rozmiar, SortTest);
		
		}
	}
	
	return 0;
}
