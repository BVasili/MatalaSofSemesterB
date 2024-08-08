#define _CRT_SECURE_NO_WARNINGS
#include "SLL.h"

//Common function to both structure
void initList(List* list)
{
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;

	list->head = NULL; //(:
}
void destroyList(List* list)
{
	if (list == NULL) //if list is empty then it cannot be destroyd
		return;
	

	Node* toDestroy = list->head;
	Node* next;
	while (toDestroy != NULL)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}

	list->head = NULL;
}
int isEmptyList(const List* list)
{
	if (checkPointer(list, NULL_POINTER))
		return;

	//1 if empty and 0 else
	return (list->head == NULL);
}

//Functions for Visit Structure
Visit Visit_removeFromHead(List* list)
{
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;

	Visit toReturn = list->head->Visit; //Save visit structure from head
	Node* temp = list->head->next; //save new head
	free(list->head); // free old head
	list->head = temp; //Update list, New head is the next of the old head
	return toReturn; // returns visit of old head
}
Visit Visit_peekList(const List* list)
{
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;
	return list->head->Visit; //get visit from head
}

//prints induvidual visit -- used in another function with "do while"
void printVisit(Visit Visit) {
	//prints visit's information
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
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;

	Node* temp;
	Visit Visit;
	do
	{ //prints each visit in list
		temp = list->head;
		Visit = temp->Visit;
		printVisit(Visit);
	} while (temp != LIST_END);

}
void Visit_addToHead(List* list, Visit Visit)
{
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;

	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	if (checkPointer(newHead, ALLOCATION_FAILED))  //checks if allcation is ok
		return;

	newHead->Visit = Visit; //inserting given visit to the newly created node

	
	if (list->head == EMPTY_LIST) //if list is empty
		list->head = newHead;//update the list
	else //list has atleast one node
	{
		newHead->next = list->head;
		list->head = newHead;//update the list
	}
}


//Functions for Doc Structure
Doc Doc_removeFromHead(List* list)
{
	if (checkPointer(list, NULL_POINTER))//checks for NULL pointer
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;

	Doc toReturn = list->head->Doctor; //Save doctor structure from head
	Node* temp = list->head->next; //save new head
	free(list->head);// free old head
	list->head = temp;//Update list, New head is the next of the old head
	return toReturn;// returns doctor structure of old head
}
Doc Doc_peekList(const List* list)
{
	if (checkPointer(list, NULL_POINTER)) //checks for NULL pointer
		return;
	if (checkPointer(list->head, NULL_POINTER))
		return;
	return list->head->Doctor; //return structure
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
	//if list is empty
	if (list->head == NULL)
		list->head = newHead;//update the list
	
	else //list has at least one member
	{
		newHead->next = list->head;
		list->head = newHead;//update  the list
	}
}

//returns doctors node from list
Node* searchDoctorInList(Node* DoctorNode, char* DoctorName)
{
	if (DoctorNode == NULL) return NULL;
	if (strcmp(DoctorNode->Doctor.Name, DoctorName) == 0) return DoctorNode; //return doctor structure
	else return searchDoctorInList(DoctorNode->next, DoctorName);
}

//ADT for function above
Node* searchDoctor(List* DoctorsList, char* DoctorName)
{
	if (DoctorsList == NULL) return NULL;
	else return searchDoctorInList(DoctorsList->head, DoctorName);
}




