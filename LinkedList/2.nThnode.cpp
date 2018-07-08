#include<stdio.h>
#include<stdlib.h>
//Nth NOde form end using n^2
struct Node{
	struct Node* next;
	int data;
};

void push(struct Node **head, int new_data)
{
	struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
	newnode->data = new_data;
	newnode->next = (*head);
	(*head)= newnode;
}
void printlist(struct Node *head)
{
	struct Node *temp = head;
	while(temp)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}
void printnth(struct Node *head, int n)
{
	int length , i = 0;
	struct Node * temp =head;
	while(temp)
	{
		length++;
		temp=temp->next;
	}
	if(n>length)
	return;
	
	temp =head;
	
	for(i =1; i< length-n+1; i++)
	{
		temp=temp->next;
	}
	printf("%dth node %d",n, temp->data);
	return ;
}
int main()
{
	struct Node * head =NULL;
	push(&head,1);
	push(&head,3);
	push(&head,5);
	push(&head,2);
	printlist(head);
	printf("\n");
	printnth(head, 3);
	return 0;
	
}
