#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};
struct Stack *createStack(){
	return NULL;
}
void Push(struct Stack **top, int data)
{
	struct Stack *temp ;
	temp=malloc(sizeof(struct Stack));
	if(!temp)
		return NULL;
	temp->data=data;
	temp->next=*top;
	*top =temp;
}
int IsEmptyStack(struct Stack *top)
{
	return top==NULL;
}
int Pop(struct Stack **top)
{
	int data;
	struct Stack *temp;
	if(IsEmptyStack(top))
		return INT_MIN;
	temp=*top;
	*top=*top->next;
	data=temp->data;
	free(temp);
	return data;
}
