#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct Node
{
	int data;
	struct Node *next;
};

//printing linked list nodes
void PrintList(struct Node *Nd)
{
	while(Nd !=NULL)
	{
		printf("\n %d ",Nd->data);
		Nd=Nd->next;
	}
}

//push element at top of list
void push(struct Node **Head_ref,int newnode)
{
	struct Node *new_node=NULL;
	new_node =(struct Node*)malloc(sizeof(struct Node ));

	new_node->data=newnode;

	new_node->next=(*Head_ref);

	(*Head_ref)=new_node;
}
//add element at the end of list
void append(struct Node **Head_Ref,int newnode)
{
	struct Node *new_node =(struct Node*)malloc(sizeof(struct Node ));

	struct Node *last_node=*Head_Ref;

	new_node->data=newnode;
	new_node->next=NULL;

	if(Head_Ref == NULL)
	{
		(*Head_Ref)=new_node;
		return;
	}
	while(last_node->next !=NULL)
	{
			last_node=last_node->next; 
	}

	last_node->next=new_node ;
	return;
}

//add element in between list

void InsertAfter(struct Node *Prev_node,int newnode)
{
	if(Prev_node==NULL)
	{
		printf("NULL element");
		return;
	}

	struct Node *new_node =(struct Node*)malloc(sizeof(struct Node ));

	new_node->data=newnode;

	new_node->next=Prev_node->next;

	Prev_node->next=new_node;
}

void deleteNode(struct Node **Head_ref,int key)
{
	struct Node *temp=*Head_ref, *prev;

	if(temp !=NULL && temp->data== key )
	{
		*Head_ref =temp->next;
		free(temp);
		return;
	}

	if(temp !=NULL && temp->data != key )
	{
		prev=temp;
		temp=temp->next;
	}

	if(temp == NULL)
		return;

	prev->next=temp->next;

	free(temp);

}
//=============================reverse list

void reverse(struct Node **head_ref)
{
	struct Node *prev=NULL;
	struct Node  *cur=*head_ref;
	struct Node *Next=NULL;

	while(cur != NULL)
	{
		Next = cur->next;
		cur->next=prev;
		prev=cur;
		cur=Next;
	}
	*head_ref=prev;
}

int main()
{
	struct Node *first=NULL;
	struct Node *second=NULL;
	struct Node *third=NULL;

	first=(struct Node*)malloc( sizeof(struct Node) );
	second=(struct Node*)malloc( sizeof(struct Node) );
	third=(struct Node*)malloc( sizeof(struct Node) );

	first ->data= 23;
	first->next=second;

	second->data=78;
	second->next=third;

	third->data=89;
	third->next=NULL;

	PrintList(first);

	printf("\n=====================================reverse list");

	reverse(&first);
	PrintList(first);

	printf("\n=====================================At top");
	push(&first,5);
	PrintList(first);

	printf("\n=====================================At End ");

	append(&first,7);
	PrintList(first);

	printf("\n=====================================At top");
	push(&first,8);
	PrintList(first);

	printf("\n=====================================Insert After");
	InsertAfter(second,8);
	PrintList(first);

	printf("\n=====================================reverse list");

	reverse(&first);
	PrintList(first);

	printf("\n=====================================Delete Node after 3rd");
	deleteNode(&third,89);
	PrintList(first);




	free(first);
	free(second);
	free(third);

	return 0;
}
