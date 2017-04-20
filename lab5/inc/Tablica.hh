#ifndef TABLICA_HH
#define TABLICA_HH
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ITablica.hh"
class Tablica:public ITablica
{
	public:
		int *tab;
		int _rozmiar;

		const int& Rozmiar() const;
		void stworz(int);
		void wypelnij(int);
		void wyswietl(int);
		const int & operator()(const unsigned int&) const;
		int &  operator()(const unsigned int&);
		void run(int);
	
		virtual void PrzygotujDoTestu() { };


		Tablica(int rozmiar)
		{
			tab=new int[rozmiar];
			_rozmiar=rozmiar;
			srand(time(0));
			for(int i=1;i<rozmiar;i++)
				{
					tab[i]=1+rand()%rozmiar;
				}
		}
	
		~Tablica()
			{
				delete[] tab;
			}
	
};

	std::ostream& operator << (std::ostream&, const Tablica&);


#endif
