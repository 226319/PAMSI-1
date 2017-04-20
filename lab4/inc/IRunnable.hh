#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH
#include <iostream>

using namespace std;
class IRunnable 
{
public:
	virtual void run(int lengthOfObject) = 0;
};
#endif
