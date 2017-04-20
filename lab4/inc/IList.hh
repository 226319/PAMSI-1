#ifndef ILIST_HH
#define ILIST_HH
#include <iostream>
#include "IRunnable.hh"
class IList:public IRunnable
{
public:
	virtual void add() = 0;
	virtual void run(int lengthOfObject)  = 0;
	virtual int find(int lengthOfObject)=0;
};
#endif
