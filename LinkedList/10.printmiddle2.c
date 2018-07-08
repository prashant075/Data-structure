#include<stdio.h>
#include<stdlib.h>
//2 scan not done
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
void printmiddle(struct node * cur)
{
	int length = 0, i =0;
	struct node * temp = cur;
	while(temp)
	{
		
		temp=temp->next;
		length++;
	}
	printf("\n%d Length", length);
	temp = cur;
	
	for(i=1;i<length/2;i++)
	temp=temp->next; 
	
	printf("\n middle node %d",temp->data);
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
	printmiddle(head);
	return 0;
}
