#include<stdio.h>
#include<stdlib.h>

struct Qnode{
	int data;
	struct Qnode* next;
};

struct Queue{
	struct Qnode *front, *rear;
};
struct Qnode* newnode(int k)
{
	struct Qnode* temp = (struct Qnode*)malloc(sizeof(struct Qnode));
	temp->data = k;
	temp->next =NULL;
	return temp;
}
struct Queue* createQueue()
{
	struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}
void enQueue(struct Queue* q, int k)
{
	struct Qnode* temp =newnode(k);
	
	if(q->rear == NULL)
	{
		q->rear=q->front = temp;
		return;
	}
	q->rear->next=temp;
	q->rear =temp;
}
struct Qnode *deQueue(struct Queue *q)
{
	if(q->front ==NULL)
	return NULL;
	
	struct Qnode* temp =q->front;	
	q->front = q->front->next;
	
	if(q->front ==NULL)
	q->rear=NULL;
	return temp;
}
void display(struct Queue* q)
{
	struct Qnode* temp = q->front;
	printf("display queue element\n");
	while(temp )
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main()
{
	struct Queue *q = createQueue();
	enQueue(q,10);
	enQueue(q,20);
	enQueue(q,30);
	enQueue(q,40);
	display(q);
	struct Qnode* n =deQueue(q);
	if(n!=NULL)
	printf("\nDequeue Element %d",n->data);
	printf("\n");
	display(q);
	return 0;
}
