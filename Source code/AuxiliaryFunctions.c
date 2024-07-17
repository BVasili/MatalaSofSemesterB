#include "AuxiliaryFunctions.h"
#include "CheckDynamicAllocation.h"
#include "Structure.h"
#include "Stack.h"
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

pInTree* searchPatient(pTree* tree, char* ID)
{
	return searchPatientInTree(tree->root, ID);
}

void displayError(int error)
{
	if (ALLOCATION_FAILED)
		printf("Error: Cannot allocate memory.\n");

	if (CANNOT_OPEN_FILE)
		printf("Error: Cannot open the desired file.\n");

	return;
}

int printMenu(void)
{
	int action = -1;
	while (action < 0 || action>12)
	{
		printf("MENU:\n\n\
  #   0. Exit Program\n\n\
  #   1. Admit Patient\n\n\
  #   2. Check fot patient's allergies\n\n\
  #   3. Dispaly all patients\n\n\
  #   4. Dispaly all patient's admission\n\n\
  #   5. Dispaly all patients in line\n\n\
  #   6. Advance patient in line\n\n\
  #   7. Display list of all doctors\n\n\
  #   8. Display all patients assigned to a doctor\n\n\
  #   9. Discharge patient\n\n\
  #   10. Remove visit\n\n\
  #   11. Remove patient\n\n\
  #   12. Close the hospital\n");
		printf("\n\nplease enter a the number of the wanted action:\t");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &action);
		if (action < 0 || action>12 || isdigit(action) != 0)
		{
			printf("\n\nERROR:\tplease enter a number between 0 and 12 include\n\n");
		}
	}

	return action;
}

pTree* loadPatients()
{
	//Declaring variables for function
	char Name[NAME_SIZE] = { 0 }, Doctor_Name[NAME_SIZE] = { 0 }, ID[ID_SIZE] = { 0 };
	char Allergies_String[LINE_SIZE], Line[LINE_SIZE] = { 0 }, Summary[SUMAMRY_SIZE] = { 0 };
	char Allergies[ALLERGY_SIZE][ALLERGY_MAX_NAME_SIZE] = { 0 };

	char Day[3] = { 0 }, Month[3] = { 0 }, Year[5] = { 0 };
	char Hour[3] = { 0 }, Minute[3] = { 0 };
	long FileSize = 0, remainingBytes = 0, currentPosition = 0;

	char* NamePtr = NULL;
	Patient PatientTemp = { 0 };
	Visit PatientsTempVisit = { 0 };
	pTree* root = malloc(sizeof(pTree)); //change and free if no pateints in txt
	Patient_initializeBST(root);

	FILE* Ptr2File = fopen("Patients.txt", "r"); //add variable to function
	if (!Ptr2File)
	{
		printf("Error opening Ptr2File: %s\n", "Patients.txt");
		return;
	}

	fseek(Ptr2File, 0, SEEK_END);
	FileSize = ftell(Ptr2File);
	fseek(Ptr2File, 0, SEEK_SET);

	fseek(Ptr2File, 47, SEEK_CUR); // Skips first line in txt file

	currentPosition = ftell(Ptr2File);
	remainingBytes = FileSize - currentPosition;

	while (remainingBytes > 3)

		while (remainingBytes > 3)
		{

			// Read Patients NAME,ID,ALLERGIES.
			{
				fgets(Line, sizeof(Line), Ptr2File);
#ifdef DEBUG

				printf("%s\n", Line);
#endif // DEBUG

				//Copying line that has NAME,ID,ALLERGIES
				sscanf(Line, "%*d.%[^;];%[^;];%s", Name, ID, Allergies_String);
				sscanf(Allergies_String, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^ ] ", Allergies[0], Allergies[1], Allergies[2], Allergies[3], Allergies[4], Allergies[5], Allergies[6], Allergies[7]);

				strcpy(PatientTemp.ID, ID); //copying Patients ID to PatientTemp

				//checking for allergies and using bitwise to add them.
				for (int i = 0; i < 8; i++)
				{
					if (strcmp(Allergies[i], "none") == 0)
						PatientTemp.Allergies |= NONE;
					if (strcmp(Allergies[i], "Penicillin") == 0)
						PatientTemp.Allergies |= PENICILLIN;
					if (strcmp(Allergies[i], "Sulfa") == 0)
						PatientTemp.Allergies |= SULFA;
					if (strcmp(Allergies[i], "Opioids") == 0)
						PatientTemp.Allergies |= OPIOIDS;
					if (strcmp(Allergies[i], "Anesthetics") == 0)
						PatientTemp.Allergies |= ANESTHETICS;
					if (strcmp(Allergies[i], "Eggs") == 0)
						PatientTemp.Allergies |= EGGS;
					if (strcmp(Allergies[i], "Latex") == 0)
						PatientTemp.Allergies |= LATEX;
					if (strcmp(Allergies[i], "Preservatives") == 0)
						PatientTemp.Allergies |= PRESERVATIVES;
				}

				//Reset allergies for the next patient
				for (int i = 0; i < 8; i++)
					strcpy(&Allergies[i], "\0");

				//Allocating memory for name and visit stack
				PatientTemp.Name = malloc(sizeof(Name));//need to fix this allocation because it uses the size of the whole string
				CheckDynamicAllocation(PatientTemp.Name);
				strcpy(PatientTemp.Name, Name);

				PatientTemp.Visits = malloc(sizeof(Stack));//check for fucks
				CheckDynamicAllocation(PatientTemp.Visits);

				//initiating stack
				Visit_initStack(PatientTemp.Visits);

#ifdef DEBUG
				printf("%s %s \n", PatientTemp.Name, PatientTemp.ID);
				printf(" Allergies: ");
				if (PatientTemp.Allergies & PENICILLIN) printf("Penicillin ");
				if (PatientTemp.Allergies & SULFA) printf("Sulfa ");
				if (PatientTemp.Allergies & OPIOIDS) printf("Opioids ");
				if (PatientTemp.Allergies & ANESTHETICS) printf("Anesthetics ");
				if (PatientTemp.Allergies & EGGS) printf("Eggs ");
				if (PatientTemp.Allergies & LATEX) printf("Latex ");
				if (PatientTemp.Allergies & PRESERVATIVES) printf("Preservatives ");
				printf("\n");
#endif // DEBUG

			}

			//Skips to the right line to read visits
			fgets(Line, sizeof(Line), Ptr2File);
			fgets(Line, sizeof(Line), Ptr2File);

			// Reads Patients Visits
			do
			{
				//increase nVisits every time there is a documented visit
				PatientTemp.nVisits++;

				sscanf(Line, "Arrival:%[^/]/%[^/]/%[^ ] %[^:]:%[^\n]", Day, Month, Year, Hour, Minute);

				//Converting from string to int and putting the variables in their right place
				PatientsTempVisit.tArrival.Day = atoi(Day);
				PatientsTempVisit.tArrival.Month = atoi(Month);
				PatientsTempVisit.tArrival.Year = atoi(Year);
				PatientsTempVisit.tArrival.Hour = atoi(Hour);
				PatientsTempVisit.tArrival.Min = atoi(Minute);

				//Reseting the temporary variables.
				strcpy(Day, "\0");
				strcpy(Month, "\0");
				strcpy(Year, "\0");
				strcpy(Hour, "\0");
				strcpy(Minute, "\0");
#ifdef DEBUG

				printf("%d/%d/%d %d:%d\n", PatientsTempVisit.tArrival.Day, PatientsTempVisit.tArrival.Month, PatientsTempVisit.tArrival.Year, PatientsTempVisit.tArrival.Hour, PatientsTempVisit.tArrival.Min);

#endif // DEBUG

				fgets(Line, sizeof(Line), Ptr2File);
				sscanf(Line, "Dismissed:%[^/]/%[^/]/%[^ ] %[^:]:%[^\n]", Day, Month, Year, Hour, Minute);

				//Converting from string to int and putting the variables in their right place
				PatientsTempVisit.tDismissed.Day = atoi(Day);
				PatientsTempVisit.tDismissed.Month = atoi(Month);
				PatientsTempVisit.tDismissed.Year = atoi(Year);
				PatientsTempVisit.tDismissed.Hour = atoi(Hour);
				PatientsTempVisit.tDismissed.Min = atoi(Minute);
				//Reseting the temporary variables.
				strcpy(Day, "\0");
				strcpy(Month, "\0");
				strcpy(Year, "\0");
				strcpy(Hour, "\0");
				strcpy(Minute, "\0");
#ifdef DEBUG

				printf("%d/%d/%d %d:%d\n", PatientsTempVisit.tDismissed.Day, PatientsTempVisit.tDismissed.Month, PatientsTempVisit.tDismissed.Year, PatientsTempVisit.tDismissed.Hour, PatientsTempVisit.tDismissed.Min);

#endif // DEBUG

				//Getting Duration of visit
				fgets(Line, sizeof(Line), Ptr2File);
				sscanf(Line, "Duration:%[^:]:%[^\n]", Hour, Minute);

				//(for debugging) Converting it to hour and minutes
				PatientsTempVisit.Duration = 60 * atoi(Hour) + atoi(Minute);
				strcpy(Hour, "\0");
				strcpy(Minute, "\0");
#ifdef DEBUG

				int Duration_hours = (int)(PatientsTempVisit.Duration) - ((int)(PatientsTempVisit.Duration) % 60);
				printf("Durtaion: %d:%d\n", Duration_hours / 60, (int)(PatientsTempVisit.Duration) % 60);
				Duration_hours = 0;
#endif // DEBUG


				//Getting doctors name from patient.txt
				fgets(Line, sizeof(Line), Ptr2File);
				sscanf(Line, "Doctor:%[^\n]", Doctor_Name);
#ifdef DEBUG

				printf("%s\n", Doctor_Name);

#endif // DEBUG

				//Alloctaing memory for Doc struc and Doc.name
				PatientsTempVisit.Doctor = malloc(sizeof(Doc));
				CheckDynamicAllocation(PatientsTempVisit.Doctor);
				PatientsTempVisit.Doctor->Name = malloc(sizeof(Doctor_Name));
				CheckDynamicAllocation(PatientsTempVisit.Doctor->Name);

				//Copying doctors name into PatientsTempVisit
				strcpy(PatientsTempVisit.Doctor->Name, Doctor_Name);

				//getting summary from given visit
				fgets(Line, sizeof(Line), Ptr2File);
				sscanf(Line, "Summary:%[^\n]", Summary);
#ifdef DEBUG

				printf("%s\n", Summary);

#endif // DEBUG

				//allocating memory for summary and copying information to it
				PatientsTempVisit.vSummary = malloc(sizeof(Summary));
				CheckDynamicAllocation(PatientsTempVisit.vSummary);
				strcpy(PatientsTempVisit.vSummary, Summary);
				strcpy(Summary, "\0");

				//pushing each visit into stack
				Visit_push(PatientTemp.Visits, PatientsTempVisit);

				//reseting PatientsTempVisit for the next visit
				PatientsTempVisit.Doctor = NULL;
				PatientsTempVisit.Duration = 0;
				PatientsTempVisit.vSummary = NULL;
				PatientsTempVisit.tDismissed.Day = 0;
				PatientsTempVisit.tDismissed.Month = 0;
				PatientsTempVisit.tDismissed.Year = 0;
				PatientsTempVisit.tDismissed.Hour = 0;
				PatientsTempVisit.tDismissed.Min = 0;
				PatientsTempVisit.tArrival.Day = 0;
				PatientsTempVisit.tArrival.Month = 0;
				PatientsTempVisit.tArrival.Year = 0;
				PatientsTempVisit.tArrival.Hour = 0;
				PatientsTempVisit.tArrival.Min = 0;

				fgets(Line, sizeof(Line), Ptr2File);

#ifdef DEBUG
				printf("%s\n", Line);

#endif // DEBUG

				//checks if there are more visits in patients file
				if (strcmp(Line, "\n") != 0)
					break;

				fgets(Line, sizeof(Line), Ptr2File);

			} while (1);

			//inserting patient into bst with all the needed information
			Patient_insertBST(root, PatientTemp);

			//reseting PatientTemp for the next patient in the txt file
			PatientTemp.Name = NULL;
			PatientTemp.nVisits = 0;
			PatientTemp.Visits = NULL;
			PatientTemp.Allergies = 0x0;
			strcpy(PatientTemp.ID, "\0");

			//finds remaining bytes from end of file
			currentPosition = ftell(Ptr2File);
			remainingBytes = FileSize - currentPosition;
		}
	fclose(Ptr2File);
	return root;
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
	PrintDocList(head);
	return head;
}