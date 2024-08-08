#define _CRT_SECURE_NO_WARNINGS
#include "removeVisit.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ID_SIZE 10

// Function to check if a string contains only digits
int is_all_digits(const char* number_str) {
	for (int i = 0; i < strlen(number_str); i++) {
		if (!isdigit(number_str[i]) && number_str[i] != '\n') {
			return 0;  // Return 0 if any character is not a digit
		}
	}
	return 1;  // Return 1 if all characters are digits
}

void removeVisit(pTree* patientsTree) {
	char id_temp[ID_SIZE] = { 0 };
	Patient* temp_pat = NULL;
	Node* temp_visit = NULL;
	Date temp_date;
	char day[ID_SIZE], month[ID_SIZE], year[ID_SIZE];
	int counter = 0, inVis = 0;

	// Get the patient ID from the user
	while (1) {
		printf("\nPlease enter the ID of the patient: ");
		scanf("%s", id_temp);

		if (validInput(id_temp, "id") == 1) {
			if ((temp_pat = searchPatient(patientsTree, id_temp)) == NULL) {
				printf("The ID isn't in the list of patients. Please try again.\n");
			}
			else {
				break;
			}
		}
		else {
			printf("INVALID ID INPUT. TRY AGAIN.\n");
		}
	}

	// Proceed by asking for the date of the visit
	temp_visit = temp_pat->Visits->sList.head;

	// Print all visits of the patient
	printf("The visits of %s:\n\n", temp_pat->Name);
	printStack(temp_pat->Visits);

	// Get the date from the user
	while (1) {
		printf("Please enter the date of the visit you want to remove:\n");

		// Day input
		while (1) {
			printf("Enter the day of the visit (1-31): ");
			fseek(stdin, 0, SEEK_END);
			fgets(day, ID_SIZE, stdin);
			if (atoi(day) < 1 || atoi(day) > 31 || is_all_digits(day) == 0)
			{
				printf("invalid day input\n");
			}
			else
			{
				break;
			}
		}

		// Month input
		while (1) {
			printf("Enter the month of the visit (1-12): ");
			fseek(stdin, 0, SEEK_END);
			fgets(month, ID_SIZE, stdin);
			if (atoi(month) < 1 || atoi(month) > 12 || is_all_digits(month) == 0)
			{
				printf("invalid month input\n");
			}
			else
			{
				break;
			}
		}

		// Year input
		while (1) {
			printf("Enter the year of the visit (1900-2024): ");
			fseek(stdin, 0, SEEK_END);
			fgets(year, ID_SIZE, stdin);
			if (atoi(year) < 1899 || atoi(year) > 2024 || is_all_digits(year) == 0)
			{
				printf("invalid year input\n");
			}
			else
			{
				break;
			}
		}
		//insert all the wanted info
		temp_date.Day = atoi(day);
		temp_date.Month = atoi(month);
		temp_date.Year = atoi(year);
		// Check if the date is found in the stack
		counter = 0;
		inVis = 0;
		temp_visit = temp_pat->Visits->sList.head;
		while (temp_visit != NULL) {
			if (temp_date.Day == temp_visit->Visit.tArrival.Day &&
				temp_date.Month == temp_visit->Visit.tArrival.Month &&
				temp_date.Year == temp_visit->Visit.tArrival.Year &&
				temp_visit->Visit.Duration != -1) {
				inVis++;
				break;
			}
			else {
				counter++;
				temp_visit = temp_visit->next;
			}
		}

		if (inVis != 0)
		{
			break;
		}
		else {
			char choice[ID_SIZE];
			printf("The date is invalid. If you want to insert a different date, press 1. If you want to return to the menu, press any other key: \n");
			fseek(stdin, 0, SEEK_END);
			fgets(choice, ID_SIZE, stdin);
			printf("\n");

			if (atoi(choice) != 1 || is_all_digits(choice) == 0)
			{
				return;
			}
		}
	}

	// Transfer all visits above the desired one to a temporary stack
	Stack temp_stack;
	initStack(&temp_stack);
	temp_visit = temp_pat->Visits->sList.head;
	for (int i = 0; i < counter; i++) {
		push(&temp_stack, temp_visit->Visit);
		if (temp_visit->next != NULL) {
			temp_visit = temp_visit->next;
		}
		else {
			break;
		}
	}

	// Remove the desired visit
	for (int i = 0; i < counter; i++) {
		if (temp_pat->Visits->sList.head->next != NULL) {
			temp_pat->Visits->sList.head = temp_pat->Visits->sList.head->next;
		}
	}
	pop(temp_pat->Visits);

	// Push back the visits that were temporarily removed
	while (!isEmptyStack(&temp_stack)) {
		push(temp_pat->Visits, pop(&temp_stack));
	}

	// Print the updated stack
	printf("\nupated visits:\n");
	printStack(temp_pat->Visits);
}
