// linkListReversal.cpp : Defines the entry point for the console application.
//

#include "stdio.h"


typedef struct list_node{
	struct list_node *next;
	int data;
}Node;

Node* reverseLL ( Node *head )
{
	if( !head )
		return NULL;
	Node *prev = NULL;
	while( head!=NULL) {
		Node *next = head->next;
		head->next = prev;
		
		prev = head;
		head = next;
	}
	return prev;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *head=NULL,*temp=NULL,*prev=NULL;
	for( int i=0;i<5;i++ )
	{
		if( head == NULL)
		{
			
			temp = new Node();
			temp->data = i;
			head = temp;
			prev = temp;
		}
		else
		{
			temp = new Node();
			temp->data = i;
			prev->next = temp;
			prev = temp;
		}
		temp = temp->next;
		//printf("%d\n",temp->data);
	
	}
	for( Node *iter = head;iter != NULL;iter = iter->next )
		printf("%d\n",iter->data );
	printf("Reverse\n");
	head = reverseLL( head );

	for( Node *iter=head;iter!=NULL;iter=iter->next)
		printf("%d\n",iter->data);
	getchar();
	return 0;
}

