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
	int loop = 0, count = 0,counter =0;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		count++;
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		if(slow_ptr==fast_ptr)
		{
			loop = 1;
			printf("fastPtr %d ",fast_ptr->data);
			break;
			
		}
			
	}
	printf("\ncount %d",count);
	if(loop)
	{
		fast_ptr=fast_ptr->next;
		
		while(slow_ptr!=fast_ptr)
		{
			counter++;
			fast_ptr=fast_ptr->next;
				
		}
		printf("\nslow_ptr %p\nfast_ptr %p",slow_ptr,fast_ptr);
		printf("\nconuter %d", counter);
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
	push(&head,8);
	push(&head,9);
	push(&head,10);
	head->next->next->next->next->next->next->next->next=head->next->next;
	FindBeginLoop(head);
	return 0;
	
}
