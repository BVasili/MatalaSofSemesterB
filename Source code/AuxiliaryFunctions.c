#include "AuxiliaryFunctions.h"
#include "Structure.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEBUG

int printMenu(void)
{
	int action = -1;
	/*while (action < 0 && action>12)*/
	/*{*/
	printf("\tMENU:\n\n\
      0. Exit Program\n\n\
      1. Admit Patient\n\n\
      2. Check fot patient's allergies\n\n\
      3. Dispaly all patients\n\n\
      4. Dispaly all patient's admission\n\n\
      5. Dispaly all patients in line\n\n\
      6. Advance patient in line\n\n\
      7. Display list of all doctors\n\n\
      8. Display all patients assigned to a doctor\n\n\
      9. Discharge patient\n\n\
      10. Remove visit\n\n\
      11. Remove patient\n\n\
      12. Close the hospital\n");
	/*}*/

	return action;
}

void loadPatients()
{
	char Name[20] = { 0 };
	char* NamePtr = NULL;
	char ID[ID_SIZE] = { 0 };
	char Allergies_String[70];
	char Allergies[8][15] = { 0 };
	char Doctor_Name[20] = { 0 };
	char Line[50] = { 0 };
	char Summary[50] = { 0 };
	char Day[4] = { 0 }, Month[4] = { 0 }, Year[5] = { 0 }, Hour[4] = { 0 }, Minute[4] = { 0 };
	int nVisit = 0;
	float Duration = 0;
	Patient PatientTemp = { 0 };
	Visit PatientsTempVisit = { 0 };
	

	FILE* Ptr2File = fopen("Patients.txt", "r");
	if (!Ptr2File) {
		printf("Error opening Ptr2File: %s\n", "Patients.txt");
		return;
	}

	FILE* Ptr2File_FilePointer = Ptr2File;
	fseek(Ptr2File_FilePointer, 21, SEEK_CUR); //Skips first line in txt file
	
	while(Ptr2File_FilePointer != EOF){
	// Read Patients NAME,ID,ALLERGIES.
	{
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);

		sscanf(Line, "%*d.%[^;];%[^;];%s", Name, ID, Allergies_String);

		sscanf(Allergies_String, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^ ] ", Allergies[0]
			, Allergies[1], Allergies[2], Allergies[3], Allergies[4], Allergies[5], Allergies[6], Allergies[7]);

		for (int i = 0; i < 8; i++)
		{
			if (strcmp(Allergies[i], "none") == 0) PatientTemp.Allergies |= NONE;
			if (strcmp(Allergies[i], "Penicillin") == 0) PatientTemp.Allergies |= PENICILLIN;
			if (strcmp(Allergies[i], "Sulfa") == 0) PatientTemp.Allergies |= SULFA;
			if (strcmp(Allergies[i], "Opioids") == 0) PatientTemp.Allergies |= OPIOIDS;
			if (strcmp(Allergies[i], "Anesthetics") == 0) PatientTemp.Allergies |= ANESTHETICS;
			if (strcmp(Allergies[i], "Eggs") == 0) PatientTemp.Allergies |= EGGS;
			if (strcmp(Allergies[i], "Latex") == 0) PatientTemp.Allergies |= LATEX;
			if (strcmp(Allergies[i], "Preservatives") == 0) PatientTemp.Allergies |= PRESERVATIVES;
		}

		PatientTemp.Name = malloc(sizeof(Name));
		if (!PatientTemp.Name) {
			printf("Cannot allocate memory");
			exit(1);
		}

		strcpy(PatientTemp.Name, &Name);
		strcpy(&PatientTemp.ID, &ID);

		printf("%s %s %d\n", PatientTemp.Name, PatientTemp.ID, PatientTemp.Allergies);
	}
	int flag = 0;
	//Reads Patients Visits
	while(flag != 1){
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		sscanf(Line, "Arrival:%[^/]/%[^/]/%[^ ] %[^:]:%[^\n]", Day, Month, Year, Hour, Minute);
		printf("%s %s %s %s %s\n", Day, Month, Year, Hour, Minute);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		sscanf(Line, "Dismissed:%[^/]/%[^/]/%[^ ] %[^:]:%[^\n]", Day, Month, Year, Hour, Minute);
		printf("%s %s %s %s %s\n", Day, Month, Year, Hour, Minute);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		sscanf(Line, "Duration:%[^:]:%[^\n]", Hour, Minute);
		printf("%s %s\n", Hour, Minute);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		sscanf(Line, "Doctor:%[^\n]", Doctor_Name);
		printf("%s\n", Doctor_Name);
		fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		sscanf(Line, "Summary:%[^\n]", Summary);
		printf("%s\n", Summary);
		printf("%s\n", Line);
		if (strcmp(Line, " \n") == 0)
			fgets(Line, sizeof(Line), Ptr2File_FilePointer);
		else flag = 1;
	}
	flag = 0;
	printf("%s\n", Line);
	}
}
