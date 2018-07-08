#include<stdio.h>

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
int heigth(struct node * root)
{
	int lheigth, rheigth;
	if(root == NULL)
	{
		return 0;	
	}
	else
	{
		lheigth = heigth(root->left);
		rheigth = heigth(root->right);
		if(lheigth > rheigth)
		return (lheigth + 1);
		else
		return (rheigth + 1);	
	}
}
void printlevel(struct node * root)
{
	int h  =heigth(root);
	int i = 0;
	for(i=1;i<heigth;i++)
	printGivenlevel(root, i);
}
void printGivenlevel(struct node * root , int h)
{
	if(root == NULL)
	return ;
	if(h == 1)
	{
		printf("%d ",root->data);
	}
	else if(h >1)
	{
		printGivenlevel(root->left, h-1);
		printGivenlevel(root->right,h-1);
	}
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
