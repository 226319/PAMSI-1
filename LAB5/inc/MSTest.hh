#ifndef _MSTEST_HH
#define _MSTEST_HH

#include <iostream>
#include <fstream>
#include "MergeSort.hh"
#include "IRunnable.hh"
#include "Tablica.hh"



class MSTest: public IRunnable {


	Tablica _tab;
	
	void WczytajTablice();

	public:

	MSTest(const int& Rozmiar);
	~MSTest();

	unsigned int Rozmiar() const;
	virtual void PrzygotujDoTestu();
	virtual void run(int);

};









#endif
