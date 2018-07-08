#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node * next;
	int data;
};
int getcount(struct node *head)
{
	struct node * temp =head;
	int count =0;
	while(temp)
	{
		count++;
		temp = temp ->next;
	}
	return count;
}
int getnode(int d, struct node *head1,struct node *head2)
{
	int i;
	struct node * current1= head1;
	struct node * current2= head2;
	for(i =0;i<d;i++)
	{
		if(current1==NULL)
		{
			return -1;
		}
		current1= current1->next;
	}
	while(current1!=NULL && current2!=NULL)
	{
		if(current1==current2)
		return current1->data;
		current1=current1->next;
		current2=current2->next;
	}
	return -1;
}
int getintersectionnode(struct node *head1, struct node *head2)
{
	int d;
	int c1= getcount(head1);
	int c2= getcount(head2);
	if(c1>c2)
	{
		 d = c1-c2;
		return getnode(d,head1,head2);
	}
	else
	{
		d = c2-c1;
		return getnode(d,head2,head1);
	}
}
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newnode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  	head1->data = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newnode = (struct node*) malloc (sizeof(struct node));
  newnode->data = 6;
  head2->next = newnode;
 
  newnode = (struct node*) malloc (sizeof(struct node));
  newnode->data = 9;
  head2->next->next = newnode;
 
  newnode = (struct node*) malloc (sizeof(struct node));
  newnode->data = 15;
  head1->next = newnode;
  head2->next->next->next  = newnode;
 
  newnode = (struct node*) malloc (sizeof(struct node));
  newnode->data = 30;
  head1->next->next= newnode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getintersectionnode(head1, head2));
 
  getchar();
}


