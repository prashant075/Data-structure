#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node * next;
	int data;
};
void push(struct node **head_ref, int newdata)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next =(*head_ref);
	(*head_ref)=newnode;
}
void printlist(struct node *head)
{
	struct node *temp =head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
struct node *mergesort(struct node *headA ,struct node *headB)
{
	 
	struct node * result = NULL;
	if(headA==NULL)
		return headB;
	if(headB==NULL)
		return headA;
	if(headA->data<=headB->data)
	{
		result= headA;
		result->next=mergesort(headA->next,headB);		
	}
	else
	{
		result=headB;
		result->next=mergesort(headA,headB->next);
	}
	return result;
}
int main()
{
	struct node *head1 = NULL;
	struct node *head2  = NULL;
	push(&head1,4);
	push(&head1,3);
	push(&head1,2);
	push(&head1,1);
	printlist(head1);
	printf("\n");
	push(&head2,8);
	push(&head2,7);
	push(&head2,6);
	push(&head2,5);
	printlist(head2);
	printf("\n");
	struct node *head3 =mergesort(head1,head2);
	printlist(head3);
	return 0;
}
