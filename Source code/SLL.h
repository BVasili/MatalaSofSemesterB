#pragma once
#include "Structure.h"
#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"

////These was defined in "Structure.h" to prevent conflicts
//typedef struct Node
//{
//	int data;
//	Visit Visit;
//	struct Node* next;
//}Node;
//
//
//typedef struct List
//{
//	Node* head;
//	Node* tail;
//} List;

//SLL function declaration for int
void checkNullLogExit(const void* object, const char* message);
void initList(List* list);
void addToHead(List* list, int data);
int removeFromHead(List* list);
int peekList(const List* list);
void addToTail(List* list, int data);
int removeFromTail(List* list);
void printList(const List* list, const char* delimiter);
int isEmptyList(const List* list);
void destroyList(List* list);

//SLL function declaration for Visit Structure
void VisitcheckNullLogExit(const void* object, const char* message);
void VisitinitList(List* list);
void VisitaddToHead(List* list, Visit Visit);
Visit VisitremoveFromHead(List* list);
Visit VisitpeekList(const List* list);
void VisitaddToTail(List* list, Visit Visit);
Visit VisitremoveFromTail(List* list);
void VisitprintList(const List* list, const char* delimiter);
int VisitisEmptyList(const List* list);
void VisitdestroyList(List* list);