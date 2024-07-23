#define _CRT_SECURE_NO_WARNINGS
#include "C:\Users\shale\source\repos\hagasha2\Structure.h"
#include"C:\Users\shale\source\repos\hagasha2\Source code\loadPatients.h"
#include <stdio.h>
#include<string.h>
#define LICENSE_SIZE 7

typedef struct NodeDoc
{
	Doc doctor;
	struct NodeDoc* next;
}NodeDoc;

typedef struct Doc
{
	char* Name;
	char nLicense[ID_SIZE];
	int nPatients;
} Doc;

void goToFunc(int choice, NodeDoc* head);
void PrintDocList(NodeDoc* head);
void freeList(NodeDoc* head);
NodeDoc* loadDoctors();
NodeDoc* removeNode(NodeDoc* head, NodeDoc* node);
NodeDoc* assignDoc2Case(NodeDoc* head);
NodeDoc* createNode(Doc* doctor, NodeDoc* next);
NodeDoc* addFirst(Doc* doctor, NodeDoc* head);
NodeDoc* addSorted(Doc* doctor, NodeDoc* head);


void goToFunc(int choice, NodeDoc* head)
{
	switch (choice) {
	case 0:
		printf("You chose option to exit the program\n\n");
		// Your code for option 0 goes here
		break;
	case 1:
		printf("You chose option to admit a patient\n\n");
		// Your code for option 1 goes here
		break;
	case 2:
		printf("You chose to check for patients allergies \n\n");
		// Your code for option 2 goes here
		break;
	case 3:
		printf("You chose to display all patients\n\n");
		// Your code for option 3 goes here
		break;
	case 4:
		printf("You chose to display all patient's admissions\n\n");
		// Your code for option 4 goes here
		break;
	case 5:
		printf("You chose to display all patients in line\n\n");
		// Your code for option 5 goes here
		break;
	case 6:
		printf("You chose to advance patient in line\n\n");
		// Your code for option 6 goes here
		break;
	case 7:
		printf("You chose to display list of all doctors\n\n");
		PrintDocList(head);
		// Your code for option 7 goes here
		break;
	case 8:
		printf("You chose to dispaly all patients assigned to a doctor\n\n");
		// Your code for option 8 goes here
		break;
	case 9:
		printf("You chose to discharge patient\n\n");
		// Your code for option 9 goes here
		break;
	case 10:
		printf("You chose to remove a visit\n\n");
		// Your code for option 10 goes here
		break;
	case 11:
		printf("You chose to remove patient\n\n");
		// Your code for option 11 goes here
		break;
	case 12:
		printf("You chose to close the hospital\n\n");
		// Your code for option 12 goes here
		break;
	}
}

void PrintDocList(NodeDoc* head)
{
	int DocNum = 0;
	while (head != NULL)
	{
		DocNum++;
		printf("%d.\tNAME: %s\t\tNUMBER OF PATIENTS: %d\n", \
			DocNum, head->doctor.Name, head->doctor.nPatients);
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

NodeDoc* loadDoctors() {
	char DocName[NAME_SIZE] = { 0 }, nLicense[LICENSE_SIZE] = { 0 }, nPatientsRead[3] = { 0 }, Line[LINE_SIZE] = { 0 };
	int nPatients = 0, firstRead = 0;

	FILE* DocsFile = fopen("Doctors.txt", "r");
	if (!DocsFile) {
		printf("FILE DIDN'T OPEN\n");
		exit(1);
	}

	fseek(DocsFile, 98, SEEK_CUR); // Adjust to the first letter

	NodeDoc* head = NULL;

	while (fgets(Line, sizeof(Line), DocsFile)) {
		if (sscanf(Line, "%[^;]; %[^;]; %[^;]", DocName, nLicense, nPatientsRead) != 3) {
			printf("Error reading line: %s\n", Line);
			continue;
		}

		nPatients = atoi(nPatientsRead);

		Doc temp;
		temp.Name = (char*)malloc(strlen(DocName) + 1);
		if (!temp.Name) {
			printf("allocation failed\n");
			exit(1);
		}

		strcpy(temp.Name, DocName);
		strcpy(temp.nLicense, nLicense);
		temp.nPatients = nPatients;

		if (firstRead) {
			head = addSorted(&temp, head);
		}
		else {
			head = addFirst(&temp, head);
			firstRead = 1;
		}

		// Clear the temporary line and name buffers
		Line[0] = '\0';
	}

	fclose(DocsFile);
	return head;
}

NodeDoc* insertSorted(NodeDoc* head, NodeDoc* node) {
	if (head == NULL || head->doctor.nPatients > node->doctor.nPatients) {
		node->next = head;
		return node;
	}

	NodeDoc* current = head;
	while (current->next != NULL && current->next->doctor.nPatients <= node->doctor.nPatients) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;

	return head;
}

NodeDoc* removeNode(NodeDoc* head, NodeDoc* node) {
	if (head == NULL) {
		return NULL;
	}

	if (head == node) {
		return head->next;
	}

	NodeDoc* current = head;
	while (current->next != NULL && current->next != node) {
		current = current->next;
	}

	if (current->next == node) {
		current->next = node->next;
	}

	return head;
}

NodeDoc* assignDoc2Case(NodeDoc* head) {
	NodeDoc* temp = head;
	NodeDoc* selectedDoctor = NULL;

	if (temp == NULL) {
		printf("List of doctors is empty\n");
		return head;
	}

	if (head->doctor.nPatients == 4)
	{
		printf("\t###THERE ARE NO AVAILABLE DOCTORS###\n");
		return head;
	}

	// Find the first doctor with fewer than 4 patients
	while (temp != NULL) {
		if (temp->doctor.nPatients < 4) {
			selectedDoctor = temp;
			break;
		}
		temp = temp->next;
	}

	if (selectedDoctor == NULL) {
		printf("No available doctors.\n");
		return head;
	}

	// Print available doctors and their patient count
	temp = head;
	while (temp != NULL) {
		if (temp->doctor.nPatients < 4) {
			printf("NAME: %s is available and has %d active patients\n", temp->doctor.Name, temp->doctor.nPatients);
		}
		temp = temp->next;
	}
	printf("\n\n");
	// Increment the patient count of the selected doctor
	selectedDoctor->doctor.nPatients++;

	// Remove the selected doctor from its current position
	head = removeNode(head, selectedDoctor);

	// Re-insert the doctor into the list in sorted order
	head = insertSorted(head, selectedDoctor);


	return head;
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