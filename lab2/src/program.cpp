
#include <iostream>
#include <ctime>
using namespace std;

class mojatablica {

public:
	void rozmiar_tablicy();
	void powieksz_jeden();
	void powieksz_razy();
	void usun_tab();
	void dotnij(int wielkosc);
	int rozmiar_tab();
	void zeruj();
private:
	int *tablica = NULL;
	int rozmiar = NULL;
};

void mojatablica::zeruj() {

	rozmiar = 10;
}

int mojatablica::rozmiar_tab() {

	return rozmiar;
}

void mojatablica::rozmiar_tablicy() {

	rozmiar = 10;
	tablica = new int[rozmiar];

}

void mojatablica::powieksz_jeden() {
	
	int *bufor = new int[rozmiar];

	for (int i = 0; i < rozmiar; i++) {
		bufor[i] = tablica[i];
	}
	delete[]tablica;

	tablica = new int[rozmiar + 1];
	for (int i = 0; i < rozmiar; i++) {
		tablica[i] = bufor[i];
	}
	delete[]bufor;
	rozmiar++;
}
void mojatablica::powieksz_razy() {
	
	int *bufor = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		bufor[i] = tablica[i];
	}
	delete[]tablica;

	tablica = new int[rozmiar * 2];
	for (int i = 0; i < rozmiar; i++) {
		tablica[i] = bufor[i];
	}
	delete[]bufor;
	rozmiar = rozmiar * 2;
}

void mojatablica::usun_tab() {
	delete[]tablica;
	tablica = NULL;
}

void mojatablica::dotnij(int wielkosc) {
	
		int *bufor = new int[wielkosc];

		for (int i = 0; i < wielkosc; i++) {
			bufor[i] = tablica[i];
		}

		delete[]tablica;
		tablica = new int[wielkosc];

		for (int i = 0; i < wielkosc; i++) {
			tablica[i] = bufor[i];
		}

		delete[]bufor;
		rozmiar = wielkosc;
}

int main() {

	mojatablica tab;
	int wielkosc;
	clock_t start, stop;
	int suma=0;
	int czas=0;

	tab.rozmiar_tablicy();								 //start od rozmiar 10

	cout << "podaj wielkosc docelowa" << endl;
	cin >> wielkosc;

	for (int i = 0; i < 20; i++) {						//20 pomiarow
		start = clock();
		while (tab.rozmiar_tab() != wielkosc) {			//powiekszanie poki nie osiagnie wilkosci zadanej
			tab.powieksz_jeden();
			
		}stop = clock();
		czas = (int)1000. / CLOCKS_PER_SEC*(stop - start);
		suma = suma + czas;
		cout<<"czas wykonania algorytmu: "
			<< czas<< "ms" << endl;
		tab.zeruj();											//zeruj rozmiar do 10
	}
	cout << "czas sredni: " << suma / 20 <<"ms"<< endl;
	suma = 0;
	czas = 0;
	
	for (int i = 0; i < 20; i++) {
		start = clock();
		while (wielkosc >= tab.rozmiar_tab()){ 			//powiekszanie poki nie osiagnie conajmniej wilkosci zadanej
			tab.powieksz_razy();
		} 
		tab.dotnij(wielkosc);							//docinanie do zadanej wielkosci
			stop = clock();
		czas = (int)1000. / CLOCKS_PER_SEC*(stop - start);
		suma = suma + czas;
		cout << "czas wykonania algorytmu: "
			<< czas << "ms" << endl;
		tab.zeruj();	 										//zeruj rozmiar do 10
	}
	cout << "czas sredni: " << suma / 20 << "ms" << endl;
	tab.usun_tab();												//zwalnianie poamieci
	return 0;
}
