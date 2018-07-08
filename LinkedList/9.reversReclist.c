#include<stdio.h>
#include<stdlib.h>
//not done yet
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

int main()
{
	struct node *head = NULL;
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,1);
	printlist(head);
	printf("\nafter revrse\n");
	reverse(NULL,head);
	printlist(head);
	return 0;
}
