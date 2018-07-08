#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node * newnode(int newdata)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data =newdata;
	node->left = node->right = NULL;
	return node;
}

int Findmax(struct node * root)
{
	int res,lres,rres;
	if(root == NULL)
	return ;
	 res = root->data;
	lres=Findmax(root->left);
	rres =Findmax(root->right);
	if(lres>res)
	res = lres;
	if(rres>res)
	res = rres;
	return res;
}
int main()
{
	struct node * root = NULL;
	root= newnode(13);
	root->left = newnode(4);
	root->right = newnode(5);
	root->left->left = newnode(7);
	root->left->right = newnode(10);
	printf("Max Element  = %d",Findmax(root));
	return 0;
	
}
