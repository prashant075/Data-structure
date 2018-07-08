#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * left, *rigth;
	int data;
};
struct node * newnode(int newdata)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data =newdata;
	temp->left = temp->rigth = NULL;
	return (temp);
}
struct node * insert(struct node * root , int key)
{
	if(root == NULL)
	return newnode(key);
	if(key > root->data)
	root->rigth= insert(root->rigth, key);
	else
	root->left = insert(root->left, key);
	return(root);
}
int heigth(struct node *root)
{
	int lheigth= 0, rheigth =0;
	if(root ==NULL)
	{
			return 0;
	}
	else
	{
		lheigth = heigth(root->left);
		rheigth= heigth(root->rigth);
		if(lheigth < rheigth)
		{
			return(rheigth +1);
		}
		else
		{
			return(lheigth+1);
		}
	}
}

void printGivenlevel(struct node * root , int h)
{
	if(root == NULL)
	return ;
	if( h ==1)
	{
		printf("%d ", root->data);
	}
	else
	{
		printGivenlevel(root->left, h-1);
		printGivenlevel(root->rigth,h-1);
	}
}
void printlevelReverse(struct node * root)
{    
	int h=heigth(root);
	int i =0;
	for(i = h ;i>=1; i--)
	printGivenlevel(root, i);
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
	printlevelReverse(root);
	
	return 0;
	
}
