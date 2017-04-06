#include <iostream>
#include <ctime>
using namespace std;
class IRunnable 
{
public:
	virtual void run(int lengthOfObject) = 0;
};
class IList:public IRunnable 
{
public:
	virtual void add() = 0;
	virtual void run(int lengthOfObject)  = 0;
};
class NodeList 
{
public:
	int value;
	NodeList *next = NULL;
	NodeList *prev = NULL;
};
class List :public NodeList, public IList
{
public:
	NodeList *head = new NodeList;
	NodeList *tail = new NodeList;
	NodeList *current = new NodeList;
	int size;
	void run(int lengthOfObject);
	void add();
	List()
	{
		
		current->prev = head;
		current->next = tail;
		current->value = 1;
		head->next = current;
		tail->prev = current;
		size = 1;
	}
};
void List::add() 
{
	NodeList *data = new NodeList;
		data->value = 1;
		current->next = data;
		tail->prev = data;
		data->prev = current;
		data->next = tail;
		size++;
}
void List::run(int lengthOfObject)
{
			add();
}
class NodeStack 
{
public:
	int value;
	NodeStack *next = NULL;
	
};
class IStack:public IRunnable
{
public:
	virtual void push(int value) = 0;
	virtual void run(int lengthOfObject)  = 0;
	virtual int pop() = 0;
};
class Stack: public NodeStack,public IStack 
{
public:
	int count = 0;
	NodeStack *top = NULL;
	int pop();
	void push(int value);
	void run(int lengthOfObject);
};
void Stack::push(int value)
{
	NodeStack *data = new NodeStack;
	if (top == NULL)
	{
		data->value = value;
		data->next = NULL;
	}
	else
	{
		data->value = value;
		data->next = top;
	}
	top = data;
	count++;
}
void Stack::run(int lengthOfObject)
{
	for (int i = 1; i < lengthOfObject + 1; i++)
	{
		value = i;
		push(value);
	}
	while (value != 1)
	{
		value = pop();
	}
	top = NULL;
}
	

int Stack::pop()
{
	NodeStack *old = top;
	top = top->next;
	count--;
	return top->value;
	delete old;
}

class NodeQueue
{
public:
	int value;
	NodeQueue *next = NULL;
};
class IQueue :public IRunnable
{
public:
	virtual void add(int value) = 0;
	virtual void run(int lengthOfObject) = 0;
	virtual int remove() = 0;
};
class Queue : public NodeQueue, public IQueue 
{
public:
	NodeQueue *head;
	NodeQueue *tail;
	void add(int value);
	int size = 0;
	void run(int lengthOfObject);
	int remove();
	Queue()
	{
		head = NULL;
		tail = NULL;
	
	}
};
void Queue::add(int value) 
{
		NodeQueue *data = new NodeQueue;
		data->next = NULL;
		if (head == NULL) 
		{
			head = data;
			data->value = value;

		}
		else
		{
			data->value = value;
			tail->next = data;
		}
		tail = data;
		size++;
}
int Queue::remove() 
{
	NodeQueue *temp = new NodeQueue;
	if (head == NULL) 
	{
		cout << "kolejka jest pusta" << endl;
		return 0;
	}
	else 
	{
		temp = head;
		head = head->next;
		return temp->value;
		delete temp;
	}
}
void Queue::run(int lengthOfObject)
{
	for (int i = 1; i < lengthOfObject+1; i++)
		{
		value = i;
		add(value);	
	}
	
	while(value==lengthOfObject+1)
	{
		value=remove();
	}
	tail = NULL;
	head = NULL;
}
class Clock
{
private:
	clock_t stopTime = 0;
	clock_t startTime = 0;
	int sum=0;
	int time=0;
	int average=0;
	
public:
	void clockStart();
	void clockStop();
	void countAverage(int numberOfMeasure);
	void start(int numberOfMeasure, int length,IRunnable *object);
};
void Clock::clockStart()
{
	startTime = clock();
}
void Clock::clockStop()
{
	stopTime = clock();
}
void Clock::countAverage(int numberOfMeasure)
{
	average = sum / numberOfMeasure;
	cout << "Czas wykonania: " << average << "ms" << endl;
	sum = 0;
}
void Clock::start(int numberOfMeasure, int lengthOfObject,IRunnable *object) 
{
	for (int j = 0; j < numberOfMeasure; j++) 
	{
		clockStart();
		
			object->run(lengthOfObject);
		
		clockStop();
		time = (int)1000. / CLOCKS_PER_SEC*(stopTime - startTime);
		sum = sum + time;
	}
	countAverage(numberOfMeasure);
}
int main()
{
	Clock watch;
	List lista;
	Stack stos;
	Queue kolejka;
	IRunnable *object;

	object = &kolejka;
	watch.start(5, 1000, object);
	
	return 0;
}
