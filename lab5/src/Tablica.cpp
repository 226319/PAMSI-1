#include "Tablica.hh"
#include "Quicksort.hh"
using namespace std;
void Tablica::stworz(int rozmiar)
{
	tab=new int[rozmiar];
  	_rozmiar=rozmiar;
}
void Tablica::wypelnij(int rozmiar)
{	srand(time(0));
	for(int i=1;i<rozmiar;i++)
	{
	tab[i]=1+rand()%rozmiar;
	}
}

const int& Tablica::Rozmiar() const {
	return _rozmiar;
}

const int& Tablica::operator()( const unsigned int& idx ) const {
	
	if ( idx >= Rozmiar()  ) {
		std::string wyjatek = "\nPrzekroczono zakres\n";
		throw wyjatek;
	}
	

	return tab[idx];
}

int& Tablica::operator()(const unsigned int& idx ) {

	if ( idx >= Rozmiar()  ) {
		std::string wyjatek = "\nPrzekroczono zakres\n";
		throw wyjatek;
	}
	
	return tab[idx];
}





void Tablica::wyswietl(int rozmiar)
{
	for(int i=0;i<rozmiar;i++)
	{
	cout<<tab[i]<<", "<<endl;
	}
}
void Tablica::run(int rozmiar)
{	int pivot;
	cout<<"Polozenie pivota:"<<endl
	<<"Pierwszy element: wpisz '1'"<<endl
	<<"Srodek: wpisz '2'"<<endl
	<<"Randomowy: wpisz '3'"<<endl
	<<endl;
	cin>>pivot;
//stworz(rozmiar);
//wypelnij(rozmiar);
quicksort(tab,0,rozmiar-1,pivot);

}

std::ostream& operator<<(std::ostream& out,const Tablica& tab) {
	
	for ( unsigned int i = 0; i < tab.Rozmiar(); ++i) {
		out << tab(i) << ' ';		
	}

	return out;
}








