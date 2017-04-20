#ifndef _MERGESORT_HH
#define _MERGESORT_HH


#include <iostream>
#include <cstdlib>
#include "Tablica.hh"



void MergeSort(Tablica&, const unsigned int&, const unsigned int&);
void Merge(Tablica&, const unsigned int&, const unsigned int&, const unsigned int&);

void Swap( Tablica&, const unsigned int&, const unsigned int& );



#endif
