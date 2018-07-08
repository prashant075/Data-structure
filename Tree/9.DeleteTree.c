#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left,*right;
	int data;
};
struct node *newnode(int newdata)
{
	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->data=newdata;
	temp->left=temp->right=NULL;
	return(temp);
}
struct node* insert(struct node * root, int key)
{
	if(root ==NULL)
	return newnode(key);
	if(root->data <key)
	root->right=insert(root->right, key);
	else
	root->left=insert(root->left,key);
	return(root);
}
void preorder(struct node * root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void deletetree(struct node *root)
{
	if(root==NULL)
	printf("Tree deleted");
	deletetree(root->left);
	deletetree(root->right);
	free(root);
}
int main()
{
	struct node* root =NULL;
	root =insert(root,50);
	insert(root,40);
	insert(root, 60);
	insert(root,30);
	insert(root,45);
	insert(root,55);
	insert(root,65);
	preorder(root);
	deletetree(root);
	preorder(root);
	return 0;
	
}
