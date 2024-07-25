#include"pTree.h"
#include "pLine.h"
#include<stdlib.h>
#include"displayError.h"

//Functions for ADT
void deletePLine(pInLine* ToBeDeleted)
{
	if (ToBeDeleted == NULL)
	{
		return;
	}

	pInLine* toDestroy = ToBeDeleted;
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
	if (q->head == NULL)
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
pInLine* searchPatientInLine(pLine* queue, char* ID)
{
	return searchPatientLine(queue->head, ID);
}
void printLineWithVisit(const pLine* q) {
	{
		if (q->head == NULL)
			return;

		pInLine* temp = q->head;
		Visit CurrentVisit;
		while (temp != NULL)
		{
			printf("Name:%s ID:%s\n", temp->lpatient->Name, temp->lpatient->ID);
			CurrentVisit = peekStack(temp->lpatient->Visits);

			printf("Arrival: ");
			printf("%d/%d/%d ", CurrentVisit.tArrival.Day, CurrentVisit.tArrival.Month, CurrentVisit.tArrival.Year);
			printf("%d:%d\n", CurrentVisit.tArrival.Hour, CurrentVisit.tArrival.Min);

			if (CurrentVisit.Duration == -1)
			{
				printf("Dismissed: ONGOING\n");
				printf("Duration:ONGING\n");//finish this later
			}
			else
			{
				printf("%d/%d/%d ", CurrentVisit.tDismissed.Day, CurrentVisit.tDismissed.Month, CurrentVisit.tDismissed.Year);
				printf("%d:%d\n", CurrentVisit.tDismissed.Hour, CurrentVisit.tDismissed.Min);
			}

			printf("Doctor:%s\n", CurrentVisit.Doctor->Name);
			printf("Summary:%s\n", CurrentVisit.vSummary);
			printf("--------------------------\n");

			temp = temp->next;
		}
	}
}

// Public functions
void initLine(pLine* q)
{
	q->head = NULL;
	q->tail = NULL;
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
	deletePLine(q->head);
	q->size = 0;
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
pInLine* searchPatientLine(pInLine* PatientInLine, char* ID)
{
	if (PatientInLine == NULL) return NULL;
	if (strcmp(PatientInLine->lpatient->ID, ID) == 0) return PatientInLine;
	else
		searchPatientLine(PatientInLine->next, ID);
}

