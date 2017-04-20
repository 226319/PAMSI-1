#ifndef _MSTEST_HH
#define _MSTEST_HH

#include <iostream>
#include "MergeSort.hh"
#include "IRunnable.hh"
#include "Tablica.hh"



class MSTest : public Testowalny
{


	Tablica _tab;
	
	void WczytajTablice();

	public:

	MSTest(const unsigned int& Rozmiar);
	~MSTest();

	unsigned int Rozmiar() const;
	virtual void PrzygotujDoTestu();
	virtual void run(int);

};









#endif
