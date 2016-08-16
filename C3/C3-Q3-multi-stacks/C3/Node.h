#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

class Node{
	friend class list;
	friend class stack;
public:
	Node();
	Node(const char item, Node* ptrnext = NULL);
	
	Node* NextNode();
	void InsertAfter(Node* p);
	void DeleteAfter(Node **end);
	Node* GetNode(const char item, Node* nextptr = NULL);
private:
	Node * next;
	char data;
};

#endif
