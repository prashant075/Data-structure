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

void FindBeginLoop(struct Node *head)
{
	struct Node * slow_ptr=head;
	struct Node* fast_ptr =head;
	int loop = 0;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		
		if(slow_ptr==fast_ptr)
		{
			loop = 1;
			printf("fastPtr %d ",fast_ptr->data);
			break;
			
		}
			
	}
	if(loop)
	{
		slow_ptr = head;
		while(slow_ptr!=fast_ptr)
		{
			fast_ptr=fast_ptr->next;
			slow_ptr=slow_ptr->next;	
		}
		printf("\nslow_ptr %p\nfast_ptr %p",slow_ptr,fast_ptr);
		printf("\nstart of loop %d", slow_ptr->data);
	}
	else
	{
		printf("No Loop");
	}
}


int main()
{
	struct Node * head =NULL;
	push(&head,1);
	push(&head,3);
	push(&head,5);
	push(&head,2);
	push(&head,7);
	head->next->next->next->next=head->next->next;
	FindBeginLoop(head);
	return 0;
	
}
