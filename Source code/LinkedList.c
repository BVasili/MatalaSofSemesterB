#define _CRT_SECURE_NO_WARNINGS
#include "Structure.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


//need some work 
//void printList(NodeDoc* head)
//{
//	while (head != NULL)
//	{
//		printf("%d-> ", head->data);
//		head = head->next;
//	}
//
//	printf("NULL\n");
//}


void freeList(NodeDoc* head)
{
	while (head != NULL)
	{
		NodeDoc* temp = head->next;
		free(head);
		head = temp;
	}
}


NodeDoc* createNode(Doc* doctor, NodeDoc* next)
{
	NodeDoc* newNode = calloc(1, sizeof(NodeDoc));
	if (!newNode) {
		printf("allocation failed");
		exit(1);
	}

	newNode->doctor.Name = (char*)malloc(sizeof(doctor->Name));
	if (!newNode->doctor.Name)
	{
		printf("allocation failed");
		exit(1);
	}
	
	if (newNode != NULL)
	{

		strcpy(newNode->doctor.Name, doctor->Name);
		strcpy(newNode->doctor.Name, doctor->nLicense);
		newNode->doctor.nPatients = doctor->nPatients;
		newNode->next = next;
	}

	return newNode;
}
NodeDoc* addFirst(Doc* doctor, NodeDoc* head)
{
	Node* newNode = createNode(doctor, head);

	if (newNode == NULL)
	{
		printf("Allocation error. not adding first\n");
		return head;
	}

	return newNode;
}
NodeDoc* addLast(Doc* doctor, NodeDoc* head)
{
	NodeDoc* newNode = createNode(doctor, NULL);
	if (newNode == NULL)
	{
		printf("Allocation error. not adding last\n");
		return head;
	}

	//case list is empty
	if (head == NULL) return newNode;

	NodeDoc* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

	return head;
}
