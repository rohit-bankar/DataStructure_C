// DoublyLinkList-Circular.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"

using namespace std;

typedef struct NODE 
{
	int iData;
	NODE *next,*prev;
}node;

node *first,*last;

void CreateCircularDoublyLinkList(int n);
void PrintCircularDoublyLinkList();

void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data , int n);

void PrintReverseDoublyLinkList();

void deleteAtMiddle(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	//cout<<"===============Circular doubly link list==============="<<endl;
	int n, data, choice=1;

    first = NULL;
    last = NULL;

    while(choice != 0)
    {/* Menu creation to use the program*/
         cout<<"============================================\n";
         cout<<"Circular DOUBLY LINKED LIST PROGRAM\n";
         cout<<"============================================\n";
         cout<<"1. Create List\n";
         cout<<"2. Insert node - at beginning\n";
         cout<<"3. Insert node - at end\n";
         cout<<"4. Insert node - at N\n";
         cout<<"5. Reverse list\n";
		 cout<<"6. Display list\n";   
         cout<<"7. Delete node - at N\n";
		 cout<<"0. Exit\n";
         cout<<"--------------------------------------------\n";
         cout<<"Enter your choice : ";

         cin>>choice;
        /* Choose from different menu operation*/
        switch(choice)
        {
            case 1:
                cout<<"Enter the total number of nodes in list: ";
                cin>>n;

                CreateCircularDoublyLinkList(n);
                break;
            case 2:
                cout<<"Enter data of first node : ";
                cin>>data;

                insertAtBeginning(data);
                break;
            case 3:
                cout<<"Enter data of last node : ";
                cin>>data;

                insertAtEnd(data);
                break;
            case 4:
                cout<<"Enter the position where you want to insert new node: ";
                cin>>n;
                cout<<"Enter data of "<<n <<" node ";
                cin>>data;

                insertAtN(data, n);
                break;
			case 5:
				PrintReverseDoublyLinkList();
				break;
            case 6:
                PrintCircularDoublyLinkList();
                break;
			case 7:
				cout<<"Enter the position where you want to delete node: ";
                cin>>n;
				deleteAtMiddle(n);
				break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-6");
        }
        printf("\n\n");
    }

	return 0;
}

void CreateCircularDoublyLinkList(int n)
{
	int data;
	node *newnode;
	if( n == 1 )
	{
		first=(node *)malloc(sizeof(node));

		cout<<"Enter 1st node::";
		cin>>data;

		first->iData=data;
		first->next=first->prev=first;
	}
	else if( n==0 )
	{
		cout<<"Enter node count value greater than zero";
	}
	else if(n>1)
	{
		first=(node *)malloc(sizeof(node));

		cout<<"Enter 1st node::";
		cin>>data;

		first->iData=data;
		first->next=first->prev=first;

		last=first->prev;

		for(int i=2 ;i<=n;i++)
		{
			newnode=(node *)malloc(sizeof(node));

			cout<<"Enter "<<i<<"th node::";
			cin>>data;

			newnode->iData=data;

			newnode->next=first;
			
			first->prev=newnode;

			newnode->prev=last;
			
			last->next=newnode;

			last=newnode;
		}
	}
	else
		cout<<"error";
}

void PrintCircularDoublyLinkList()
{
	node *temp = first; 
  
    cout<<"\nTraversal in forward direction \n"; 
    while (temp->next != first) 
    { 
        cout<<">>"<< temp->iData<<">>"; 
        temp = temp->next; 
    } 
    cout<<temp->iData; 
  
    cout<<"\nTraversal in reverse direction \n"; 
    last = first->prev; 
    temp = last; 
    while (temp->prev != last) 
    { 
        cout<<">>"<<temp->iData<<">>"; 
        temp = temp->prev; 
    } 
    cout<< temp->iData; 
}


void insertAtBeginning(int data)
{
	last=first->prev;

	node *newnode;

	newnode=(node *)malloc(sizeof(node));

	newnode->iData=data;
	newnode->next=first;
	newnode->prev=last;

	last->next=first->prev=newnode;

	first=newnode;
}

void insertAtEnd(int data)
{
	node *newnode;

	last=first->prev;

	newnode=(node *)malloc(sizeof(node));

	newnode->iData=data;

	newnode->next=first;
	
	first->prev=newnode;

	newnode->prev=last;
	
	last->next=newnode;

	last=newnode;
}

void insertAtN(int data , int n)
{
	node *newnode,*temp;

	last=first->prev;

	newnode=(node *)malloc(sizeof(node));

	newnode->iData=data;
    
    temp = first; 

    for (int i=1 ; i<n-1 ; i++ ) 
	{
        temp = temp->next; 
	}
     node *next1 = temp->next; 
  
    // insert new_node between temp and next. 
    temp->next = newnode; 
    newnode->prev = temp; 
    newnode->next = next1; 
    next1->prev = newnode; 
}

void PrintReverseDoublyLinkList()
{
}

void deleteAtMiddle(int n)
{
	    // If list is empty 
    if (first == NULL) 
        return; 
  
    // Find the required node 
    // Declare two pointers and initialize them 
     node *curr = first, *prev_1 = NULL; 
    while (curr -> iData != n) 
    { 
        // If node is not present in the list 
        if (curr->next == first) 
        { 
            printf("\nList doesn't have node with value = %d", n); 
            return; 
        } 
  
        prev_1 = curr; 
        curr = curr -> next; 
    } 
  
    // Check if node is the only node in list 
    if (curr -> next == first && prev_1 == NULL) 
    { 
        first = NULL; 
        free(curr); 
        return; 
    } 
  
    // If list has more than one node, 
    // check if it is the first node 
    if (curr == first) 
    { 
        // Move prev_1 to last node 
        prev_1 = first -> prev; 
  
        // Move start ahead 
        first = first -> next; 
  
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = first; 
        first -> prev = prev_1; 
        free(curr); 
    } 
  
    // check if it is the last node 
    else if (curr->next == first) 
    { 
        // Adjust the pointers of prev_1 and start node 
        prev_1 -> next = first; 
        first -> prev = prev_1; 
        free(curr); 
    } 
    else
    { 
        // create new pointer, points to next of curr node 
         node *temp = curr -> next; 
  
        // Adjust the pointers of prev_1 and temp node 
        prev_1 -> next = temp; 
        temp -> prev = prev_1; 
        free(curr); 
    } 
}