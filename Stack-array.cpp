// Stack-array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "stdio.h"
#include "iostream"

#define SIZE 10

using namespace std;

//https://codeforwin.org/2018/07/stack-implementation-using-array.html
//
//Stack is a LIFO (Last In First Out) data structure. It allows us to insert and remove an element in special order. Stack allows element addition and removal from the top of stack.

int stack[SIZE];

int top=-1;

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
                printf("Stack size: %d\n", top + 1);
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
	if(top>=SIZE)
	{
		cout<<"stack overflow";
		return;
	}
	else
	{
		stack[++top]=element;
	}
}
int pop()
{
	if( top < 0 )
	{
		cout<<"stack underflow";
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

