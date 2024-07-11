#pragma once

#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"


typedef struct Node
{
	int data;
	struct Node* next;
}Node;


typedef struct List
{
	Node* head;
} List;

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