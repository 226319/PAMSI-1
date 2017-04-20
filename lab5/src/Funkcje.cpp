#include "Funkcje.hh"


void PrzygotujDane(const unsigned int& LiczbaElem, const unsigned int& Tryb ) {
	
	std::ofstream plik("tmp/TestTab.tmp");

	srand(time(NULL));	
	
	switch ( Tryb ) {

		case 1:
			for ( unsigned int idx = 0; idx< LiczbaElem; ++idx ) {
				plik << idx << ' ';
			}
			break;
	
		case 2:
			for ( unsigned int idx = 0; idx< LiczbaElem; ++idx ) {
				plik << rand() % 101 << ' ';
			}
			break;
		
		case 3:
			for ( unsigned int idx = LiczbaElem; idx > 0; --idx ) {
				plik << 4 << ' ';
			}
			break;
	
		default:
			std::string wyjatek = "\nBledny tryb";

	}

	plik.close();

}


