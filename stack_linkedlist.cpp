// stack_linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "stdio.h"
#include "iostream"

#define CAPACITY 10

using namespace std;

//https://codeforwin.org/2018/08/stack-implementation-using-linked-list-push-pop.html
//
//Stack is a LIFO (Last In First Out) data structure. It allows us to insert and remove an element in special order. Stack allows element addition and removal from the top of stack.

typedef struct stack
{
	int iData;
	struct stack *next;

};

stack *top=NULL;

int size=0;

void push(int element);
int pop();


int _tmain(int argc, _TCHAR* argv[])
{
	int choice,data;

    while(1)
    {
        cout<<"------------------------------------\n";
        cout<<"    STACK IMPLEMENTATION PROGRAM    \n";
        cout<<"------------------------------------\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Size\n";
        cout<<"4. Exit\n";
        cout<<"------------------------------------\n";
        cout<<"Enter your choice: ";

        cin>>choice;

        switch(choice) 
        {
            case 1: 
                cout<<"Enter data to push into stack: ";
                cin>>data;
                
                // Push element to stack
                push(data);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;

            case 3: 
                printf("Stack size: %d\n", size );
                break;

            case 4: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }

	return 0;
}
void push(int element)
{
	if(size >= CAPACITY)
	{
		cout<<"stack overflow";
		return;
	}
	else
	{
		stack *newtop=(stack *)malloc(sizeof(stack));
		newtop->iData=element;
		newtop->next=top;

		top=newtop;
		size++;

		cout<<"data pushed to stack";
	}
}
int pop()
{
	int data;
	stack *newnode=NULL;

	if( size <= 0 )
	{
		cout<<"stack underflow";
		return -1;
	}
	else
	{
		newnode=top;

		data=top->iData;

		top=top->next;

		free(newnode);
		
		size--;

		return data;
	}
}

