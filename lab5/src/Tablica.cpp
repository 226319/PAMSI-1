#include "Tablica.hh"
#include "Quicksort.hh"
using namespace std;
void Tablica::stworz(int rozmiar)
{
	tab=new int[rozmiar];
  	rozmiar=rozmiar;
}
void Tablica::wypelnij(int rozmiar)
{	srand(time(0));
	for(int i=1;i<rozmiar;i++)
	{
	tab[i]=1+rand()%rozmiar;
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
