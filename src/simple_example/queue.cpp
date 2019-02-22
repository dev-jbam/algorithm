#if 0

#include <stdio.h>

#define MAX_N 100

int top;
int stack[MAX_N];

void stackInit(void)
{
	top = 0;
}

int stackIsEmpty(void)
{
	return (top == 0);
}

int stackIsFull(void)
{
	return (top == MAX_N);
}

int stackPush(int value)
{
	if (stackIsFull())
	{
		printf("stack overflow!");
		return 0;
	}
	stack[top] = value;
	top++;

	return 1;
}

int stackPop(int *value)
{
	if (top == 0) 
	{
		printf("stack is empty!");
		return 0;
	}
	top--;
	*value = stack[top];

	return 1;
}

#endif