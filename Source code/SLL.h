#pragma once
#ifndef SLL_HEADER__
#define SLL_HEADER__

#include "Structure.h"
#include"displayError.h"
#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

typedef struct Node
{
	Visit Visit;
	Doc Doctor;
	struct Node* next;
}Node;


typedef struct List
{
	Node* head;
} List;

void initList(List* list);

//SLL function declaration for Visit Structure
void Visit_addToHead(List* list, Visit Visit);
Visit Visit_removeFromHead(List* list);
Visit Visit_peekList(const List* list);
void printVisit(Visit);
void Visit_printList(const List* list, const char* delimiter);
int Visit_isEmptyList(const List* list);
void Visit_destroyList(List* list);



//SLL function declaration for Doc Structure
void Doc_addToHead(List* list, Doc Doctor);
Doc Doc_removeFromHead(List* list);
Doc Doc_peekList(const List* list);
void Doc_printList(const List* list);
int Doc_isEmptyList(const List* list);
void Doc_destroyList(List* list);
Node* searchDoctorInList(Node*, char*);
Node*  searchDoctor(List*, char*);
#endif // SLL_HEADER__