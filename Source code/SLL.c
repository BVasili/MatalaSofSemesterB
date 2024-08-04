#define _CRT_SECURE_NO_WARNINGS
#include "SLL.h"

//Common function to both structure
void initList(List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;

	list->head = NULL;
}
void destroyList(List* list)
{
	if (list == NULL)
	{
		return;
	}

	Node* toDestroy = list->head;
	Node* next;
	while (toDestroy != LIST_END)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}

	list->head = EMPTY_LIST;//update list
}
int isEmptyList(const List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;

	//double check for testing purposes
	return (list->head == EMPTY_LIST);
}

//Functions for Visit Structure
Visit Visit_removeFromHead(List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;

	Visit toReturn = list->head->Visit; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	return toReturn;
}
Visit Visit_peekList(const List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;
	return list->head->Visit;
}
void printVisit(Visit Visit) {

	printf("Arrival: ");
	printf("%d/%d/%d ", Visit.tArrival.Day, Visit.tArrival.Month, Visit.tArrival.Year);
	printf("%d:%.2d\n", Visit.tArrival.Hour, Visit.tArrival.Min);
	printf("Dismissed:");

	if (Visit.tDismissed.Day == -1)
		printf("ONGOING\n");
	else
	{
		printf("%d/%d/%d ", Visit.tDismissed.Day, Visit.tDismissed.Month, Visit.tDismissed.Year);
		printf("%d:%.2d\n", Visit.tDismissed.Hour, Visit.tDismissed.Min);
	}

	if (Visit.Duration == -1.0)
		printf("Duration:ONGOING\n", Visit.Duration);
	else
		printf("Durtaion: %d:%.2d\n", ((int)(Visit.Duration) - ((int)(Visit.Duration) % 60)) / 60, (int)(Visit.Duration) % 60);


	printf("Doctor:%s\n", Visit.Doctor->Name);
	printf("Summary:%s\n", Visit.vSummary);
	printf("------------------------------\n\n");

}
void Visit_printList(const List* list, const char* delimiter)
{
	if (checkPointer(list, NULL_POINTER))
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;


	Node* temp;
	Visit Visit;
	do
	{
		temp = list->head;
		Visit = temp->Visit;
		printVisit(Visit);

		//printf("Arrival: ");
		//printf("%d/%d/%d ", Visit.tArrival.Day, Visit.tArrival.Month, Visit.tArrival.Year);
		//printf("%d:%d\n", Visit.tArrival.Hour, Visit.tArrival.Min);
		//printf("Dismissed:");
		//printf("%d/%d/%d ", Visit.tDismissed.Day, Visit.tDismissed.Month, Visit.tDismissed.Year);
		//printf("%d:%d\n", Visit.tDismissed.Hour, Visit.tDismissed.Min);
		//printf("Duration:");//finish this later
		//printf("Doctor:%s", Visit.Doctor->Name);
		//printf("Summary:%s", Visit.vSummary);
		//temp = temp->next;
		//if (temp != NULL)
		//	printf(" %s ", delimiter);
	} while (temp != LIST_END);

}
void Visit_addToHead(List* list, Visit Visit)
{
	if (checkPointer(list, NULL_POINTER))
		return;

	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	if (checkPointer(newHead, ALLOCATION_FAILED))
		return;

	newHead->Visit = Visit;

	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}


//Functions for Doc Structure
Doc Doc_removeFromHead(List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;

	Doc toReturn = list->head->Doctor; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	return toReturn;
}
Doc Doc_peekList(const List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;
	return list->head->Doctor;
}
void Doc_printList(const List* list)
{
	if (checkPointer(list, NULL_POINTER))
	{
		printf("doctors list is empty\n");
		return;
	}


	if (list->head == EMPTY_LIST)
		return;

	int DocNum = 1;
	Node* temp = list->head;
	Doc TempDoctor = temp->Doctor;
	while (temp != NULL)
	{

		printf("%d.\tNAME: %s\t\tNUMBER OF PATIENTS: %d\n", \
			DocNum, TempDoctor.Name, TempDoctor.nPatients);
		DocNum++;
		temp = temp->next;

		if (!temp)
			return;

		TempDoctor = temp->Doctor;
	}
}
void Doc_addToHead(List* list, Doc Doctor)
{
	if (checkPointer(list, NULL_POINTER))
		return;

	//create new list node
	Node* newHead = (Node*)malloc(sizeof(Node));
	if (checkPointer(newHead, ALLOCATION_FAILED))
		return;

	newHead->Doctor = Doctor;
	newHead->next = NULL;
	//case this is very first list element added to empty list
	if (list->head == NULL)
	{
		list->head = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}

Node* searchDoctorInList(Node* ListNode, char* DoctorName)
{
	if (ListNode == NULL) return NULL;
	if (strcmp(ListNode->Doctor.Name,DoctorName) == 0) return ListNode;
	else return searchDoctorInList(ListNode->next, DoctorName);
}
Node* searchDoctor(List* DoctorsList, char* DoctorName)
{
	if (DoctorsList == NULL) return NULL;
	else return searchDoctorInList(DoctorsList->head, DoctorName);
}




