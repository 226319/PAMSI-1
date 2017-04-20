#ifndef QUEUE_HH
#define QUEUE_HH
#include <iostream>
#include"IQueue.hh"
class NodeQueue
{
public:
	int value;
	NodeQueue *next = NULL;
};

class Queue : public NodeQueue, public IQueue 
{
public:
	NodeQueue *head;
	NodeQueue *tail;
	void add(int value);
	int size;
	void run(int lengthOfObject);
	int remove();
	Queue()
	{	size=0;
		head = NULL;
		tail = NULL;
	
	}
};
#endif
