#include "MSTest.hh"



MSTest::MSTest(const unsigned int& Rozmiar) {
		
	_tab = Tablica(Rozmiar);

}

MSTest::~MSTest(){}




void MSTest::WczytajTablice() {

	std::ifstream plik("tmp/TestTab.tmp");

	if ( plik.fail() ) {
		std::string wyjatek = "\nNie znaleziono: tmp/TestTab.tmp";
		throw wyjatek;
	}

	for ( unsigned int idx = 0; idx < _tab.Size(); ++idx ) {
		plik >> _tab.ZmienElement(idx);
		if ( plik.bad() ) {
			std::string wyjatek = "\nBlad odczytu: tmp/TestTab.tmp";
			throw wyjatek;
		}
	}

	plik.close();

}


MSTest& MSTest::operator=(const MSTest& TmpQs) {

	if ( this != &TmpQs ) 
		_tab = Tablica(TmpQs.Rozmiar());

	return *this;

}

unsigned int MSTest::Rozmiar() const {
	return _tab.Size();
}


void MSTest::PrzygotujDoTestu() {
 
	WczytajTablice();

}

void MSTest::Testuj(int zm2 ) {

	MergeSort(_tab,0,_tab.Rozmiar()-1);
	
}







