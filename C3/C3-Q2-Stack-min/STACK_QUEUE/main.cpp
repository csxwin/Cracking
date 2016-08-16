#include <stdlib.h>
#include <stdio.h>

     

int *sp = (int *)malloc(sizeof(int));;

void push(int x)
{
	sp--;
	* sp = x;
}

int pop()
{
	int x = *sp;
	sp++;
	return x;
}

int main()
{
	//int * SP = (int *)malloc(sizeof(int));

	push(0);
	push(1);
	push(2);
	push(3);
	push(4);

	int a = pop();
	a = pop();
	a = pop();
	a = pop();
	a = pop();


	return 1;
}