// SinglyLinkList-1.cpp : Defines the entry point for the console application.
//

//https://www.geeksforgeeks.org/reverse-a-linked-list/
//https://codeforwin.org/2015/09/singly-linked-list-data-structure-in-c.html



#include "stdafx.h"
#include "conio.h"
#include "stdio.h"
#include "iostream"

using namespace std;

typedef struct NODE
{

	int iData;
	struct NODE *next;

}node;

node *first,*last;

void CreateSingleLinkList();
void PrintSingleLinkList();

void ReverseLinkedList();

void InsertElementAtBegining(int iElement);
void InsertElementAtEnd(int iElement);
void InsertElementAtMiddle(int iPos,int iElement);

void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtMiddle(int iPos);


int _tmain(int argc, _TCHAR* argv[])
{
		cout<<"\n :: Single Linked list :: \n "<<endl ;
		CreateSingleLinkList();  //creating linked list
		PrintSingleLinkList();   //printing linked list

		cout<<"1) Reverse Linked list::"<<endl ;
		ReverseLinkedList();     //reverse link list
		PrintSingleLinkList();   //printing linked list

		cout<<"2) Insert at begining of Linked list::"<<endl ;
		InsertElementAtBegining(90);
		PrintSingleLinkList();   //printing linked list

		cout<<"3) Insert at end of Linked list::"<<endl ;
		InsertElementAtEnd(99);
		PrintSingleLinkList();   //printing linked list

		cout<<"4) Insert at middle of Linked list::"<<endl ;
		InsertElementAtMiddle(1,76);
		PrintSingleLinkList();   //printing linked list

		cout<<"5) Delete at begining of Linked list::"<<endl ;
		DeleteAtBegin();
		PrintSingleLinkList();   //printing linked list

		cout<<"6) Delete at end of Linked list::"<<endl ;
	    DeleteAtEnd();
		PrintSingleLinkList();   //printing linked list

		cout<<"7) Delete at middle of Linked list::"<<endl ;
		DeleteAtMiddle(3);
		PrintSingleLinkList();   //printing linked list


		return 0;
}

void CreateSingleLinkList()
{
		 NODE *first1=NULL;
		 NODE *second=NULL;
		 NODE *third=NULL;

		first1=( NODE*)malloc( sizeof(NODE) );
		second=(NODE*)malloc( sizeof(NODE) );
		third=( NODE*)malloc( sizeof(NODE) );

		first1 ->iData= 23;
		first1 -> next=second;

		second->iData=78;
		second->next=third;

		third->iData=89;
		third->next=NULL;

		first=first1;
}

void PrintSingleLinkList()
{
		node *Current;
		Current=first;

		cout<<"---------------------------------------------"<<endl ;
		cout<<"Printing list::"<<endl ;

		while( Current != NULL )
		{
			cout<< Current->iData <<"    " ;
			Current=Current->next;
		}
		cout<<"\nPrinted list"<<endl ;
		cout<<"---------------------------------------------"<<endl ;
		cout<<"\n"<<endl ;
}

void ReverseLinkedList()
{
		 node *prev=NULL;
		 node  *cur=NULL;
		 node *Next=NULL;

		 cur=first;

		 while(cur != NULL)
		 {
			Next = cur->next;
			cur->next=prev;
			prev=cur;
			cur=Next;
		 }
		 first=prev;
}

void InsertElementAtBegining(int iElement)
{
		node *head = NULL ;
		head=(NODE *)malloc(sizeof(NODE));
		if(!head)
			return;

		head->iData=iElement;
		head->next=first;
		first=head;
}

void InsertElementAtEnd(int iElement)
{
		node *tail = NULL ;
		tail=(NODE *)malloc(sizeof(NODE));
		if(!tail)
			return;

		tail->iData=iElement;

		last=first;
		while(last->next != NULL)
			last=last->next;

		last->next=tail;
		tail->next=NULL;
}

void InsertElementAtMiddle(int iPos,int iElement)
{
		node *tail = NULL ;
		tail=(NODE *)malloc(sizeof(NODE));
		if(!tail)
			return;

		tail->iData=iElement;
		tail->next=NULL;
		last=first;

		int iCheck=0;
		while(iCheck != iPos)
		{
			last=last->next;
			++iCheck;
		}
		tail->next=last->next;
		last->next=tail;
}

void DeleteAtBegin()
{
		node *head=NULL;
		head=first;

		first=first->next;
		free(head);
}

void DeleteAtEnd()
{
		node *LastNode,*SecondLast;
		LastNode=SecondLast=first;

		while(LastNode->next != NULL )
		{
			SecondLast=LastNode;
			LastNode=LastNode->next;
		}

		SecondLast->next=NULL;
		free(LastNode);
}

void DeleteAtMiddle(int iPos)
{
		node *prevnode,*TodeleteNode;

		prevnode = TodeleteNode = first;

		for(int i=0; i<iPos; i++)
		{
			prevnode= TodeleteNode;
			TodeleteNode= TodeleteNode->next;
		}
		prevnode->next = TodeleteNode->next;
		free(TodeleteNode);
}