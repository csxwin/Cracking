#include "Node.h"
#include "MyStack.h"
#include<iostream>
using namespace std;
/*
public class EmptyStackException
{
   
}
*/

#define max_stack_size 5

int stackSize=5;
int *buffer=new int [stackSize*3];
int stackPointer[]={-1,-1,-1};

void push(int stackNum, int value)
{
	if(stackPointer[stackNum]+1>stackSize){cout<<"stack full"<<endl;}
	else{
		stackPointer[stackNum]++;
		buffer[stackNum*stackSize+stackPointer[stackNum]]=value;
	}
}

bool IsEmpty(int stackNum)
{
	bool IsTrue = false;
	if(stackPointer[stackNum]==-1)
	{
		IsTrue=true;
	}
	return IsTrue;
}

int pop(int stackNum) //throw Exception
{
	if(IsEmpty(stackNum))
	{
		//throw new EmptyStackException();
	}
	int value=buffer[stackNum*stackSize+stackPointer[stackNum]];
	buffer[stackNum*stackSize+stackPointer[stackNum]]=0;
	stackPointer[stackNum]--;
	return value;
}

int peek(int stackNum) //throw Exception
{
	if(IsEmpty(stackNum))
	{
		//throw new EmptyStackException();
	}
	return buffer[stackNum*stackSize+stackPointer[stackNum]];
}

void test()
{
	bool i=true;
	if(i){throw 20;}
}

/**
Q3
**/
class SetOfStacks
{
public:
	void init();
	stack stack_create(char x);
	void push(char s);
	char pop();
	char popAt(int index);
private:
	stack stack_array[10]; //array of stacks
	int N;                 //current active stack
};

stack SetOfStacks::stack_create(char X)
{
	stack s;
	s.init();
	s.push(X);
	return s;
}

void SetOfStacks::init()
{
	N = 0;
	for(int i = 0; i < 10; i++)
	{
		stack_array[i].top = NULL;
	}
}

void SetOfStacks::push(char X)
{
	if(stack_array[0].top == NULL)
	{
		stack_array[0] = stack_create(X);
	}
	else if(stack_array[N].length >= max_stack_size)
	{
		stack_array[++N] = stack_create(X);
	}
	else
	{
		stack_array[N].push(X);
	}
}

char SetOfStacks::pop()
{
	if(stack_array[0].top == NULL)
	{
		return 0x7F;
	}
	else if(stack_array[N].length == 0)
	{
		stack_array[N--].top = NULL;
		return stack_array[N].pop();
	}
	else
	{
		return stack_array[N].pop();
	}
}

char SetOfStacks::popAt(int index)
{
	if(stack_array[index].length == 0)
	{
		return 0x7F;
	}
	{
		return stack_array[index].pop();
	}
}

void main()
{
	/*stack s1;
	char s[]="abcde";
	char *p=s;
	int count=0;
	do
	{
		s1.push(*p);
		count++;
	}while(*(++p)!='\0');
	for(int i=1;i<=count;i++)
	{
		cout<<s1.peek()<<endl;
		s1.pop();
	}*/
	int i =0;

	stack s1;
	s1.init();
	s1.push(0x10);
	s1.push(0x15);
	s1.push(0x25);
	s1.push(0x35);
	char a = s1.pop();
	a = s1.pop();
	a = s1.pop();
	a = s1.pop();


	char test_pattern[50];
	for(int i = 0; i < 50; i++)
	{
		test_pattern[i]= i;
	}
	
	SetOfStacks stacks;
	stacks.init();

	for(int i = 0; i < 50; i++)
	{
		stacks.push(test_pattern[i]);
	}

	a = stacks.popAt(9);
	a = stacks.popAt(8);

	for(int i = 0; i < 48; i++)
	{
		printf("%d ", stacks.pop());
	}

	getchar();
}