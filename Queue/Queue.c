#include<stdio.h>
#include<stdlib.h>
struct Queue{
	
	struct ListNode *front;
	struct ListNode *rear;
};
struct ListNode{
	int data;
	struct ListNode *next;
};
struct Queue *createQueue()
{
	struct Queue *Q;
	struct ListNode *temp;
	Q=malloc(sizeof(struct Queue));
	
	if(!Q)
		return NULL;
	temp =malloc(sizeof(struct ListNode));
	Q->front=Q->rear=NULL;
	return Q;
}
int IsEmptyQueue(struct Queue *Q)
{
	return (Q->front==NULL);
}
void EnQueue(struct Queue *Q, int data)
{
	struct ListNode *newNode;
	newNode=malloc(sizeof(struct ListNode));
	if(!newNode)
		printf("UnderFlow");
	newNode->data=data;
	newNode->next=NULL;
	if(Q->rear)
		Q->rear->next=newNode;
	Q->rear=newNode;
	if(Q->front==NULL)
		Q->front=Q->rear;
}
int DeQueue(struct Queue *Q)
{
	int data;
	struct ListNode *temp;
	if(IsEmptyQueue(Q))
	{
		printf("Queue is Empty");
		return 0;
	}
	else
	{
		temp=Q->front;
		data=Q->front->data;
		Q->front=Q->front->next;
		free(temp);
	}
	return data;
}

void display(struct Queue* q)
{
	struct ListNode* temp = q->front;
	printf("\ndisplay queue element\n");
	while(temp )
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
void DeleteQueue(struct Queue *Q){
	struct ListNode *temp ;
	while(!IsEmptyQueue(Q))
	{
		temp=Q->front;
		Q->front=Q->front->next;
		free(temp);
	}
}
int main()
{
	struct Queue *q = createQueue();
	EnQueue(q,10);
	EnQueue(q,20);
	EnQueue(q,30);
	EnQueue(q,40);
	display(q);
	int data =DeQueue(q);
	printf("\nDequeue Element %d",data);
	printf("\n");
	display(q);
	DeleteQueue(q);
	display(q);
	return 0;
}
