#include"StackVisit.h"
//functions for Visit 

//initalize
void Visit_initStack(Stack* s)
{
	Visit_initList(&(s->sList));
	s->size = 0;
}

//destory stack
void Visit_destroyStack(Stack* s)
{
	Visit_destroyList(&(s->sList));
	s->size = 0;
}

//put into stack
void Visit_push(Stack* s, Visit Visit)
{
	Visit_addToHead(&(s->sList), Visit);
	s->size++;
}

// pop from stack
Visit Visit_pop(Stack* s)
{
	s->size--;
	return Visit_removeFromHead(&(s->sList));
}

int Visit_isEmptyStack(const Stack* s)
{
	return Visit_isEmptyList(&(s->sList));
}

void Visit_printStack(Stack* s)
{
	Stack temp;
	Visit_initStack(&temp);
	while (!Visit_isEmptyStack(s))
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

	while (!Visit_isEmptyStack(&temp))
	{
		Visit_push(s, Visit_pop(&temp));
	}

	Visit_destroyStack(&temp);
}

Visit Visit_peekStack(const Stack* s)
{
	return Visit_peekList(&(s->sList));
}

int Visit_getStackSize(const Stack* s)
{
	return s->size;
}