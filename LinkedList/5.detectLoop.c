#include<stdio.h>
#include<stdlib.h>
//detect loop in order of n 
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

int detectloop(struct Node *head)
{
	struct Node * slow_ptr=head;
	struct Node* fast_ptr =head;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		
		if(slow_ptr==fast_ptr)
			return 1;
	}
	return 0;
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
int main()
{
	struct Node * head =NULL;
	push(&head,1);
	push(&head,3);
	push(&head,5);
	push(&head,2);
	head->next->next->next->next=head->next->next;
//	printlist(head);
	printf("\n");
	if(detectloop(head))
	{
		printf("Loop Found");
	}
	else
	{
		printf("No Loop Found");
	}
	return 0;
	
}
