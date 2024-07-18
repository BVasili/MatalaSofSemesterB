#pragma once
#ifndef SLL_HEADER__
#define SLL_HEADER__

#include "Structure.h"
#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"


typedef struct Node
{
	int data;
	Visit Visit;
	Patient Patient;
	Patient* Ptr2Patient;
	Doc Doctor;
	struct Node* next;
}Node;


typedef struct List
{
	Node* head;
	Node* tail;
} List;

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
void Visit_checkNullLogExit(const void* object, const char* message);
void Visit_initList(List* list);
void Visit_addToHead(List* list, Visit Visit);
Visit Visit_removeFromHead(List* list);
Visit Visit_peekList(const List* list);
void Visit_addToTail(List* list, Visit Visit);
Visit Visit_removeFromTail(List* list);
void Visit_printList(const List* list, const char* delimiter);
int Visit_isEmptyList(const List* list);
void Visit_destroyList(List* list);

//SLL function declaration for Patient Structure

void Line_checkNullLogExit(const void* object, const char* message);
void Line_initList(List* list);
void Line_addToHead(List* list, Patient* Patient);
Patient* Line_removeFromHead(List* list);
Patient* Line_peekList(const List* list);
void Line_addToTail(List* list, Patient* Patient);
Patient* Line_removeFromTail(List* list);
void Line_printList(const List* list, const char* delimiter);
int Line_isEmptyList(const List* list);
void Line_destroyList(List* list);

//SLL function declaration for Doc Structure

void Doc_checkNullLogExit(const void* object, const char* message);
void Doc_initList(List* list);
void Doc_addToHead(List* list, Doc Doctor);
Doc Doc_removeFromHead(List* list);
Doc Doc_peekList(const List* list);
void Doc_addToTail(List* list, Doc Patient);
Doc Doc_removeFromTail(List* list);
void Doc_printList(const List* list, const char* delimiter);
int Doc_isEmptyList(const List* list);
void Doc_destroyList(List* list);



#endif // SLL_HEADER__