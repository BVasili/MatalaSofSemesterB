#define _CRT_SECURE_NO_WARNINGS
#include "removeVisit.h"
#include <ctype.h>

void removeVisit(pTree* patientsTree)
{
	/// getting the id input from the user
	char id_temp[ID_SIZE] = { 0 };
	Patient* temp_pat = NULL;
	Node* temp_visit = NULL;
	while (1)
	{
		printf("\nplease enter the id of the patient:");
		fseek(stdin, 0, SEEK_END);
		fgets(id_temp, ID_SIZE, stdin);
		printf("\n");
		if (validInput(id_temp, "id") == 1)
		{
			if (searchPatient(patientsTree, id_temp) == NULL)
			{
				printf("the ID isnt in the list of patients please try again\n");
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("INVALID ID INPUT TRY AGAIN\n");
		}
	}


	/// the id is in the tree so proceed by asking for the date of the visit #if the visit is active => cant remove it
	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
	temp_visit = temp_pat->Visits->sList.head;
	Date temp_date;
	int counter = 0, inVis = 0;


	/// print all the visits of the patient so the user could so choosing it becomes easier
	printf("the visits of %s\n\n", temp_pat->Name);
	printStack(temp_pat->Visits);

	/// getting the date from the user
	while (1)
	{
		printf("please enter the date of the visit you want to remove\n");

		///day input
		while (1)
		{
			//checking the day input
			printf("enter the day of the visit:\n");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &temp_date.Day);
			printf("\n");
			if ((temp_date.Day > 31 || temp_date.Day < 1) || (isalpha(temp_date.Day) != 0))
			{
				printf("invalid day input please try again\n ");
			}
			else
			{
				break;
			}
		}

		///month input
		while (1)
		{
			//checking the month input
			printf("enter the month of the visit:\n");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &temp_date.Month);
			printf("\n");
			if ((temp_date.Month > 12 || temp_date.Month < 1) || (isalpha(temp_date.Month) != 0))
			{
				printf("invalid month input please try again\n ");
			}
			else
			{
				break;
			}
		}

		///year input
		while (1)
		{
			//checking the year input
			printf("enter the year of the visit:\n");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%d", &temp_date.Year);
			printf("\n");
			if ((temp_date.Year > 2025 || temp_date.Year < 1900)/* || (isalpha(temp_date.Year) != 0)*/)
			{
				printf("invalid year input please try again\n ");
			}
			else
			{
				break;
			}
		}

		///check if the date is found in the stack
		counter = 0, inVis = 0;
		temp_visit = temp_pat->Visits->sList.head;
		while (temp_visit != NULL)
		{
			if ((temp_date.Day == temp_visit->Visit.tArrival.Day) && \
				(temp_date.Month == temp_visit->Visit.tArrival.Month) && \
				(temp_date.Year == temp_visit->Visit.tArrival.Year) && \
				(temp_visit->Visit.Duration != -1))
			{
				inVis++;
				break;
			}
			else
			{
				counter++;
				if (temp_visit->next != NULL)
				{
					temp_visit = temp_visit->next;
				}
				else
				{
					break;
				}
			}
		}

		///break if the date is found
		if (inVis != 0)
		{
			break;
		}

		///ask for the accurate date from the user
		/// add an opt. out because it may get into an infinite loop
		else
		{
			printf("the visit date ivalid, try a visit thats not active or a date thats in the visits list \n\n\n");
		}
	}

	///get all of the the above visits in a temp stack

	///transfer all of the visits that is above the wanted one
	Stack temp_stack;
	initStack(&temp_stack);
	temp_visit = &temp_pat->Visits->sList.head->Visit;
	for (int i = 0; i < counter; i++)
	{
		// Push the visit data onto the stack
		push(&temp_stack, temp_visit->Visit);

		// Move to the next node in the linked list
		if (temp_visit->next != NULL)
		{
			temp_visit = temp_visit->next;
		}
		else
		{
			break;
		}
	}


	///search the index to pop the stack
	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
	for (int i = 0; i < counter; i++)
	{
		if (temp_pat->Visits->sList.head->next != NULL)
			temp_pat->Visits->sList.head = temp_pat->Visits->sList.head->next;
	}
	///get rid of the wanted visit
	pop(temp_pat->Visits);

	///push back the visits that 
	temp_pat = &searchPatient(patientsTree, id_temp)->tpatient;
	for (int i = 0; i < counter; i++)
	{
		push(temp_pat->Visits, temp_stack.sList.head->Visit);
		temp_stack.sList.head = temp_stack.sList.head->next;
	}

	/// print the updated stack
	printStack(temp_pat->Visits);
}
