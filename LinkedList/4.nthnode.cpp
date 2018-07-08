#include<stdio.h>
#include<stdlib.h>
//Nth NOde form end using n
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
void printNthFromLast(struct Node *head, int n)
{
  struct Node *main_ptr = head;
  struct Node *ref_ptr = head;
 
  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
        printf("ref_ptr %p Count %d\n",ref_ptr->next,count);
     } /* End of while*/
 
     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
        
     }
    // printf("ref_ptr %d, main_ptr %d\n",ref_ptr->data ,main_ptr->data);
     printf("Node no. %d from last is %d ", 
              n, main_ptr->data);
  }
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
	printNthFromLast(head, 3);
	return 0;
	
}
