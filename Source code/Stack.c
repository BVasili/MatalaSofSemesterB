#include "Stack.h"


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

//functions for Visit 

//initalize
void Visit_initStack(Stack* s)
{
	VisitinitList(&(s->sList));
	s->size = 0;
}

//destory stack
void Visit_destroyStack(Stack* s)
{
	VisitdestroyList(&(s->sList));
	s->size = 0;
}

//put into stack
void Visit_push(Stack* s, Visit Visit)
{
	VisitaddToHead(&(s->sList), Visit);
	s->size++;
}

// pop from stack
Visit Visit_pop(Stack* s)
{
	s->size--;
	return VisitremoveFromHead(&(s->sList));
}

int Visit_EmptyStack(const Stack* s)
{
	return VisitisEmptyList(&(s->sList));
}

void Visit_printStack(Stack* s)
{
	Stack temp;
	Visit_initStack(&temp);
	while (!Visit_EmptyStack(s))
	{
		Visit popped = Visit_pop(s);
		Visit_push(&temp, popped);
		printf("Arrival: ");
		printf("%d/%d/%d ", popped.tArrival.Day, popped.tArrival.Month, popped.tArrival.Year);
		printf("%d:%d\n", popped.tArrival.Hour, popped.tArrival.Min);
		printf("Dismissed:");
		printf("%d/%d/%d ", popped.tDismissed.Day, popped.tDismissed.Month, popped.tDismissed.Year);
		printf("%d:%d\n", popped.tDismissed.Hour, popped.tDismissed.Min);
		printf("Duration: %0.f\n", popped.Duration);//finish this later
		printf("Doctor:%s\n", popped.Doctor->Name);
		printf("Summary:%s\n", popped.vSummary);
		
	}
	printf("------------------------------\n\n");

	while (!Visit_EmptyStack(&temp))
	{
		Visit_push(s, Visit_pop(&temp));
	}

	Visit_destroyStack(&temp);
}

Visit Visit_peekStack(const Stack* s)
{
	return VisitpeekList(&(s->sList));
}

int Visit_getStackSize(const Stack* s)
{
	return s->size;
}