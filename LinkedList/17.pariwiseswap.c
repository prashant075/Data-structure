#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node * next;
	int data;
};
void push(struct node **headref, int newdata)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=(*headref);
	(*headref)=newnode;	
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
void pairwise(struct node *head)
{
	struct node *temp =head;
	while(temp != NULL && temp->next!=NULL)
	{
		swap(&temp->data,&temp->next->data);
		temp = temp->next->next;
	}
}
void printlist(struct node *head)
{
	struct node *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	struct node * head=NULL;
	push(&head,3);
	push(&head,2);
	push(&head,5);
	push(&head,7);
	push(&head,9);
	push(&head,10);
	printlist(head);
	printf("\nPair wise swap\n");
	pairwise(head);
	printlist(head);
	return 0;
}
