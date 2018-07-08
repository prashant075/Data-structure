#include<stdio.h>
#include<stdlib.h>
#define bool int

struct snode{
	char data;
	struct snode* next;
};
void push(struct snode** top, int new_data);
 
int pop(struct snode** top);
bool isMatching(char c1, char c2)
{
	if(c1 =='[' && c2 ==']')
	return 1;
	else if(c1=='{' && c2 =='}')
	return 1;
	else if(c1=='('&& c2 ==')')
	return 1;
	else
	return 0;
}

bool isparathensis(char exp[])
{
	int i  =0;
	struct snode * stack = NULL;
	while(exp[i])
	{
		if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
		push(&stack,exp[i]);
		
		if(exp[i]==']' || exp[i]=='}'|| exp[i]==')')
		{
			if(stack == NULL)
			return 0;
			
			else if(!isMatching(pop(&stack),exp[i]))
			return 0;
		}
		i++;
	}
	if(stack ==NULL)
	return 1;
	else
	return 0;
}

void push(struct snode **top , int new_data)
{
	struct snode * new_node = (struct snode*)malloc(sizeof(struct snode));
	if(new_node ==NULL)
	{
		printf("Stack is Overflow");
		getchar();
		exit(0);
	}
	new_node->data = new_data;
	new_node->next = (*top);
	(*top)=new_node;
}
int pop(struct snode **top)
{
	char res;
	struct snode *top_value;
	if(*top == NULL)
	{
		printf("Stack is Overflow");
		getchar();
		exit(0);
	}
	else
	{
		top_value = *top;
		res = top_value->data;
		*top=top_value->next;
		free(top_value);
		return res;	
	}
}
int main()
{
	char exp[100]="({A+B+C+C}(A*V))[A+V]";
	if(isparathensis(exp))
	printf("Balanced");
	else
	printf("Not Balanced");
	return 0;
}
