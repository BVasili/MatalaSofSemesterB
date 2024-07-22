#include"pTree.h"
#include "pLine.h"
#include<stdlib.h>
#include"displayError.h"

//Functions for ADT
void deletePLine(pLine* ToBeDeleted) 
{
	if (ToBeDeleted == NULL)
	{
		return;
	}

	ToBeDeleted->size = 0;

	pInLine* toDestroy = ToBeDeleted->head;
	pInLine* next;
	while (toDestroy != NULL)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}
}
void AddToTailLine(pLine* q, char* ID, pTree* tree)
{
	pInLine* newTail = (pInLine*)calloc(1, sizeof(pInLine));

	if (!newTail) {
		displayError(ALLOCATION_FAILED);
		return;
	}
	newTail->lpatient = searchPatient(tree, ID);

	//case this is very first list element added to empty list
	if (q->tail == NULL)
	{
		q->head = q->tail = newTail;//update list
		return;
	}
	else //list has at least one element
	{
		q->tail->next = newTail;
		q->tail = newTail;//update list
	}

	q->size++;
}
Patient* RemoveHeadFromLine(pLine* q) {

	if (q == NULL)
		return NULL;

	if (q->head == NULL)
		return NULL;

	q->size--;

	//save return value
	Patient* toReturn = q->head->lpatient;

	//save new list head
	pInLine* temp = q->head->next;

	free(q->head);

	//update list
	q->head = temp;

	//check if list has become empty after removal
	if (q->head == NULL)
		q->tail = NULL;//update list

	return toReturn;
}
Patient GetFromHead(const pLine* q) 
{
	Patient toBeReturned = *q->head->lpatient;
	return toBeReturned;
}
int CheckLineHead(const pLine* q) 
{
	return q->head == NULL;
}
void printLineADT(const pLine* q) 
{
	if (q->head ==NULL)
		return;
	
	pInLine* temp = q->head;

	while (temp != NULL)
	{
		printf("%s", temp->lpatient->ID);
		temp = temp->next;

		if (temp != NULL)
			printf(" | ");
	}
}


void initLine(pLine* q)
{
	q->head = NULL;
	q->size = 0;
}
void enLine(pLine* q, char* ID, pTree* tree)
{
	AddToTailLine(q, ID, tree);
}
Patient* deLine(pLine* q)
{
	RemoveHeadFromLine(q);
}
void destroyLine(pLine* q)
{
	deletePLine(q);
}
Patient peekLine(const pLine* q)
{
	return GetFromHead(q);
}
int isEmptyLine(const pLine* q)
{
	return CheckLineHead(q);
}
void printLine(const pLine* q)
{
	printf("Head of Queue| ");
	printLineADT(q);
	printf(" |Tail of Queue\n\n");
}
int getLineSize(const pLine* q)
{
	return q->size;
}