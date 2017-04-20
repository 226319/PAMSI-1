#ifndef STACK_HH
#define STACK_HH
#include <iostream>
#include "IStack.hh"
class NodeStack 
{
public:
	int value;
	NodeStack *next = NULL;
	
};

class Stack: public NodeStack,public IStack 
{
public:
	int count;
	NodeStack *top = NULL;
	int pop();
	void push(int value);
	void run(int lengthOfObject);
Stack()
{
count=0;
}
};
#endif
