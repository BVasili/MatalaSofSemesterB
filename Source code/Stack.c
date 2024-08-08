#include "Stack.h"

//initalize stack
void initStack(Stack* s)
{
	initList(&(s->sList));
	s->size = 0;
}

//destory stack
void destroyStack(Stack* s)
{
	destroyList(&(s->sList));
	s->size = 0;
}

//put into stack
void push(Stack* s, Visit Visit)
{
	Visit_addToHead(&(s->sList), Visit);
	s->size++;
}

// pop from stack
Visit pop(Stack* s)
{
	s->size--;
	return Visit_removeFromHead(&(s->sList));
}

// return 1 if stack is empty
int isEmptyStack(const Stack* s)
{
	return isEmptyList(&(s->sList));
}

//prints the stack
void printStack(Stack* s)
{
	Stack temp;
	initStack(&temp);
	while (!isEmptyStack(s))
	{
		Visit popped = pop(s);
		push(&temp, popped);
		printVisit(popped);
	}

	while (!isEmptyStack(&temp))
	{
		push(s, pop(&temp));
	}
	destroyStack(&temp);
}

//get the visit from top of stack
Visit peekStack(const Stack* s)
{
	return Visit_peekList(&(s->sList));
}

//get stack size
int getStackSize(const Stack* s)
{
	return s->size;
}