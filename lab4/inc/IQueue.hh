#ifndef IQUEUE_HH
#define IQUEUE_HH
#include <iostream>
#include "IRunnable.hh"
class IQueue :public IRunnable
{
public:
	virtual void add(int value) = 0;
	virtual void run(int lengthOfObject) = 0;
	virtual int remove() = 0;
};
#endif
