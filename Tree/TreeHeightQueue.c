#include<stdio.h>
#include<stdlib.h>

struct Qnode{
	int data;
	struct Qnode* next;
};

struct Queue{
	struct Qnode *front, *rear;
};
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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
int IsEmptyQueue(struct Queue *q)
{
	return(q->front ==NULL);
}
int treeHeight(struct node * root)
{
	int level  =1;
	struct Queue *q;
	if(!root)
		return 0;
	q = createQueue();
	enQueue(q,root->data);
	enQueue(q,0);
	while(!IsEmptyQueue(q))
	{
		root=(struct node*)deQueue(q);
		if(root==NULL)
		{
			if(!IsEmptyQueue(q))
				enQueue(q,0);
			level++;
		}
		else
		{
			if(root->left)
				enQueue(q,root->left->data);
			if(root->right)
				enQueue(q,root->right->data);
		}
	}
	return level;	
}

int main()
{
 	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    printf("Height of tree is %d" ,treeHeight(root));
    return 0;
}
