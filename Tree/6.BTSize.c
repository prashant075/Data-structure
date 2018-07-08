#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *left, *right;
	int data;
};

struct node* newnode(int newdata)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = newdata;
	temp->left=temp->right = NULL;
	return (temp);
}

struct node * insert(struct node * root, int key)
{
	if(root==NULL)
	return newnode(key);
	else if(key<root->data)
	root->left = insert(root->left, key);
	else
	root->right = insert(root->right, key);
	return (root);
}
void inorder(struct node * root)
{
	if(root!= NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
int SizeBst(struct node * root)
{
	if(root == NULL)
	return 0;
	else
	return (SizeBst(root->left)+1+SizeBst(root->right));
}
int main()
{
	struct node *root = NULL;
	root =insert(root,10);
	insert(root,20);
	insert(root, 70);
	insert(root,30);
	insert(root,40);
	insert(root,50);
	insert(root,60);
	inorder(root);
	printf("\nSize of Tree %d",SizeBst(root));
	return 0;
	
}
