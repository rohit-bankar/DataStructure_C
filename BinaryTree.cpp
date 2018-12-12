// BinaryTree.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"

#include <stdlib.h>         /* For _MAX_PATH definition */
#include <stdio.h>
#include <malloc.h>


typedef struct BIN_TREE
{

	int iValue;
	struct BIN_TREE *left,*right;

}bin_tree;

 bin_tree * alloc_new_node(int val);
 bin_tree * add_new_node(bin_tree *node, int val);

 int get_node_count (bin_tree* node) ;

 void inorder(bin_tree *root) ;
 void preorder(bin_tree *root) ;
 void postorder(bin_tree *root) ;

 bin_tree* search(bin_tree* root, int key) ;

int _tmain(int argc, _TCHAR* argv[])
{
	bin_tree *root;

	int iCount=0;

	root=NULL;

	iCount=get_node_count(root);
	printf("\nCount=%d",iCount);

	root=alloc_new_node(9);

	add_new_node( root , 4 );

	add_new_node( root , 15 );

	add_new_node( root , 6 );

	add_new_node( root , 12 );

	add_new_node( root , 17 );

	add_new_node( root , 2 );

	iCount=get_node_count(root);
	printf("\nCount=%d",iCount);

	printf("\nPreorder::==> \n");
	preorder(root);
	printf("\n==::nPreorder::== \n");

	printf("\nInorder::==> \n");
	inorder(root);
	printf("\n==::Inorder::== \n");

	printf("\nPostorder::==> \n");
	postorder(root);
	printf("\n==::nPostorder::== \n");

	bin_tree *temp;
	temp=search(root, 4) ;
	if(temp)
		printf("found");
	else
		printf("not found");

	return 0;
}

 bin_tree * alloc_new_node(int val)
{
	bin_tree *new_node;
	
	new_node=(bin_tree *)malloc(sizeof(bin_tree));

	new_node->iValue=val;
	new_node->left=NULL;
	new_node->right=NULL;

	return new_node;
}

 bin_tree * add_new_node(bin_tree *node,int val)
{
	if(node==NULL)
	{
		node=alloc_new_node(val);
		return node;
	}
	else if (val == node -> iValue) 
	{
		return NULL;
  	}
	else if (val < node -> iValue) 
	{
		node ->left  =add_new_node (node ->left, val);

		return node;
	} 
	else if (val > node -> iValue) 
	{
		node ->right  =add_new_node (node ->right, val);

		return node;
    }
}

 int get_node_count (bin_tree* node) 
 { 
   if (node==NULL)
   { 
     return(0); 
   }
   else 
   { 
     return(get_node_count(node->left) + 1 + get_node_count(node->right)); 
   } 
 }

void inorder(bin_tree *root) 
{ 	 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->iValue); 
        inorder(root->right); 
    } 
} 

void preorder(bin_tree *root) 
{
	if (root != NULL) 
    { 
		printf("%d \n", root->iValue); 
        preorder(root->left); 
        preorder(root->right); 
    } 
}
void postorder(bin_tree *root) 
{
	if (root != NULL) 
    { 
        postorder(root->left); 
       
        postorder(root->right); 
		 printf("%d \n", root->iValue); 
    } 
}

bin_tree* search(bin_tree* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->iValue == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->iValue < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 