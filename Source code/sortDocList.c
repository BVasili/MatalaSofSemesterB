#include"sortDocList.h"

Node* docsSortList(List* docsList, Doc Doctor)
{

	//create new list node
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (checkPointer(newNode, ALLOCATION_FAILED))
		return;

	newNode->Doctor = Doctor;
	newNode->next = NULL;
	if (newNode->Doctor.nPatients < docsList->head->Doctor.nPatients)
	{
		newNode->next = docsList->head;
		return newNode;
	}

	Node* temp1 = docsList->head;
	while ((temp1->next != NULL) && (temp1->next->Doctor.nPatients < newNode->Doctor.nPatients))
		temp1 = temp1->next;

	newNode->next = temp1->next;
	temp1->next = newNode;

	return docsList->head;
}