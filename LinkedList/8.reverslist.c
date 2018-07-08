#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node * next;
	int data;
};
void push(struct node **head, int newdata)
{
	struct node * newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = (*head);
	(*head) = newnode;
}
void printlist(struct node *head)
{
	struct node * temp = head;
	while(temp)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}
struct node * reverse(struct node * cur)
{
	struct node * prev = NULL;
	struct node * nextnode = NULL;
	while(cur)
	{
		nextnode=cur->next;
		cur->next = prev;
		prev=cur;
		cur = nextnode;
	}
	return prev;
}
int main()
{
	struct node *head = NULL;
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,1);
	printlist(head);
	printf("\nafter revrse\n");
	struct node * revnode = reverse(head);
	printlist(revnode);
	return 0;
}
