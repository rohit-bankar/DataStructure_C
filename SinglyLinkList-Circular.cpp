// SinglyLinkList-Circular.cpp : Defines the entry point for the console application.

//
#include "stdafx.h"
#include "stdio.h"
#include "iostream"

using namespace std;

//https://codeforwin.org/2015/10/c-program-to-insert-node-in-doubly-linked-list.html

typedef struct NODE
{
	int iData;
	NODE *next;

}node;

node *first;

void CreateCircularSinglyLinkList(int n);
void DisplayCircularSinglyLinkList();
void SearchNodeInCircularSLL(int key);

void InsertNodeAtBegin(int iElement);
void InsertNodeAtPosition(int iElement ,int iPos);

void DeleteNode(int key);

void ReverseCircularSLL();

int _tmain(int argc, _TCHAR* argv[])
{
	int n=0,data,choice=1;
	first=NULL;

	while( choice != 0 )
	{
		cout<<"\n====================Circular Singly Link List========================="<<endl;
		cout<<"Choice 1) Create List"<<endl;
		cout<<"Choice 2) Display List and node count"<<endl;
		cout<<"Choice 3) Search in List"<<endl;
		cout<<"Choice 4) Insert at beging"<<endl;
		cout<<"Choice 5) Insert at given position"<<endl;
		cout<<"Choice 6) Delete node"<<endl;
		cout<<"Choice 7) Reverse list"<<endl;
		cout<<"Choice 0) Exit"<<endl;
		cout<<"\n"<<endl;
		cout<<"\n"<<endl;

		cout<<"Please Enter choice::";
		cin>>choice;

		switch(choice)
		{
			case 1:
					cout<<"Enter node count to create:"<<endl;
					cin>>n;
					CreateCircularSinglyLinkList(n);

					break;
			case 2:
					DisplayCircularSinglyLinkList();
					break;
			case 3:
					cout<<"Enter node to search in list::";
					cin>>data;
					SearchNodeInCircularSLL(data);
					break;
			case 4:
					cout<<"Enter node to insert at begining of list::";
					cin>>data;

					InsertNodeAtBegin(data);
					break;

			case 5:
					cout<<"Enter position of list where to insert::";
					cin>>n;

					cout<<"Enter node to insert at given position of list::";
					cin>>data;

					InsertNodeAtPosition(data,n);
					break;
			case 6:
				    cout<<"Enter node to delete";
					cin>>data;

				    DeleteNode(data);

			case 7:
					ReverseCircularSLL();
					break;

			default:
					cout<<"invalid choice..Please "<<endl;
					break;
		}
	}

	return 0;
}



void CreateCircularSinglyLinkList(int n)
{
	int data=0;
	node *newnode,*prevnode;
	newnode=NULL;
	prevnode=NULL;

	if( n >= 1 )
	{
        first=(node *)malloc(sizeof(node));

		cout<<"Enter Data for node 1::";
		cin>>data;

		first->iData=data;
		first->next=NULL;

		prevnode=first;

		for(int i=2 ; i<=n ; i++ )
		{
			newnode=(node *)malloc(sizeof(node));

			cout<<"Enter Data for node "<<i<<"::";
			cin>>data;

			newnode->iData=data;
			newnode->next=NULL;

			prevnode->next=newnode;

			prevnode=newnode;
		}
		prevnode->next=first;
	}
}
void DisplayCircularSinglyLinkList()
{
	node *curr;
	int nodecount=0;

	if( first == NULL )
	{
		cout<<"List is empty........."<<endl;
	}
	else
	{
		curr=first;
		do
		{
			cout<<">>"<<curr->iData<<">>";
			nodecount++;
			curr=curr->next;

		}while( curr != first );

		cout<<"\nCircular Linked List node Count::"<<nodecount<<endl;
	}
}

void SearchNodeInCircularSLL(int key)
{
	node *curr;
	int nodecount=0;

	if( first == NULL )
	{
		cout<<"List is empty........."<<endl;
	}
	else
	{
		curr=first;
		do
		{
			 nodecount++;
			 if(curr->iData==key)
			 {
				 cout<<"Node Found at" <<nodecount<<endl;
				 return;
			 }

			 curr=curr->next;

		}while( curr != first );

		cout<<"Node not found"<<endl;
	}
}

void InsertNodeAtBegin(int iElement)
{
	node *newnode,*current;

	if(first==NULL)
	{
		cout<<"List is empty...."<<endl;
	}
	else
	{
		newnode=(node *)malloc(sizeof(node));

		newnode->iData=iElement;
		newnode->next=first;

		current=first;
		while(current->next != first)
		{
			current=current->next;
		}

		current->next=newnode;

		first=newnode;

		cout<<"Node inserted at begining"<<endl;
	}
}

void InsertNodeAtPosition(int iElement ,int iPos)
{
	node *newnode,*current;

	if( iPos==1 )
	{
		InsertNodeAtBegin(iElement);
	}
	else
	{
		newnode=(node *)malloc(sizeof(node));

		newnode->iData=iElement;

		current=first;
		for(int i=2;i<=iPos-1;i++)
		{
			current=current->next;
		}

		newnode->next=current->next;
		current->next=newnode;

		cout<<"Node inserted"<<endl;
	}
}

void DeleteNode(int key)
{
	int count=0;
	node *prevnode , *curnode ;
	
	if( first == NULL )
	{
		cout<<"list is empty...";
		return;
	}

	curnode=first;
	prevnode=curnode;

	while(prevnode->next !=first)
	{
		prevnode=prevnode->next;
		count++;
	}

	int i=0;
	while(i<=count)
	{
		if(curnode->iData==key)
		{
			if(curnode->next != curnode)
				prevnode->next=curnode->next;
			else
				prevnode->next=NULL;

			if( curnode == first )
				first=prevnode->next;

			free(curnode);

			if( prevnode != NULL )
				curnode=prevnode->next;
			else
				curnode=NULL;
		}
		else
		{
			prevnode=curnode;
			curnode=curnode->next;
		}
		i++;
	}

}

void ReverseCircularSLL()
{
	 // Temporary helper variables
    node *prev, *cur,*last;

    // Cannot reverse empty list
    if (first == NULL)
    {
        cout<<"Cannot reverse empty list.\n";
        return;
    }

    // Head is going to be our last node after reversing list
    last = first;

    prev  = first;
    cur   = first->next;
    first = first->next;

    // Iterate till you reach the initial node in circular list
    while (first != last)
    {
        first = first->next;
        cur->next = prev;

        prev = cur;
        cur  = first;
    }

    cur->next = prev;
    first = prev;       // Make last node as head
}