#include "List.hh"

void List::add() 
{
	NodeList *data = new NodeList;
		data->value = size;
		current->next = data;
		data->next = tail;
		current=data;
		size++;
}
void List::run(int lengthOfObject)
{
for(int i=0;i<lengthOfObject;i++){
			add();
	
}
find(lengthOfObject);
		head->next = current;
		current->next = tail;
		current->value = 1;
		size = 1;
}
int List::find(int lengthOfObject)
{
NodeList *temp=head->next;
while(temp->value!=lengthOfObject/2)
{
temp=temp->next;
}
return temp->value;
}
