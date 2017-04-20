#ifndef LIST_HH
#define LIST_HH
#include <iostream>
#include "IList.hh"
class NodeList 
{
public:
	int value;
	NodeList *next = NULL;
};
class List :public NodeList, public IList
{
public:
	NodeList *head;
	NodeList *tail;
	NodeList *current;
	int size;
	void run(int lengthOfObject);
	void add();
	int find(int lengthOfObject);
	List()
	{
		head = new NodeList;
		tail = new NodeList;
		current = new NodeList;
		head->next = current;
		current->next = tail;
		current->value = 1;
		size = 1;
	}
};
#endif
