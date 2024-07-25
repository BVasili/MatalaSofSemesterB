#include "Stack.h"

//initalize
void initStack(Stack* s)
{
	initList(&(s->sList));
	s->size = 0;
}

//destory stack
void destroyStack(Stack* s)
{
	Visit_destroyList(&(s->sList));
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
	return Visit_isEmptyList(&(s->sList));
}

void printStack(Stack* s)
{
	Stack temp;
	initStack(&temp);
	while (!isEmptyStack(s))
	{
		Visit popped = pop(s);
		push(&temp, popped);
		printf("Arrival: ");
		printf("%d/%d/%d ", popped.tArrival.Day, popped.tArrival.Month, popped.tArrival.Year);
		printf("%d:%d\n", popped.tArrival.Hour, popped.tArrival.Min);
		printf("Dismissed:");

		if (popped.tDismissed.Day == -1) 
			printf("ONGOING\n");
		else
		{
			printf("%d/%d/%d ", popped.tDismissed.Day, popped.tDismissed.Month, popped.tDismissed.Year);
			printf("%d:%d\n", popped.tDismissed.Hour, popped.tDismissed.Min);
		}

		if (popped.Duration == -1.0)
			printf("Duration:ONGOING\n", popped.Duration);
		else 
			printf("Durtaion: %d:%d\n", ((int)(popped.Duration) - ((int)(popped.Duration) % 60)) / 60, (int)(popped.Duration) % 60);
		
		
		printf("Doctor:%s\n", popped.Doctor->Name);
		printf("Summary:%s\n", popped.vSummary);
		printf("------------------------------\n\n");
	}
	
	while (!isEmptyStack(&temp))
	{
		push(s, pop(&temp));
	}
	destroyStack(&temp);
}

Visit peekStack(const Stack* s)
{
	return Visit_peekList(&(s->sList));
}

int getStackSize(const Stack* s)
{
	return s->size;
}