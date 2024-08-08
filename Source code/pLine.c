#include"pTree.h"
#include "pLine.h"
#include<stdlib.h>
#include"displayError.h"

//Deletes pInLine node
void deletePLine(pInLine* ToBeDeleted)
{
	if (ToBeDeleted == NULL) // if address is NULL it returns
		return;
	
	pInLine* toDestroy = ToBeDeleted;
	pInLine* next;

	while (toDestroy != NULL)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}
}

//Adds to tail --- used in anoter ADT function
void AddToTailLine(pLine* q, char* ID, pTree* tree)
{
	pInLine* newTail = (pInLine*)calloc(1, sizeof(pInLine));

	if (!newTail) {
		displayError(ALLOCATION_FAILED);
		return;
	}

	newTail->lpatient = searchPatient(tree, ID); //loads patient from tree using a fucntion that returns a ptr to patients structure

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

//removes from head and returns ptr to the patient
Patient* RemoveHeadFromLine(pLine* q) {

	if (q == NULL)
		return NULL;

	if (q->head == NULL)
		return NULL;

	q->size--;

	//save head
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

//returns structure from head
Patient GetFromHead(const pLine* q)
{
	Patient toBeReturned = *q->head->lpatient;
	return toBeReturned;
}

//check if line is empty
int CheckLineHead(const pLine* q)
{
	return q->head == NULL;
}

//prints all Line --- used for another ADT function
void printLineForADT(const pLine* q)
{
	if (q->head == NULL)
		return;
	int index = 1;
	pInLine* temp = q->head;

	while (temp != NULL)
	{
		printf("%d. Name:%s ID:%s\n",index++, temp->lpatient->Name,temp->lpatient->ID);
		temp = temp->next;


	}
}



//searches for patients in line and returns ptr to them
pInLine* searchPatientLine(pInLine* PatientInLine, char* ID)
{
	if (PatientInLine == NULL) return NULL;
	if (strcmp(PatientInLine->lpatient->ID, ID) == 0) return PatientInLine;
	else
		searchPatientLine(PatientInLine->next, ID);
}
//prints line with patients ongoing visit
void printLineWithVisit(const pLine* q) {
	{
		if (q->head == NULL)
			return;
		int index = 1;
		pInLine* temp = q->head;
		Visit CurrentVisit;
		while (temp != NULL)
		{
			printf("%d.Name:%s ID:%s\n", index++,temp->lpatient->Name, temp->lpatient->ID);
			CurrentVisit = peekStack(temp->lpatient->Visits);

			printf("Arrival: ");
			printf("%d/%d/%d ", CurrentVisit.tArrival.Day, CurrentVisit.tArrival.Month, CurrentVisit.tArrival.Year);
			printf("%d:%d\n", CurrentVisit.tArrival.Hour, CurrentVisit.tArrival.Min);

			if (CurrentVisit.Duration == -1)
			{
				printf("Dismissed: ONGOING\n");
				printf("Duration:ONGOING\n");//finish this later
			}
			else
			{
				printf("%d/%d/%d ", CurrentVisit.tDismissed.Day, CurrentVisit.tDismissed.Month, CurrentVisit.tDismissed.Year);
				printf("%d:%d\n", CurrentVisit.tDismissed.Hour, CurrentVisit.tDismissed.Min);
			}

			printf("Doctor:%s\n", CurrentVisit.Doctor->Name);
			printf("Summary:%s\n", CurrentVisit.vSummary);
			printf("--------------------------\n\n");

			temp = temp->next;
		}
	}
}

// ADT Functions
//initalizes line
void initLine(pLine* q)
{
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

//puts patient into line
void enLine(pLine* q, char* ID, pTree* tree)
{
	AddToTailLine(q, ID, tree);
}

//remove patient from line
Patient* deLine(pLine* q)
{
	RemoveHeadFromLine(q);
}

//destorys line
void destroyLine(pLine* q)
{
	deletePLine(q->head);
	q->size = 0;
}

//gets patients structure from head of line
Patient peekLine(const pLine* q)
{
	return GetFromHead(q);
}

//check if line is empty
int isEmptyLine(const pLine* q)
{
	return CheckLineHead(q);
}

//prints line
void printLine(const pLine* q)
{
	printf("Head of Queue| \n");
	printLineForADT(q);
	printf(" |Tail of Queue\n\n");
}

//gets line size
int getLineSize(const pLine* q)
{
	return q->size;
}

//Retunrs ptr to patient in line -- is ADT
pInLine* searchPatientInLine(pLine* queue, char* ID)
{
	return searchPatientLine(queue->head, ID);
}

//moves patient to head of line
void moveToHead(pLine* q, char* ID) {

	if (q == NULL || q->head == NULL) 
		return;
	

	pInLine* prev = NULL;
	pInLine* current = q->head;

	// search for the patient with the given ID
	while (current != NULL && strcmp(current->lpatient->ID, ID) != 0) {
		prev = current;
		current = current->next;
	}

	// if the patient is not found, return
	if (current == NULL) {
		return;
	}

	// if the patient is already at the head, do nothing
	if (current == q->head) {
		return;
	}

	// remove the patient from its current position
	if (prev != NULL) {
		prev->next = current->next;
	}
	if (current == q->tail) {
		q->tail = prev;
	}

	// insert the patient at the head of the line
	current->next = q->head;
	q->head = current;
	if (q->tail == NULL) {
		q->tail = current;
	}
}

