#include "Stack.hh"
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
