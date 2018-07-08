#include<stdio.h>
#include<stdlib.h>
//1 scan
struct node{
	struct node * next;
	int data;
};
void push(struct node **head, int newdata)
{
	struct node * newnode = (struct nde *)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = (*head);
	(*head) =newnode;
}
void printlist(struct node * head)
{
	struct node * temp = head ;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
}
void printrevres(struct node * head)
{
	if(!head)
	return ;
	printrevres(head->next);
	printf("%d ",head->data);
}
int main()
{
	struct node * head =NULL;
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,10);
	printlist(head);
	printf("\n");
	printrevres( head);
	
	return 0;
}
