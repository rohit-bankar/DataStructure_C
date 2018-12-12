// queue-array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"

#define CAPACITY 100

using namespace std;

int queue[CAPACITY];

int size=0;
int rear=CAPACITY-1;
int front=0;

int enqueue(int data);
int dequeue();
int isEmpty();
int isFull();
int GetRear();
int GetFront();

int _tmain(int argc, _TCHAR* argv[])
{
	int ch, data;

    /* Run indefinitely until user manually terminates */
    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);

        
        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                // Enqueue function returns 1 on success
                // otherwise 0
                if (enqueue(data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = dequeue();

                // on success dequeue returns element removed
                // otherwise returns INT_MIN
                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3: 

                // isEmpty() function returns 1 if queue is emtpy 
                // otherwise returns 0
                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Queue size => %d", size);

                break;

            case 4: 

                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Rear => %d", GetRear());

                break;

            case 5: 

                if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Front => %d", GetFront());

                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);
        
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }

        printf("\n\n");
    }

	return 0;
}

int enqueue(int data)
{
	if(isFull())
	{
		cout<<"Queue is full"<<endl;
		return 0;
	}

	rear=(rear+1)% CAPACITY ;

	size++;

	queue[rear]=data;

	return 1;
}

int dequeue()
{
	int data=0;

	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return 0;
	}

	data=queue[front];

	front=(front+1)% CAPACITY;

	size--;

	return data;

}

int isEmpty()
{
	if( size==0 )
		return 1;
	else
		return 0;
}

int isFull()
{
	if(size==CAPACITY)
		return 1;
	else 
		return 0;
}
int GetRear()
{
	return queue[rear];
}
int GetFront()
{
	return queue[front];
}