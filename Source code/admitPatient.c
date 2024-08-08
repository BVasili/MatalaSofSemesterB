#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadPatients.h"
#include <math.h>
#include <ctype.h>
#include <time.h>
#include "Stack.h"
#include"admitPatient.h"
#include "removeVisit.h"


int validInput(char* str, char* action)//just for now later will be in a file
{
	int counter = 0;
	//check id input
	if (strcmp("id", action) == 0)
	{
		if (strlen(str) != ID_SIZE - 1)
		{
			return 0;
		}
		for (int i = 0; i < ID_SIZE - 1; i++)
		{
			if (isdigit(str[i]) == 0)
				counter++;
		}
		if (counter != 0)
			return 0;

		return 1;
	}

	//check name input
	if (strcmp("name", action) == 0)
	{
		int i = 0;
		while (str[i] != '\0')
			if ((isalpha(str[i]) == 0) && (str[i] != ' '))
				return 0;
			else
				i++;

		return 1;
	}
}

void insertNewPatientInfo(char* id_str, List* doctors, pLine* PatientsLine, pTree* PatientsTree)
{
	//the id value has already been inserted 

	//get the name from the user
	char Name[NAME_SIZE] = { 0 };
	while (1)
	{
		printf("please enter the patient's name:\t ");
		fseek(stdin, 0, SEEK_END);
		fgets(Name, NAME_SIZE, stdin);
		printf("\n");
		if (validInput(Name, "name") == 1)
			break;
		else
			printf("INVALID NAME PLEASE ENTER A NAME WITHOUT NUMBER OR SPECIAL LETTERS\n");
	}

	//get the allergies
	char* Allergies_String[] = { "Penicillin" , "Sulfa" , "Opioids", "Anesthetics","Eggs","Latex","Preservatives" };
	char allergyValue[ID_SIZE] = { 0 };
	char binVal = NULL;
	//this while loop gets the binary value of the patient's allergies
	while (1)
	{
		int i = 1;
		printf("if the patient is allergic to something please enter 1, if not enter 2:\t");
		fseek(stdin, 0, SEEK_END);
		fgets(allergyValue, ID_SIZE, stdin);
		printf("\n\n");
		if ((atoi(allergyValue)) == 1 && (is_all_digits(allergyValue) == 1))
		{
			while (1)
			{
				printf("is the patient allergic to %s?\n press 1 for yes, and 2 for no:\t", Allergies_String[i - 1]);
				fseek(stdin, 0, SEEK_END);
				fgets(allergyValue, ID_SIZE, stdin);
				printf("\n");
				if (atoi(allergyValue) == 1 && (is_all_digits(allergyValue) == 1))
				{
					switch (i)
					{
					case 1:
						binVal |= PENICILLIN;
						break;
					case 2:
						binVal |= SULFA;
						break;
					case 3:
						binVal |= OPIOIDS;
						break;
					case 4:
						binVal |= ANESTHETICS;
						break;
					case 5:
						binVal |= EGGS;
						break;
					case 6:
						binVal |= LATEX;
						break;
					case 7:
						binVal |= PRESERVATIVES;
						break;
					}
					i++;
				}
				if (atoi(allergyValue) == 2 && (is_all_digits(allergyValue) == 1))
					i++;
				if ((atoi(allergyValue) != 2) && (atoi(allergyValue) != 1) || (is_all_digits(allergyValue) == 0))
					printf("invalid input try again!\n");
				if (i == 8)
					break;
			}
		}
		if (atoi(allergyValue) == 2 && i == 1 && is_all_digits(allergyValue) == 1)
		{
			binVal |= NONE;
			break;
		}
		if (i == 8)
		{
			break;
		}
		if (atoi(allergyValue) != 2 || atoi(allergyValue) != 1 || is_all_digits(allergyValue) == 0)
			printf("invalid allergies input please enter  1 or 2\n");
	}


	//fill the visit field 
	//get the tArrival with the current time with time.h library
	Visit temp;
	time_t t = time(NULL);
	struct tm date = *localtime(&t);
	temp.tArrival.Year = date.tm_year + 1900;
	temp.tArrival.Month = date.tm_mon + 1;
	temp.tArrival.Day = date.tm_mday;
	temp.tArrival.Hour = date.tm_hour;
	temp.tArrival.Min = date.tm_min;

	//assign doc 2 case
	temp.Doctor = &assignDoc2Case(doctors)->Doctor;//if we got here theres an available doctor

	// get the vsummary
	printf("please enter the summary of the visit:\t");
	fseek(stdin, 0, SEEK_END);
	char summary[LINE_SIZE];
	scanf("%[^\n]", summary);
	printf("\n");

	temp.vSummary = (char*)malloc(sizeof(strlen(summary)) + 1);
	if (!temp.vSummary)
	{
		displayError(ALLOCATION_FAILED);
		return;

	}

	strcpy(temp.vSummary, summary);
	// insert all the valid info to patient type parameter and add the patient to the tree
	Patient new_patient = { 0 };

	//allocate memory for the name
	new_patient.Name = (char*)malloc(sizeof(strlen(Name) + 1));
	if (!new_patient.Name)
	{
		displayError(ALLOCATION_FAILED);
		return;

	}

	//inserting the info to a temp element
	strcpy(new_patient.Name, Name);
	strcpy(new_patient.ID, id_str);
	new_patient.Allergies = binVal;
	new_patient.nVisits = 1;
	new_patient.Visits = malloc(sizeof(Stack));
	if (!new_patient.Visits)
	{
		displayError(ALLOCATION_FAILED);
		return;
	}

	initStack(new_patient.Visits);
	push(new_patient.Visits, temp);

	//initialize all the other fields that hasnt been inserted
	new_patient.Visits->sList.head->Visit.Duration = -1;
	new_patient.Visits->sList.head->Visit.tDismissed.Day = -1;
	new_patient.Visits->sList.head->Visit.tDismissed.Month = -1;
	new_patient.Visits->sList.head->Visit.tDismissed.Year = -1;
	new_patient.Visits->sList.head->Visit.tDismissed.Hour = -1;
	new_patient.Visits->sList.head->Visit.tDismissed.Min = -1;
	new_patient.Visits->sList.head->Visit.Duration = -1;
	//add the new patient to the tree
	insertPTree(PatientsTree, new_patient);

	/*printPTree(PatientsTree);*/

	//add the new patient to the line 
	enLine(PatientsLine, id_str, PatientsTree);

	//print line
	printLineWithVisit(PatientsLine);
	return;
}

void insertExisPatient(char* id_str, List* doctors, pLine* PatientsLine, pTree* PatientsTree)//need to check if working
{
	//get current time 
	Visit temp;
	time_t t = time(NULL);
	struct tm date = *localtime(&t);
	temp.tArrival.Year = date.tm_year + 1900;
	temp.tArrival.Month = date.tm_mon + 1;
	temp.tArrival.Day = date.tm_mday;
	temp.tArrival.Hour = date.tm_hour;
	temp.tArrival.Min = date.tm_min;
	//initialize fields
	temp.tDismissed.Day = -1;
	temp.tDismissed.Month = -1;
	temp.tDismissed.Year = -1;
	temp.tDismissed.Hour = -1;
	temp.tDismissed.Min = -1;
	temp.Duration = -1;


	//assign doc 2 case
	temp.Doctor = &assignDoc2Case(doctors)->Doctor;

	//sum the visit
	printf("please enter the summary of the visit:\t");
	fseek(stdin, 0, SEEK_END);
	char summary[LINE_SIZE];
	scanf("%[^\n]", summary);
	printf("\n");

	temp.vSummary = (char*)malloc(sizeof(strlen(summary)) + 1);
	if (!temp.vSummary)
	{
		displayError(ALLOCATION_FAILED);
		return;

	}

	strcpy(temp.vSummary, summary);

	//insert new visit to patient 
	Patient* ptr_patient = &searchPatient(PatientsTree, id_str)->tpatient;
	ptr_patient->nVisits++;

	//inserting visit to patients stack 
	push(ptr_patient->Visits, temp);

	//update the line
	enLine(PatientsLine, id_str, PatientsTree);

	return;
}

void admitPatient(List* doctors, pLine* PatientsLine, pTree* PatientsTree)
{
	//first check capacity #notice that THE LIST OF DOCTORS SHOULD ALWAYS BE SORTED
	if (doctors->head->Doctor.nPatients >= 4)
	{
		printf("WE ARE AT FULL CAPACITY AT THE MOMENT\n\n");
		return;
	}

	//insert id from the user
	char id_str[ID_SIZE];
	while (1)
	{
		printf("please enter an id number:\t");
		fseek(stdin, 0, SEEK_END);
		fgets(id_str, ID_SIZE + 5, stdin);
		printf("\n");

		//check if the number is valid
		if (validInput(id_str, "id") == 1)
		{
			//check if the patient is already registered

			if (find(PatientsTree, id_str) == 1)//member is already registered
			{
				//check if he is already in line
				if (searchPatientInLine(PatientsLine, id_str) != NULL)
				{
					printf("%s is already in line\n", searchPatientInLine(PatientsLine, id_str)->lpatient->Name);
					return;
				}
				else
				{
					//insert existing patient's info with a destined func
					insertExisPatient(id_str, doctors, PatientsLine, PatientsTree);

					return;
				}
			}
			else
			{
				//insert new patient's info with a destined func
				insertNewPatientInfo(id_str, doctors, PatientsLine, PatientsTree);
				return;
			}
		}
		else
		{
			printf("INVALID ID NUMBER PLEASE TRY AGAIN\n");
		}
	}
}