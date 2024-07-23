#pragma once
#ifndef STACK_HEADER__
#define STACK_HEADER__
#include "Structure.h"
#include "SLL.h"


#ifndef STACKDEFINITION__
#define STACKDEFINITION__
typedef struct Stack
{
	List sList;
	int size;
}Stack;
#endif // !STACKDEFINITION__


//Function declaration for visit

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, Visit Visit);
Visit pop(Stack* s);
Visit peekStack(const Stack* s);
int isEmptyStack(const Stack* s);
void printStack(Stack* s);
int getStackSize(const Stack* s);


#endif // STACK_HEADER__
