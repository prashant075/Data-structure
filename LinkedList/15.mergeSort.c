#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node * next;
	int data;
};

void push(struct node **head_ref, int newdata)
{
	struct node * newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next=(*head_ref);
	(*head_ref)=newnode;
}
void printlist(struct node *head)
{
	struct node *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

struct node * sortedmerge(struct node *a, struct node *b)
{
	struct node *result=NULL;
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	if(a->data<=b->data)
	{
		result =a;
		result->next=sortedmerge(a->next,b);
	}
	else
	{
		result = b;
		result->next=sortedmerge(a,b->next);
	}
	return result;
}
void splitfrontback(struct node *source, struct node **front, struct node **back)
{
	struct node* slow;
	struct node * fast;
	slow = source;
	fast = source->next;
	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	*front = source;
	*back=slow->next;
	slow->next=NULL;
}
void mergesort(struct node **headref)
{
	struct node *head= *headref;
	struct  node *a;
	struct node *b;
	if(head == NULL || head->next ==NULL)
	return;
	splitfrontback(head,&a,&b);
	mergesort(&a);
	mergesort(&b);
	
	(*headref)=sortedmerge(a,b);
	
}
int main()
{
	struct node *head=NULL;
	push(&head,3);
	push(&head,2);
	push(&head,12);
	push(&head,4);
	push(&head,6);
	push(&head,1);
	printlist(head);
	printf("\nsorted list\n");
	mergesort(head);
	printlist(head);
	return 0;
}
