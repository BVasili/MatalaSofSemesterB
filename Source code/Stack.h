#pragma once
#ifndef STACK_HEADER__
#define STACK_HEADER__
#include "Structure.h"
#include "SLL.h"


//This was defined in "Structure.h" b
//typedef struct Stack
//{
//	List sList;
//	int size;
//}Stack;

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
int peekStack(const Stack* s);
int isEmptyStack(const Stack* s);
void printStack(Stack* s);
int getStackSize(const Stack* s);

//Function declaration for visit

void VisitinitStack(Stack* s);
void VisitdestroyStack(Stack* s);
void Visitpush(Stack* s, Visit Visit);
Visit Visitpop(Stack* s);
Visit VisitpeekStack(const Stack* s);
int VisitisEmptyStack(const Stack* s);
void VisitprintStack(Stack* s);
int VisitgetStackSize(const Stack* s);

#endif // STACK_HEADER__
