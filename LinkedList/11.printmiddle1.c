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
struct node * printmiddle(struct node * cur)
{
	struct node *ptr1, *ptr2;
	ptr1=ptr2 =cur;
	int i =0;
	while(ptr1->next != NULL)
	{
		if(i ==0)
		{
			ptr1=ptr1->next;
			i=1;
		}
		else if(i==1)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
			i = 0;
		}
	}
	return ptr2;
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
	struct node * ptr =	printmiddle(head);
	printf("middle %d", ptr->data);
	return 0;
}
