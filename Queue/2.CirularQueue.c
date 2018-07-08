#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * link;
};

struct Queue{
	struct Node * front, *rear;
};
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue( struct Queue* q, int value)
{
	struct Node * temp =(struct Node*)malloc(sizeof(struct Node));
	temp->data=value;
	if(q->front==NULL)
		q->front = temp;
	else
		q->rear->link=temp;
	q->rear =temp;
	q->rear->link=q->front;
}
int deQueue(struct Queue *q)
{
	if(q->front==NULL)
		return INT_MIN;
	int value ;
	if(q->rear==q->front)
	{
		value = q->front->data;
		free(q->front);
		q->front=NULL;
		q->rear =NULL;
	}
	else
	{
		struct Node* temp =q->front;
		value = temp->data;
		q->front=q->front->link;
		q->rear->link= q->front;
		free(temp);
	}
	return value;
}
void displayQueue(struct Queue *q)
{
	struct Node* temp = q->front;
	printf("\nElements in Circular Queue are: ");
	while(temp->link!=q->front)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("%d ",temp->data);
	
}
int main()
{
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
 
    // Display elements present in Circular Queue
    displayQueue(q);
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
 
    // Remaining elements in Circular Queue
    displayQueue(q);
 
    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);
 
    return 0;
	
}
