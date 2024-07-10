#pragma once
#ifndef __MY_STACK_HEADER_
#define __MY_STACK_HEADER_

#include "SLL.h"

typedef struct Stack
{
	List sList;
	int size;
}Stack;

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
int peekStack(const Stack* s);
int isEmptyStack(const Stack* s);
void printStack(Stack* s);
int getStackSize(const Stack* s);

#endif // !__MY_STACK_HEADER_
