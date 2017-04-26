#include "MSTest.hh"



MSTest::MSTest(const int& Rozmiar) {
		
	_tab = Tablica(Rozmiar);

}


MSTest::~MSTest(){}




void MSTest::WczytajTablice() {

	std::ifstream plik("tmp/TestTab.tmp");

	if ( plik.fail() ) {
		std::string wyjatek = "\nNie znaleziono: tmp/TestTab.tmp";
		throw wyjatek;
	}

	for ( unsigned int idx = 0; idx < _tab.Rozmiar(); ++idx ) {
		plik >> _tab(idx);
		if ( plik.bad() ) {
			std::string wyjatek = "\nBlad odczytu: tmp/TestTab.tmp";
			throw wyjatek;
		}
	}

	plik.close();

}


unsigned int MSTest::Rozmiar() const {
	return _tab.Rozmiar();
}


void MSTest::PrzygotujDoTestu() {
 
	WczytajTablice();

}

void MSTest::run(int zm2 ) {

	MergeSort(_tab,0,_tab.Rozmiar()-1);
	
}



