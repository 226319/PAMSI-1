#ifndef ISTACK_HH
#define ISTACK_HH
#include <iostream>
#include "IRunnable.hh"
class IStack:public IRunnable
{
public:
	virtual void push(int value) = 0;
	virtual void run(int lengthOfObject)  = 0;
	virtual int pop() = 0;
};
#endif
