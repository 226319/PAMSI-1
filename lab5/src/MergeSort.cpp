#include "MergeSort.hh"



void MergeSort(Tablica& array, const unsigned int& Poczatek, const unsigned int& Koniec) {

	if (Poczatek < Koniec) {

		unsigned int q = (Poczatek+Koniec)/2;

		MergeSort(array, Poczatek, q);
		MergeSort(array, q+1, Koniec);
		Merge(array,Poczatek,q,Koniec);
	
	}


}


void Merge( Tablica& array, const unsigned int& Poczatek, const unsigned int& Podzial, const unsigned int&  Koniec ) {

	unsigned int i = Poczatek;
	unsigned int k = Podzial+1;
	unsigned int idx = 0;

	int* tmp_tab = new int[Koniec-Poczatek+1];

	while ( i <= Podzial && k <= Koniec ) {
	
		if ( array(k) < array(i) ){
			
			tmp_tab[idx] = array(k);
			++k;	
		
		} else {

			tmp_tab[idx] = array(i);;
			++i;
		}
		++idx;
	}

	if ( i <= Podzial ) {
		for ( ; i <= Podzial; ++i, ++idx ) {
			tmp_tab[idx] = array(i);
		}
	} else {
		for ( ; k <= Koniec; ++k, ++idx) {
			tmp_tab[idx] = array(k);
		}
	}

	for ( i = 0; i < Koniec-Poczatek+1 ; ++i ){
		array(Poczatek+i) = tmp_tab[i];
	}

	delete [] tmp_tab;

}	










