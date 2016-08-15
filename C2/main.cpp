#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

struct node * head = NULL;

node * GetNewNode(int x)
{
	node * newnode = (node *)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void node_print()
{
	node * ptr = head;
	puts("linked list are:");
	while(ptr!=NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

void InsertAtHead()
{

}

void InsertAtTail(node ** head, int x)
{
	node * newnode = GetNewNode(x);
	node * node_ptr = *head;
	if(*head == NULL)
	{
		*head = newnode; //init creation
	}
	else{
		while(node_ptr->next!=NULL)
		{
			node_ptr = node_ptr->next;
		}
		node_ptr->next = newnode;
	}
}

node * delete_node(node * head, int x)
{
	node *n = head;
	if(n->data == x)
	{
		return head->next;
	}
	while(n->next!=NULL)
	{
		if(n->next->data==x)
		{
			n->next = n->next->next;
			break;
		}
		n = n->next;
	}
	return head;
}

void runner(node * head)
{
	node * ptr1 = head;
	node * ptr2 = head;
	node * temp;
	
	while(ptr2->next!=NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	temp = ptr1->next;
	ptr1->next = NULL; //terminate list. specifically, 5 next to null
	ptr1 = temp;
	ptr2 = head;
	do
	{
		temp = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr1->next;
		ptr2->next->next = temp;
		ptr2 = temp;
	}while(ptr1!=NULL);
}

void Q1(node * head)
{
	node * ptr1 = head;
	node * ptr2 = head;
	while(ptr1->next!=NULL)
	{
		ptr2 = ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr2->next->data==ptr1->data)
			{
				ptr2->next = ptr2->next->next;
			}
			if(ptr2->next!=NULL)
			{
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

node * Q2(node * head, int k)
{
	int length = 0;
	int i = 0;
	node * ptr = head;
	while(ptr!=NULL)
	{
		ptr = ptr->next;
		length++;
	}
	ptr = head;
	while(i++<length-1-k)
	{
		ptr=ptr->next;
	}
	return ptr;
}

void Q4(node * head, int x)
{
	node * ptr = head;
	node * temp_head = NULL;
	node * temp_ptr = temp_head;
	node * middle_ptr;
	if(ptr->data > x)
	{
		head = head->next;
		temp_head = ptr;
		temp_head->next = NULL;
	}
	while(ptr->next!=NULL)
	{
		if(ptr->next->data > x)
		{
			if(temp_head == NULL)
			{
				temp_head = ptr->next;
				ptr->next = ptr->next->next; 
				temp_head->next = NULL;
				temp_ptr = temp_head;
			}
			else{
				while(temp_ptr->next!=NULL)
				{
					temp_ptr = temp_ptr->next;
				}
				temp_ptr->next = ptr->next;
				ptr->next = ptr->next->next; 
				temp_ptr->next->next = NULL;
			}
			//delete from current list
		}
		else
		{
			ptr = ptr->next;
		}
	}
	ptr = head;
	while(ptr->next!=NULL)
	{
		if(ptr->next->data == x)
		{
			middle_ptr = ptr->next;
			ptr->next = ptr->next->next;
			middle_ptr->next = temp_head;
		}
		if(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
	}
	ptr->next = middle_ptr;
	puts("after repartition...");
	node_print();
}

node * Q5_1(node* digit1, node * digit2)
{
	int N1 = 0;
	int N2 = 0;
	int w = 1;
	node * output = NULL;
	node * ptr = digit1;
	while(ptr!=NULL)
	{
		N1 += ptr->data * w;
		ptr = ptr->next;
		w = w * 10;
	}
	w = 1;
	ptr = digit2;
	while(ptr!=NULL)
	{
		N2 += ptr->data * w;
		ptr = ptr->next;
		w = w * 10;
	}
	if((N1+N2) < 1000)
	{
		InsertAtTail(&output, ((N1 + N2) % 100) % 10);
		InsertAtTail(&output, ((N1 + N2) % 100) / 10);
		InsertAtTail(&output, (int)((N1 + N2) / 100));
	}
	return output;
}

node * Q6(node * list)
{
	node * ptr1 = list;
	node * ptr2 = list;
	int loop_len_max = 100;
	int timeout = 100;
	int n = 0;
	int repeat = 0;
	int m = 0;
	while(m++ < timeout)
	{
		n = loop_len_max;
		ptr2 = ptr1->next;
		while(n-->0)
		{
			if( ptr2->data == ptr1->data )
			{
				repeat++;
			}
			ptr2 = ptr2->next;
		}
		if(repeat > 10){
			return ptr1;
		}
		ptr1 = ptr1->next;
	}
	return NULL;
}

node * reverse(node * list)
{
	node * reverse_list = NULL;
	int list_length = 0;
	int i = 0;
	int j = 0;
	node * ptr = list;
	while(ptr!=NULL)
	{
		ptr = ptr->next;
		list_length++;
	}
	for(i = 0; i<= list_length-1; i++)
	{
		ptr = list;
		for(j = 0; j< list_length-i-1; j++)
		{
			ptr=ptr->next;
		}
		InsertAtTail(&reverse_list, ptr->data);
	}
	return reverse_list;
}

int Q7(node * list)
{
	node * reverse_list = reverse(list);
	node * ptr1 = reverse_list;
	node * ptr2 = list;
	while(ptr1!=NULL)
	{
		if(ptr1->data != ptr2->data)
		{
			return 0;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return 1;
}

int main()
{
	for(int i = 0; i <= 10; i++){
		InsertAtTail(&head, i);
	}

/**
Q3
**/
	//node_print();
	//delete_node(head, 5);
	//node_print();
/**
runner
**/
	runner(head);
	puts("perform runner...");
	node_print();
/**
Q1
**/
	InsertAtTail(&head, 10);
	InsertAtTail(&head, 3);
	InsertAtTail(&head, 4);
	InsertAtTail(&head, 8);
	puts("new list");
	node_print();
	Q1(head);
	puts("remove duplication");
	node_print();

/**
Q2
**/
	Q2(head, 3);

/**
Q4
**/
	Q4(head, 5);

/**
Q5
**/
	node * digit1 = NULL;
	node * digit2 = NULL;
	node * output = NULL;
	InsertAtTail(&digit1, 7);
	InsertAtTail(&digit1, 1);
	InsertAtTail(&digit1, 6);
	InsertAtTail(&digit2, 5);
	InsertAtTail(&digit2, 9);
	InsertAtTail(&digit2, 2);
	output = Q5_1(digit1, digit2);

/**
Q6
**/
	node * list = NULL;
	InsertAtTail(&list, 1);
	InsertAtTail(&list, 2);
	InsertAtTail(&list, 3);
	InsertAtTail(&list, 4);
	InsertAtTail(&list, 5);
	InsertAtTail(&list, 6);
	node * ptr = list;
	node * loop_start;
	while(ptr->next!=NULL)
	{
		if(ptr->data == 4)
		{
			loop_start = ptr;
		}
		ptr = ptr->next;
	}
	ptr->next = loop_start; //inject corruption.

	ptr = list;

	ptr = Q6(list);

/**
Q7
**/
	node * Plist = NULL;
	InsertAtTail(&Plist, 1);
	InsertAtTail(&Plist, 6);
	InsertAtTail(&Plist, 4);
	InsertAtTail(&Plist, 6);
	InsertAtTail(&Plist, 2);
	int P = Q7(Plist);

	return 0;
}