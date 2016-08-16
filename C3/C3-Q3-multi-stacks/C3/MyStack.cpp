#include "MyStack.h"
#include "Node.h"


void stack::push(char item)
{
	Node *p1=new Node();
	p1->data=item;
	p1->next=top;
	length++;
	top=p1;
}

void stack::init()
{
	length = 0;

}

char stack::peek()
{
	return top->data;
}
	
char stack::pop()
{
	if(top!=NULL)
	{
			char item=top->data;
			top=top->next;
			length--;
			return item;
	}
	return 'c';
}
