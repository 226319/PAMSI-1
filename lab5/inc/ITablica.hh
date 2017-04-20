#ifndef ITABLICA_HH
#define ITABLICA_HH
#include <iostream>
#include "IRunnable.hh"
class ITablica:public IRunnable
{
public:
virtual void stworz(int rozmiar)=0;
virtual void wypelnij(int)=0;
virtual void wyswietl(int)=0;
};
#endif
