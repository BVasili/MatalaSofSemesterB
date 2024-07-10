#include "Stack.h"
#include "../Headers/Stack.h"

void initStack(Stack* s)
{
	initList(&(s->sList));
	s->size = 0;
}

void destroyStack(Stack* s)
{
	destroyList(&(s->sList));
	s->size = 0;
}

void push(Stack* s, int data)
{
	addToHead(&(s->sList), data);
	s->size++;
}

int pop(Stack* s)
{
	s->size--;
	return removeFromHead(&(s->sList));
}

int isEmptyStack(const Stack* s)
{
	return isEmptyList(&(s->sList));
}

void printStack(Stack* s)
{
	Stack temp;
	initStack(&temp);
	while (!isEmptyStack(s))
	{
		int popped = pop(s);
		push(&temp, popped);
		printf("| %d |\n", popped);
	}
	printf("-----\n\n");

	while (!isEmptyStack(&temp))
	{
		push(s, pop(&temp));
	}

	destroyStack(&temp);
}

int peekStack(const Stack* s)
{
	return peekList(&(s->sList));
}

int getStackSize(const Stack* s)
{
	return s->size;
}