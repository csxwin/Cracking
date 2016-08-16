#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int data;
	struct node * next;
}node;   //!!!!!!!!!!!!!!! missed once. name and semicoma

node * min_top = NULL;

int peek(node * top){
	if(top!=NULL)
	{
		return top->data;
	}
	else{
		return 0x7FFFFFFF;
	}
}

node * new_node(int x)
{
	node * newnode = (node *) malloc (sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void min_stack_push(int x)
{
	node * newnode = new_node(x);
	if(min_top!=NULL){
		newnode->next = min_top;
	}
	min_top = newnode;
}

void push(node ** top, int x)
{	
	node * newnode = new_node(x);
	if(*top!=NULL)
	{
		newnode->next = *top;
		if(newnode->data <= peek(min_top))
		{
			min_stack_push(newnode->data);
		}
	}
	else{
		min_stack_push(newnode->data);
	}
	*top = newnode;
}

void min_stack_pop()
{
	if(min_top!=NULL)
	{
		min_top = min_top->next;
	}
}

int pop(node ** top)
{
	int x;
	if(*top!=NULL)
	{
		x = (*top)->data;
		*top = (*top)->next; //might not work
		if(x <= peek(min_top))
		{
			min_stack_pop();
		}
		return x;
	}
	else{
		return 999;
	}
}


int min(node * top){
	if(top!=NULL)
	{
		return top->data;
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
	push(&top, 1);
	push(&top, 3);
	push(&top, 7);
	a = min(min_top); //1
	push(&top, 1);

	a = pop(&top);
	a = pop(&top);
	a = min(min_top); //1
	a = pop(&top);
	a = pop(&top);

	a = peek(top);
	
	a = pop(&top);
	a = pop(&top);

	return 1;
}