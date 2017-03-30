#include <iostream>
#include <ctime>
using namespace std;
class wykonujaca {
public:
	virtual void wykonaj()=0;
};
class pomiar {
private:
	clock_t stop = 0;
	clock_t start = 0;
	int suma = 0;
	int czas = 0;
	
public:
	void zacznij_mierzyc();
	void zakoncz_mierzyc();
	void liczba_pomiarow();
	int liczba_pom;
};
void pomiar::zacznij_mierzyc() {
	start = clock();
}
void pomiar::zakoncz_mierzyc() {
	stop = clock();
	czas = (int)1000. / CLOCKS_PER_SEC*(stop - start);
	cout << "czas: " << czas << "ms" << endl;
}
void pomiar::liczba_pomiarow() {
	cout << "Podaj liczbe pomiarow" << endl;
	cin >> liczba_pom;
}
class mojatablica :public pomiar,public wykonujaca{
private:
	int *tablica = NULL;
	int rozmiar = 0;
	int dlugosc = 0;
	int powtorzenia = 0;
public:
	void wykonaj();
	void menu();
	void pobierz_dlugosc();
	void rozmiar_tablicy();
	void powieksz_jeden();
	void powieksz_razy();
	void dotnij(int dlugosc);
	void zeruj_tab();
	
};

void mojatablica::wykonaj() {
	menu();
	delete[]tablica;
	tablica = NULL;
}
void mojatablica::menu() {
	rozmiar_tablicy();
	int wybor;
	cout << "1: Powieksz tablice: wielkosc+1" << endl
		<< "2: Powieksz tablice: wilekosc*2" << endl;
	cin >> wybor;
	switch (wybor) {

	case 1:
		pobierz_dlugosc();
		liczba_pomiarow();
		for (int i = 0; i < liczba_pom; i++){
			zacznij_mierzyc();
			while (rozmiar != dlugosc) { 			//powiekszanie poki nie osiagnie conajmniej wilkosci zadanej
				powieksz_jeden();
			}
			zakoncz_mierzyc();
			zeruj_tab();
		}
		break;
	case 2:
		pobierz_dlugosc();
		liczba_pomiarow();
		for (int i = 0; i < liczba_pom; i++) {
			zacznij_mierzyc();
			while (dlugosc >= rozmiar) { 			//powiekszanie poki nie osiagnie conajmniej wilkosci zadanej
				powieksz_razy();
			}
			dotnij(dlugosc);		//docinanie do zadanej wielkosci
			zakoncz_mierzyc();
			zeruj_tab();
		}
		break;
	}
}
void mojatablica::pobierz_dlugosc() {
	cout << "podaj wielkosc docelowa" << endl;
	cin >> dlugosc;
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
void mojatablica::dotnij(int dlugosc) {

	int *bufor = new int[dlugosc];

	for (int i = 0; i < dlugosc; i++) {
		bufor[i] = tablica[i];
	}

	delete[]tablica;
	tablica = new int[dlugosc];

	for (int i = 0; i < dlugosc; i++) {
		tablica[i] = bufor[i];
	}

	delete[]bufor;
	rozmiar = dlugosc;
}
void mojatablica::zeruj_tab() {
	delete[]tablica;
	*tablica = NULL;
	rozmiar = 10;
	tablica = new int[rozmiar];
}

class liczba {
public:
	int wartosc;
	liczba *nastepna;
	liczba() {
		nastepna = NULL;
	}
};

class mojalista : public wykonujaca,public liczba,public pomiar{
public:
	liczba *pierwsza;
	void wykonaj();
	void dodaj_liczbe();
	//void usun_liczbe(int numer);
	//void wyswietl_liste();
	mojalista() {
		pierwsza = NULL;
	}
};

void mojalista::dodaj_liczbe() {
	liczba *nowa = new liczba;
	nowa->wartosc = 0;
	if (pierwsza == NULL) {
		pierwsza = nowa;
	}
	else {
		liczba *temp = pierwsza;
		while (temp->nastepna) {
			temp = temp->nastepna;
		}
		temp->nastepna = nowa;
		nowa->nastepna = NULL;
	}
}
void mojalista::wykonaj() {
  int dlugosc;
	cout << "jaka dlugosc" << endl;
	cin >> dlugosc;
  
	zacznij_mierzyc();
	for (int i = 0; i < dlugosc; i++) {
		dodaj_liczbe();
	}
	zakoncz_mierzyc();
}

int main() {
	mojalista lista ;
	mojatablica tablica;
	wykonujaca *obiekt;
	int wybor;
  
	cout << "lista: 1" << endl
		<< "tablica: 2" << endl;
	cin >> wybor;
  
	if (wybor == 1) {
		obiekt = &lista;
	}
	else if (wybor == 2) {
		obiekt = &tablica;
	}
	else return 0;
	
	obiekt->wykonaj();		

	return 0;
}
