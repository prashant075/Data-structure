#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *left, *right;
	int data;
};

struct node *newnode(int newdata)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data = newdata;
	temp->left = temp->right = NULL;
	return (temp);
}
struct node *insert(struct node *root, int key)
{
	if(root ==NULL)
	return newnode(key);
	
	if(key < root->data)
	root->left = insert(root->left,key);
	
	else if (key > root->data)
	root->right = insert(root->right,key);
	
	return root;
}
void inorder(struct node * root)
{
	if(root != NULL )
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
int find(struct node * root, int value)
{
	int temp ;
	if(root == NULL)
	return 0;
	else
	{
		if(value==root->data)
		return 1;
		else{
		temp = find(root->left, value);
		if(temp !=0)
		return temp ;
		else
		return find(root->right,value);
		}
	
	}
	return 0;
}

int main()
{
	struct node * root = NULL;
	root = insert(root, 10);
	insert(root, 20);
	insert(root, 30);
	insert(root,40);
	insert(root,5);
	insert(root,6);
	inorder(root);
	struct node * val =search( root, 100);
	printf("\n%p ", val );
	printf("\n%d",find(root,10));
	return 0;
}
