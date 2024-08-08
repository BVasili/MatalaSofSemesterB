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
        if (!isdigit(number_str[i])) {
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
            if (scanf("%d", &temp_date.Day) != 1 || temp_date.Day < 1 || temp_date.Day > 31) {
                printf("Invalid day input. Please try again.\n");
                while (getchar() != '\n');  // Clear the input buffer
            }
            else {
                break;
            }
        }

        // Month input
        while (1) {
            printf("Enter the month of the visit (1-12): ");
            if (scanf("%d", &temp_date.Month) != 1 || temp_date.Month < 1 || temp_date.Month > 12) {
                printf("Invalid month input. Please try again.\n");
                while (getchar() != '\n');  // Clear the input buffer
            }
            else {
                break;
            }
        }

        // Year input
        while (1) {
            printf("Enter the year of the visit (1900-2025): ");
            if (scanf("%d", &temp_date.Year) != 1 || temp_date.Year < 1900 || temp_date.Year > 2025) {
                printf("Invalid year input. Please try again.\n");
                while (getchar() != '\n');  // Clear the input buffer
            }
            else {
                break;
            }
        }

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

        if (inVis != 0) {
            break;
        }
        else {
            int choice = 0;
            printf("The date is invalid. If you want to insert a different date, press 1. If you want to return to the menu, press any other key: ");
            scanf("%d", &choice);
            getchar();  // Clear newline character from buffer

            if (choice != 1) {
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
    printStack(temp_pat->Visits);
}


//
//void removeVisit(pTree* patientsTree)
//{
//	/// getting the id input from the user
//	char id_temp[ID_SIZE] = { 0 };
//	Patient* temp_pat = NULL;
//	Node* temp_visit = NULL;
//	char date_in[5] = { 0 };
//	while (1)
//	{
//		printf("\nplease enter the id of the patient:");
//		fseek(stdin, 0, SEEK_END);
//		fgets(id_temp, ID_SIZE, stdin);
//		printf("\n");
//		if (validInput(id_temp, "id") == 1)
//		{
//			if (searchPatient(patientsTree, id_temp) == NULL)
//			{
//				printf("the ID isnt in the list of patients please try again\n");
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			printf("INVALID ID INPUT TRY AGAIN\n");
//		}
//	}
//
//
//	/// the id is in the tree so proceed by asking for the date of the visit #if the visit is active => cant remove it
//	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
//	temp_visit = temp_pat->Visits->sList.head;
//	Date temp_date;
//	int counter = 0, inVis = 0;
//
//
//	/// print all the visits of the patient so the user could so choosing it becomes easier
//	printf("the visits of %s\n\n", temp_pat->Name);
//	printStack(temp_pat->Visits);
//
//	/// getting the date from the user
//	while (1)
//	{
//		printf("please enter the date of the visit you want to remove\n");
//
//		///day input
//		while (1)
//		{
//			//checking the day input
//			printf("enter the day of the visit:\n");
//			fseek(stdin, 0, SEEK_END);
//			fgets(date_in,3,stdin);
//			printf("\n");
//			if (is_all_digits(date_in) != 0)
//			{
//				if (temp_date.Day > 31 || temp_date.Day < 1)
//				{
//					printf("invalid day input please try again\n ");
//				}
//			}
//
//			else
//			{
//				break;
//			}
//		}
//
//		///month input
//		while (1)
//		{
//			//checking the month input
//			printf("enter the month of the visit:\n");
//			fseek(stdin, 0, SEEK_END);
//			scanf_s("%d", &temp_date.Month);
//			printf("\n");
//			if ((temp_date.Month > 12 || temp_date.Month < 1) || (is_all_digits(temp_date.Month) != 0))
//			{
//				printf("invalid month input please try again\n ");
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		///year input
//		while (1)
//		{
//			//checking the year input
//			printf("enter the year of the visit:\n");
//			fseek(stdin, 0, SEEK_END);
//			scanf_s("%d", &temp_date.Year);
//			printf("\n");
//			if ((temp_date.Year > 2025 || temp_date.Year < 1900) || (is_all_digits(temp_date.Year) == 0))
//			{
//				printf("invalid year input please try again\n ");
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		///check if the date is found in the stack
//		counter = 0, inVis = 0;
//		temp_visit = temp_pat->Visits->sList.head;
//		while (temp_visit != NULL)
//		{
//			if ((temp_date.Day == temp_visit->Visit.tArrival.Day) && \
//				(temp_date.Month == temp_visit->Visit.tArrival.Month) && \
//				(temp_date.Year == temp_visit->Visit.tArrival.Year) && \
//				(temp_visit->Visit.Duration != -1))
//			{
//				inVis++;
//				break;
//			}
//			else
//			{
//				counter++;
//				if (temp_visit->next != NULL)
//				{
//					temp_visit = temp_visit->next;
//				}
//				else
//				{
//					int choice = 0;
//					printf("the date is invalid ,if you want to insert a different date press 1, if you want to return to menu press anything\n");
//					while (1)
//					{
//						fseek(stdin, 0, SEEK_END);
//						scanf("%d", &choice);
//						printf("\n");
//						if (choice == 1)
//						{
//							break;
//						}
//						else
//						{
//							return;
//						}
//
//					}
//					break;
//				}
//			}
//		}
//
//		///break if the date is found
//		if (inVis != 0)
//		{
//			break;
//		}
//
//		///ask for the accurate date from the user
//		/// add an opt. out because it may get into an infinite loop
//		else
//		{
//			printf("try a visit thats not active or a date thats in the visits list \n\n\n");
//		}
//	}
//
//	///get all of the the above visits in a temp stack
//
//	///transfer all of the visits that is above the wanted one
//	Stack temp_stack;
//	initStack(&temp_stack);
//	temp_visit = &temp_pat->Visits->sList.head->Visit;
//	for (int i = 0; i < counter; i++)
//	{
//		// Push the visit data onto the stack
//		push(&temp_stack, temp_visit->Visit);
//
//		// Move to the next node in the linked list
//		if (temp_visit->next != NULL)
//		{
//			temp_visit = temp_visit->next;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//
//	///search the index to pop the stack
//	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
//	for (int i = 0; i < counter; i++)
//	{
//		if (temp_pat->Visits->sList.head->next != NULL)
//			temp_pat->Visits->sList.head = temp_pat->Visits->sList.head->next;
//	}
//	///get rid of the wanted visit
//	pop(temp_pat->Visits);
//
//	///push back the visits that 
//	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
//	for (int i = 0; i < counter; i++)
//	{
//		push(temp_pat->Visits, temp_stack.sList.head->Visit);
//		temp_stack.sList.head = temp_stack.sList.head->next;
//	}
//
//	/// print the updated stack
//	printStack(temp_pat->Visits);
//}
//
//
//int is_all_digits(char number)
//{
//	char number_str[100];
//
//	sprintf(number_str, "%s", number);
//
//	for (int i = 0; i < strlen(number_str); i++) {
//		if (!isdigit(number_str[i])) {
//			return 0;  // Return 0 if any character is not a digit
//		}
//	}
//
//	return 1;  // Return 1 if all characters are digits
//}