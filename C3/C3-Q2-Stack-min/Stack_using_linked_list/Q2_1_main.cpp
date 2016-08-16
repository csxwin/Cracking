#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int data;
	int min_below;
	struct node * next;
}node;   //!!!!!!!!!!!!!!! missed once. name and semicoma

node * new_node(int x)
{
	node * newnode = (node *) malloc (sizeof(struct node));
	newnode->data = x;
	newnode->min_below = newnode->data;
	newnode->next = NULL;
	return newnode;
}

void push(node ** top, int x)
{	
	node * newnode = new_node(x);
	if(*top!=NULL)
	{
		newnode->next = *top;
		newnode->min_below = newnode->data > (*top)->data ? (*top)->min_below : newnode->data;
	}
	*top = newnode;
}

int pop(node ** top)
{
	int x;
	if(*top!=NULL)
	{
		x = (*top)->data;
		*top = (*top)->next; //might not work
		return x;
	}
	else{
		return 999;
	}
}

int peek(node * top){
	if(top!=NULL)
	{
		return top->data;
	}
	else{
		return 999;
	}
}

int min(node * top){
	if(top!=NULL)
	{
		return top->min_below;
	}
	else{
		return 999;
	}
}

int main()
{
	node * top = NULL;
	int a;

	push(&top, 5);
	push(&top, 6);
	push(&top, 3);
	push(&top, 7);
	a = min(top); //3
	push(&top, 1);

	a = pop(&top);
	a = pop(&top);
	a = min(top); //3
	a = pop(&top);
	a = pop(&top);

	a = peek(top);
	
	a = pop(&top);

	

	return 1;
}