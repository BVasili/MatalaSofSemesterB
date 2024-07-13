#include "AuxiliaryFunctions.h"
#include "Structure.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG

int printMenu(void)
{
	int action = -1;
	while (action < 0 && action > 12)
	{
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
	}

	return action;
}

void loadPatients()
{
#ifdef DEBUG
	int countLetters = 0;
	char tempLetter;
	char temp[NAME_SIZE];
	Patient PatientPlaceHolder;
	Visit VisitPlaceHolder;

	FILE* PtrPatients = fopen("Patients.txt", "r");
	if (!PtrPatients)
	{
		printf("Error: Cannot Reach Memory Address\n");
		exit(1);
	}

	// the first three loops is only to get to the first letter of the name, it will be different and optimized //fseek
	while ((tempLetter = fgetc(PtrPatients)) != '=')

		countLetters++;

	while ((tempLetter = fgetc(PtrPatients)) == '=')

		countLetters++;

	while (((tempLetter = fgetc(PtrPatients)) == '\n') || ((tempLetter = fgetc(PtrPatients)) == '1'))

		countLetters++;

	countLetters = 0;

	// extracting the name out of the file
	while ((tempLetter = fgetc(PtrPatients)) != ';')
	{
		temp[countLetters] = tempLetter;
		countLetters++;
	}
	temp[countLetters] = '\0';

	PatientPlaceHolder.Name = (char*)malloc((countLetters + 1) * sizeof(char*));

	if (!PatientPlaceHolder.Name)
	{
		printf("Cannot allocate memory");
		exit(1);
	}

	for (int i = 0; i <= countLetters; i++) // try strcpy
		PatientPlaceHolder.Name[i] = temp[i];

	// extracting the id out of the file
	countLetters = 0;
	while ((tempLetter = fgetc(PtrPatients)) != ';')
	{
		temp[countLetters] = tempLetter;
		countLetters++;
	}
	temp[countLetters] = '\0';

	for (int i = 0; i <= countLetters; i++) // strcpy
		PatientPlaceHolder.ID[i] = temp[i];

	// extracting the allergies out of the file
	PatientPlaceHolder.Allergies = none;
	countLetters = 0;

	while ((tempLetter = fgetc(PtrPatients)) != EOF)
	{
		temp[countLetters] = tempLetter;
		countLetters++;
		while ((tempLetter = fgetc(PtrPatients)) != ',')
		{
			if (tempLetter == '\n')
				break;
			temp[countLetters] = tempLetter;
			countLetters++;
		}

		temp[countLetters] = '\0';
		countLetters = 0;
		PatientPlaceHolder.Allergies |= getAllergyBit(temp);

		if (tempLetter == '\n')
			break;
	}

	printf("name:\t%s\nid:\t%s\n", PatientPlaceHolder.Name, PatientPlaceHolder.ID);
	exit(1);
	// dont forget to close the file
#endif // DEBUG

}
char getAllergyBit(const char* allergy)
{
	if (strcmp(allergy, "Penicillin") == 0)
		return Penicillin;
	if (strcmp(allergy, "Sulfa") == 0)
		return Sulfa;
	if (strcmp(allergy, "Opioids") == 0)
		return Opioids;
	if (strcmp(allergy, "Anesthetics") == 0)
		return Anesthetics;
	if (strcmp(allergy, "Eggs") == 0)
		return Eggs;
	if (strcmp(allergy, "Latex") == 0)
		return Latex;
	if (strcmp(allergy, "Preservatives") == 0)
		return Preservatives;
	return none;
}