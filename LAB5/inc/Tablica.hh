#ifndef TABLICA_HH
#define TABLICA_HH
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ITablica.hh"
#include "IRunnable.hh"

class Tablica:public ITablica, IRunnable
{
	public:
		int *tab;
		unsigned int _rozmiar;

		const unsigned int& Rozmiar() const;
		void stworz(int);
		void wypelnij(int);
		void wyswietl(int);
		const int & operator()(const unsigned int&) const;
		int &  operator()(const unsigned int&);
		Tablica& operator= ( const Tablica& );
		void run(int);
	
		virtual void PrzygotujDoTestu(){};

		Tablica();
		Tablica(const unsigned int&);
		~Tablica();
	
};

	std::ostream& operator << (std::ostream&, const Tablica&);


#endif
