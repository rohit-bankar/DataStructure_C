// DoublyLinkedList-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"

using namespace std;

//https://codeforwin.org/2015/10/c-program-to-insert-node-in-doubly-linked-list.html

typedef struct NODE
{
	int iData;
	NODE * next ;
	NODE * prev;

}node ;

node *first, *last;

void CreateDoublyLinkList(int n);
void PrintDoublyLinkList();

void PrintReverseDoublyLinkList();

void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data,int n);

void deleteAtBegining();
void deleteAtEnd();
void deleteAtMiddle(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n, data, choice=1;

    first = NULL;
    last = NULL;

    while(choice != 0)
    {/* Menu creation to use the program*/
         cout<<"============================================\n";
         cout<<"DOUBLY LINKED LIST PROGRAM\n";
         cout<<"============================================\n";
         cout<<"1. Create List\n";
         cout<<"2. Insert node - at beginning\n";
         cout<<"3. Insert node - at end\n";
         cout<<"4. Insert node - at N\n";
         cout<<"5. Reverse list\n";
		 cout<<"6. Display list\n";   
		 cout<<"7. Delete node - at beginning\n";
         cout<<"8. Delete node - at end\n";
         cout<<"9. Delete node - at N\n";
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

                CreateDoublyLinkList(n);
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
                PrintDoublyLinkList();
                break;
			case 7:
				deleteAtBegining();
				break;
            case 8:
                deleteAtEnd();
                break;
			case 9:
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

void CreateDoublyLinkList(int n)
{
	int data;
	if( n == 1 )
	{
		node *newnode=(node *)malloc(sizeof(node));
		cout<<"Enter 1st element to enter in list:";
		cin>>data;
		
		newnode->iData=data;
		newnode->prev=NULL;
		newnode->next=NULL;

		first=newnode;
	}
	else if( n == 0 )
	{
		cout<<"Item count is zero.so unable to process " ;
	}
	else if( n > 1 )
	{
		first=(node *)malloc(sizeof(node));

		cout<<"Enter 1st element to enter in list:";
		cin>>data;
		first->iData=data;
		first->prev=NULL;
		first->next=NULL;

		last=first;

		for(int i=2;i<= n ;i++)
		{
			node *newnode=(node *)malloc(sizeof(node));

			cout<<"Enter"<<i << "element to enter in list:";
			cin>>data;

			newnode->iData=data;

			newnode->prev=last;
			newnode->next=NULL;

			last->next=newnode;
			last=newnode;
		}
	}
}

void PrintDoublyLinkList()
{
	node *temp;
	temp = first;

	if( first == NULL )
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		while (temp !=NULL)
		{
			cout<<temp->iData<<"  >>  " ;
			temp=temp->next;
		}
	}
}

void PrintReverseDoublyLinkList()
{
    node *current, *temp;

    current = first;
    while(current != NULL)
    {
        /*
         * Swap the previous and next address fields of current node
         */
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /* Move the current pointer to next node which is stored in temp */
        current = temp;
    }
    
    /* 
     * Swap the head and last pointers
     */
    temp = first;
    first = last;
    last = temp;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}

void insertAtBeginning(int data)
{
	if(first ==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node *newnode=(node *)malloc(sizeof(node));
		
		newnode->iData=data;
		newnode->prev=NULL;
		newnode->next=first;

		first->prev=newnode;
		first=newnode;
		cout<<"NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n";
	}
}

void insertAtEnd(int data)
{
	if(last == NULL )
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node *newnode=(node *)malloc(sizeof(node));
			
		newnode->iData=data;

		newnode->prev=last;
		newnode->next=NULL;

		last->next=newnode;
		last=newnode;
	}
	cout<<"NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n";
}

void insertAtN(int data,int n)
{
	int i;
	node *newnode,*temp;

	if(first ==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		temp=first;
		i=1;

		while( i < n-1 && temp !=NULL )
		{
			temp=temp->next;
			i++;
		}

		if(n==1)
		{
			insertAtBeginning(data);
		}
		else if(temp==last)
		{
			insertAtEnd(data);
		}
		else if( temp != NULL )
		{
			newnode=(node *)malloc(sizeof(node));

			newnode->iData=data;
			newnode->next=temp->next;
			newnode->prev=temp;

			
			temp->next=newnode;


			cout<<"added node at given position";
		}
		else
			cout<<"Invalid position...";
	}
}


void deleteAtBegining()
{
	node *toDelete;
	
	if( first==NULL )
	{
		cout<<"List is empty..";
	}
	else
	{
		toDelete=first;

		first=first->next;
		
		if( first!=NULL )
		first->prev=NULL;

		free(toDelete);

		cout<<"1st node deleted..";
	}
}

void deleteAtEnd()
{
	node *toDelete;

	if( last==NULL )
	{
		cout<<"List is empty..";
	}
	else
	{
		toDelete=last;
		last=last->prev;
		
		if( last!=NULL )
		last->next=NULL;

		free(toDelete);

		cout<<"1st node deleted..";
	}

}

void deleteAtMiddle(int n)
{
	int i;
	node *current;

	current=first;

	for(i=1; i<n-1 && current!=NULL ;i++)
	{
		current=current->next;
	}

	if(n==1)
		deleteAtBegining();
	else if(current == last)
		deleteAtEnd();
	else if(current!=NULL)
	{
		current->prev->next = current->next;
        current->next->prev = current->prev;

		free(current);
		cout<<"SUCCESSFULLY DELETED NODE FROM POSITION:"<< n ;
	}
	else
	{
		cout<<"invalid position..";
	}
}