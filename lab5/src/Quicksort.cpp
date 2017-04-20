#include "Quicksort.hh"
using namespace std;
void swap(int i,int j, int *tab){
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}


void quicksort(int *tab, int left, int right,int dobor){
    int min = (left+right)/2;
    int i = left;
    int j = right;
    int pivot;
	
	srand(time(0));
	if(dobor==1)
	{
    	pivot = tab[min];

	}
	else if(dobor==2)
	{
	pivot=tab[left];
	
}
	else if(dobor==3)
	{
	pivot=tab[(int)rand()%1+right];	
	}
    while(left<j || i<right)
    {
        while(tab[i]<pivot)
        i++;
        while(tab[j]>pivot)
        j--;

        if(i<=j){
            swap(i,j,tab);
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(tab, left, j,dobor);
            if(i<right)
                quicksort(tab,i,right,dobor);
            return;
        }
    }
}
