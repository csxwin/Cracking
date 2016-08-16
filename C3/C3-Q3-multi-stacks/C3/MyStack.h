#ifndef STACK_H
#define STACK_H

#include"Node.h"

class Node;
class stack{
public:	Node *top; 
		void init();
		int  length;
		char pop();
		void push(char s);
		char peek();
};

#endif
