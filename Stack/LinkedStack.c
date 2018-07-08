#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
	struct node * next;
	int data;
};

struct node * newnode( int newdata){
	struct node * stacknode =(struct node *)malloc(sizeof(struct node));
	stacknode->data =newdata;
	stacknode->next = NULL;
	return stacknode;
}
int isEmpty(struct node *root)
{
	return !root;
}
void push(struct node ** root , int data)
{
	struct node * stacknode = newnode(data);
	stacknode->next = *root;
	*root = stacknode;
	printf("%d pushed  into stack\n",data);
}
int pop(struct node **root)
{
	if(isEmpty(*root))
	return INT_MIN;
	struct node * temp =*root;
	*root =(*root)->next;
	int pop =temp->data;
	free(temp);
	return pop;
}
int peek(struct node * root)
{
	if(isEmpty(root))
	return INT_MIN;
	return root->data;
}
int main()
{
	struct node * root =NULL;
	push(&root,10);
	push(&root,20);
	push(&root,30);
	printf("Poped Item %d",pop(&root));
	printf("\nPeeked Item in stack %d",peek(root));
	return 0;
}

