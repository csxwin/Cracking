#include "Node.h"

Node::Node()
{
	//this allow creating new obeject without initialization
}

Node::Node(const char item, Node* ptrnext)
{
	this->data = item;
	//this->next = ptrnext;
	this->next = NULL;
}

Node* Node::NextNode()
{
	return this->next;
}

void Node::InsertAfter(Node *p)
{
	if(this->next!=NULL)
	{
		p->next=this->next;
	}
	this->next=p;
}

void Node::DeleteAfter(Node **end)
{
	Node* tempNode = next;
	if(next!=*end)
	{
		this->next=next->next;
	}
	else
	{
		this->next=NULL;
		*end=this;
	}
}

Node* GetNode(const char item, Node* nextptr = NULL)
{
	Node* newnode;
	newnode = new Node(item, nextptr);
	if(newnode == NULL)
	{
		cerr<<"memory allocation failed."<<endl;
		exit(1);
	}
	return newnode;
}


