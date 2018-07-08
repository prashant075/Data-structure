#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
	unsigned capacity;
	int * array;
	int top; 
};
struct Stack* CreateStack(unsigned capacity)
{
	struct Stack * stack =(struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array =(int*)malloc(stack->capacity*sizeof(int));
	return stack;
}
int isFull(struct Stack* stack){
	return stack->top==stack->capacity-1;
}
int isEmpty(struct Stack* stack){
	return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
	if(isFull(stack))
	return;
	stack->array[++stack->top]=item;
	printf("%d Pushed to Stack\n",item);
}
int pop(struct Stack* stack){
	if(isEmpty(stack))
	return INT_MIN;
	return stack->array[stack->top--];
}
int main()
{
	struct Stack * stack =CreateStack(100);
	push(stack,10);
	push(stack,20);
	push(stack,30);
	printf("%d Poped from Stack\n",pop(stack));
	return 0;
}
