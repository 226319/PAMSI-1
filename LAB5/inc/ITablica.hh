#ifndef ITABLICA_HH
#define ITABLICA_HH
#include <iostream>

class ITablica
{
public:
virtual ~ITablica() {};
virtual void stworz(int rozmiar)=0;
virtual void wypelnij(int)=0;
virtual void wyswietl(int)=0;
};
#endif
