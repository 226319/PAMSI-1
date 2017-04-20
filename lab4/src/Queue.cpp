#include "Queue.hh"
using namespace std;
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
