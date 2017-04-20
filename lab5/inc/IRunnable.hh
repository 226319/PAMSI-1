#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH
#include <iostream>

using namespace std;
class IRunnable 
{
public:
	virtual void PrzygotujDoTestu()=0;
	virtual void run(int) = 0;
};
#endif
