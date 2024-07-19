#define _CRT_SECURE_NO_WARNINGS
#include "Structure.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


void PrintDocList(NodeDoc* head)
{
	int DocNum = 0;
	while (head != NULL)
	{
		DocNum++;
		printf("%d.\tNAME: %s\t\tLICENSE: %s\t\tNUMBER OF PATIENTS: %d\n", \
			DocNum, head->doctor.Name, head->doctor.nLicense, head->doctor.nPatients);
		head = head->next;
	}

	printf("\n\n\n");
}


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
	// Allocate memory for the new node
	NodeDoc* newNode = (NodeDoc*)malloc(sizeof(NodeDoc));
	CheckDynamicAllocation(newNode);

	// Allocate memory for the doctor's name
	newNode->doctor.Name = (char*)malloc(strlen(doctor->Name) + 1);
	CheckDynamicAllocation(newNode->doctor.Name);


	// Copy the doctor's information
	strcpy(newNode->doctor.Name, doctor->Name);
	strcpy(newNode->doctor.nLicense, doctor->nLicense);
	newNode->doctor.nPatients = doctor->nPatients;
	newNode->next = next;

	return newNode;
}
NodeDoc* addFirst(Doc* doctor, NodeDoc* head)
{
	NodeDoc* newNode = createNode(doctor, NULL);

	if (newNode == NULL)
	{
		printf("Allocation error. not adding first\n");
		return head;
	}

	return newNode;
}
NodeDoc* addSorted(Doc* doctor, NodeDoc* head)
{
	NodeDoc* newNode = createNode(doctor, NULL);
	CheckDynamicAllocation(newNode);

	if (head == NULL) return newNode;

	if (newNode->doctor.nPatients < head->doctor.nPatients)
	{
		newNode->next = head;
		return newNode;
	}

	NodeDoc* temp1 = head;
	while ((temp1->next != NULL) && (temp1->next->doctor.nPatients < newNode->doctor.nPatients))
		temp1 = temp1->next;

	newNode->next = temp1->next;
	temp1->next = newNode;

	return head;
}