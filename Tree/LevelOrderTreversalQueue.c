#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left,*right;
	int data;
};
struct node * newnode(int newdata)
{
	struct node * temp =(struct node *)malloc(sizeof(struct node));
	temp->data = newdata;
	temp->left = temp->right = NULL;
	return (temp);
}
struct node * insert(struct node * root , int key)
{
	if(root == NULL)
	return newnode(key);
	else if(key > root->data)
	root->right = insert(root->right, key);
	else
	root->left = insert(root->left, key);
	return(root);
}
/*---------------------Queue------------*/
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
void DeleteQueue(struct Queue *Q){
	struct ListNode *temp ;
	while(!IsEmptyQueue(Q))
	{
		temp=Q->front;
		Q->front=Q->front->next;
		free(temp);
	}
}
/*------------------------------------------*/
void printlevel(struct node* root)
{
	struct node *temp;
	struct Queue *Q = createQueue();
	if(!root)
		return;
	EnQueue(Q,root->data);
	
	while(!IsEmptyQueue(Q)){
		
		printf("%d ",DeQueue(Q));
		
		if(temp->left)
			EnQueue(Q,temp->left->data);
		if(temp->right)
			EnQueue(Q,temp->right->data);
	}
	DeleteQueue(Q);
}
int main()
{
	struct node *root = NULL;
	root =insert(root,50);
	insert(root,40);
	insert(root, 60);
	insert(root,30);
	insert(root,45);
	insert(root,55);
	insert(root,65);
	printlevel(root);
	
	return 0;
	
}
