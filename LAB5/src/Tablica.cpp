#include "Tablica.hh"
#include "Quicksort.hh"
using namespace std;


Tablica::Tablica(const unsigned int& rozmiar) {
	
		if ( rozmiar <= 0 ) {
			std::string wyjatek = "\nZly rozmiar\n";
			throw wyjatek;
		}

		tab=new int[rozmiar];
		_rozmiar=rozmiar;

		for(unsigned int i = 0; i < rozmiar; ++i){
				tab[i]=0;
		}
	}

Tablica::Tablica() {

 tab = nullptr;
 _rozmiar = 0;

}

Tablica::~Tablica() {
	
	delete[] tab;
	tab = nullptr;
}


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

const unsigned int& Tablica::Rozmiar() const {
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

Tablica& Tablica::operator = ( const Tablica& DoSkopiowania) {

	if ( this != & DoSkopiowania ) {

		tab = new int[DoSkopiowania.Rozmiar()];
		_rozmiar = DoSkopiowania.Rozmiar();

		for ( unsigned int i = 0; i < DoSkopiowania.Rozmiar(); ++i ) {
			tab[i] = DoSkopiowania(i);
		}
	}
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








