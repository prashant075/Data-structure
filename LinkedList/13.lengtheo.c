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
int length(struct node * head)
{
	struct node *temp =head;
	while(temp && temp->next)
	temp = temp->next->next;
	printf("%p",!temp);
	
	if(!temp)
	return 0;
	
 return 1;
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
	int i = length( head);
	if(i  == 0)
	{
		printf("Even");
	}
	else
	{
		printf("odd");
	}
	
	return 0;
}
