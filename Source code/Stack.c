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

void VisitinitStack(Stack* s)
{
	VisitinitList(&(s->sList));
	s->size = 0;
}

void VisitdestroyStack(Stack* s)
{
	VisitdestroyList(&(s->sList));
	s->size = 0;
}

void Visitpush(Stack* s, Visit Visit)
{
	VisitaddToHead(&(s->sList), Visit);
	s->size++;
}

Visit Visitpop(Stack* s)
{
	s->size--;
	return VisitremoveFromHead(&(s->sList));
}

int VisitisEmptyStack(const Stack* s)
{
	return VisitisEmptyList(&(s->sList));
}

void VisitprintStack(Stack* s)
{
	Stack temp;
	VisitinitStack(&temp);
	while (!VisitisEmptyStack(s))
	{
		Visit popped = Visitpop(s);
		Visitpush(&temp, popped);
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

	while (!VisitisEmptyStack(&temp))
	{
		Visitpush(s, Visitpop(&temp));
	}

	VisitdestroyStack(&temp);
}

Visit VisitpeekStack(const Stack* s)
{
	return VisitpeekList(&(s->sList));
}

int VisitgetStackSize(const Stack* s)
{
	return s->size;
}