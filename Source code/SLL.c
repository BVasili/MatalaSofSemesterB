#define _CRT_SECURE_NO_WARNINGS
#include "SLL.h"

//Functions for INT
void initList(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	list->head = list->tail = EMPTY_LIST;
}

void checkNullLogExit(const void* object, const char* message)
{
	if (object == NULL)
	{
		FILE* logErrors = fopen("logErrors.txt", "w");
		if (logErrors != NULL && message != NULL)
		{
			fprintf(logErrors, "%s", message);
			fprintf(stderr, "%s", message);
		}
		exit(EXIT_FAILURE);
	}
}

int removeFromHead(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);

	int toReturn = list->head->data; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	//check if list has become empty after removal
	if (list->head == EMPTY_LIST)
	{
		list->tail = EMPTY_LIST;//update list
	}
	return toReturn;
}

int peekList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	return list->head->data;
}

void printList(const List* list, const char* delimiter)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);

	if (list->head == EMPTY_LIST)
	{
		return;
	}

	Node* temp = list->head;
	while (temp != LIST_END)
	{
		printf("%d", temp->data);
		temp = temp->next;
		if (temp != NULL)
			printf(" %s ", delimiter);
	}

}

void addToTail(List* list, int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newTail = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newTail, BAD_ALLOC);
	newTail->data = data;
	//case this is very first list element added to empty list
	if (list->tail == EMPTY_LIST)
	{
		list->head = list->tail = newTail;//update list
		return;
	}
	else //list has at least one element
	{
		list->tail->next = newTail;
		list->tail = newTail;//update list
	}
}

int isEmptyList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//double check for testing purposes
	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST);
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

	list->head = list->tail = EMPTY_LIST;//update list
}

void addToHead(List* list, int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newHead, BAD_ALLOC);
	newHead->data = data;
	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = list->tail = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}

int removeFromTail(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	//temp nodes to iterate over list and find the element previous to tail
	Node* current = list->head;
	Node* previous = NULL;
	while (current->next != LIST_END)
	{
		previous = current;
		current = current->next;
	}

	int toReturn = current->data;//save return value
	free(current);
	list->tail = previous;//update list
	//check if list has become empty after removal
	if (list->tail == EMPTY_LIST)
	{
		list->head = EMPTY_LIST;//update list
	}
	else
	{
		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
	}

	return toReturn;
}




//Functions for Visit Structure

void Visit_initList(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	list->head = list->tail = EMPTY_LIST;
}

void Visit_checkNullLogExit(const void* object, const char* message)
{
	if (object == NULL)
	{
		FILE* logErrors = fopen("logErrors.txt", "w");
		if (logErrors != NULL && message != NULL)
		{
			fprintf(logErrors, "%s", message);
			fprintf(stderr, "%s", message);
		}
		exit(EXIT_FAILURE);
	}
}

Visit Visit_removeFromHead(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);

	Visit toReturn = list->head->Visit; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	//check if list has become empty after removal
	if (list->head == EMPTY_LIST)
	{
		list->tail = EMPTY_LIST;//update list
	}
	return toReturn;
}

Visit Visit_peekList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	return list->head->Visit;
}

void Visit_printList(const List* list, const char* delimiter)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);

	if (list->head == EMPTY_LIST)
	{
		return;
	}

	Node* temp = list->head;
	Visit Visit = temp->Visit;
	while (temp != LIST_END)
	{
		printf("Arrival: ");
		printf("%d/%d/%d ",Visit.tArrival.Day, Visit.tArrival.Month, Visit.tArrival.Year);
		printf("%d:%d\n", Visit.tArrival.Hour, Visit.tArrival.Min);
		printf("Dismissed:");
		printf("%d/%d/%d ", Visit.tDismissed.Day, Visit.tDismissed.Month, Visit.tDismissed.Year);
		printf("%d:%d\n", Visit.tDismissed.Hour, Visit.tDismissed.Min);
		printf("Duration:");//finish this later
		printf("Doctor:%s", Visit.Doctor->Name);
		printf("Summary:%s", Visit.vSummary);
		temp = temp->next;
		if (temp != NULL)
			printf(" %s ", delimiter);
	}

}

void Visit_addToTail(List* list, Visit Visit)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newTail = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newTail, BAD_ALLOC);
	newTail->Visit = Visit;
	//case this is very first list element added to empty list
	if (list->tail == EMPTY_LIST)
	{
		list->head = list->tail = newTail;//update list
		return;
	}
	else //list has at least one element
	{
		list->tail->next = newTail;
		list->tail = newTail;//update list
	}
}

int Visit_isEmptyList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//double check for testing purposes
	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST);
}

void Visit_destroyList(List* list)
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

	list->head = list->tail = EMPTY_LIST;//update list
}

void Visit_addToHead(List* list, Visit Visit)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newHead, BAD_ALLOC);
	newHead->Visit = Visit;
	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = list->tail = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}

Visit Visit_removeFromTail(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	//temp nodes to iterate over list and find the element previous to tail
	Node* current = list->head;
	Node* previous = NULL;
	while (current->next != LIST_END)
	{
		previous = current;
		current = current->next;
	}

	Visit toReturn = current->Visit;//save return value
	free(current);
	list->tail = previous;//update list
	//check if list has become empty after removal
	if (list->tail == EMPTY_LIST)
	{
		list->head = EMPTY_LIST;//update list
	}
	else
	{
		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
	}

	return toReturn;
}



////Functions for Doc Structure
//
//void Doc_initList(List* list)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	list->head = list->tail = EMPTY_LIST;
//}
//
//void Doc_checkNullLogExit(const void* object, const char* message)
//{
//	if (object == NULL)
//	{
//		FILE* logErrors = fopen("logErrors.txt", "w");
//		if (logErrors != NULL && message != NULL)
//		{
//			fprintf(logErrors, "%s", message);
//			fprintf(stderr, "%s", message);
//		}
//		exit(EXIT_FAILURE);
//	}
//}
//
//Doc Doc_removeFromHead(List* list)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	checkNullLogExit(list->head, LIST_POINTER_ERROR);
//
//	Doc toReturn = list->head->Doctor; //save return value
//	Node* temp = list->head->next; //save new list head
//	free(list->head);
//	list->head = temp;//update list
//	//check if list has become empty after removal
//	if (list->head == EMPTY_LIST)
//	{
//		list->tail = EMPTY_LIST;//update list
//	}
//	return toReturn;
//}
//
//Doc Doc_peekList(const List* list)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	checkNullLogExit(list->head, LIST_POINTER_ERROR);
//	return list->head->Doctor;
//}
//
//void Doc_printList(const List* list, const char* delimiter)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//
//	if (list->head == EMPTY_LIST)
//	{
//		return;
//	}
//	
//	int DocNum = 1;
//	Node* temp = list->head;
//	Doc TempDoctor = temp->Doctor;
//	while (temp != LIST_END)
//	{
//
//		printf("%d.\tNAME: %s\t\tLICENSE: %s\t\tNUMBER OF PATIENTS: %d\n", \
//			DocNum, TempDoctor.Name, TempDoctor.nLicense, TempDoctor.nPatients);
//		DocNum++;
//		temp = temp->next;
//
//		if (!temp)
//			return;
//
//		TempDoctor = temp->Doctor;
//
//
//	}
//
//}
//
//void Doc_addToTail(List* list, Doc Doctor)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	//create new list node
//	Node* newTail = (Node*)calloc(1, sizeof(Node));
//	checkNullLogExit(newTail, BAD_ALLOC);
//	newTail->Doctor = Doctor;
//	//case this is very first list element added to empty list
//	if (list->tail == EMPTY_LIST)
//	{
//		list->head = list->tail = newTail;//update list
//		return;
//	}
//	else //list has at least one element
//	{
//		list->tail->next = newTail;
//		list->tail = newTail;//update list
//	}
//}
//
//int Doc_isEmptyList(const List* list)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	//double check for testing purposes
//	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST);
//}
//
//void Doc_destroyList(List* list)
//{
//	if (list == NULL)
//	{
//		return;
//	}
//
//	Node* toDestroy = list->head;
//	Node* next;
//	while (toDestroy != LIST_END)
//	{
//		next = toDestroy->next;
//		free(toDestroy);
//		toDestroy = next;
//	}
//
//	list->head = list->tail = EMPTY_LIST;//update list
//}
//
//void Doc_addToHead(List* list, Doc Doctor)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	//create new list node
//	Node* newHead = (Node*)calloc(1, sizeof(Node));
//	checkNullLogExit(newHead, BAD_ALLOC);
//	newHead->Doctor = Doctor;
//	//case this is very first list element added to empty list
//	if (list->head == EMPTY_LIST)
//	{
//		list->head = list->tail = newHead;//update list
//	}
//	else //list has at least one element
//	{
//		newHead->next = list->head;
//		list->head = newHead;//update list
//	}
//}
//
//Doc Doc_removeFromTail(List* list)
//{
//	checkNullLogExit(list, LIST_POINTER_ERROR);
//	checkNullLogExit(list->head, LIST_POINTER_ERROR);
//	//temp nodes to iterate over list and find the element previous to tail
//	Node* current = list->head;
//	Node* previous = NULL;
//	while (current->next != LIST_END)
//	{
//		previous = current;
//		current = current->next;
//	}
//
//	Doc toReturn = current->Doctor;//save return value
//	free(current);
//	list->tail = previous;//update list
//	//check if list has become empty after removal
//	if (list->tail == EMPTY_LIST)
//	{
//		list->head = EMPTY_LIST;//update list
//	}
//	else
//	{
//		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
//	}
//
//	return toReturn;
//}
