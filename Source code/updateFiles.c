#include "updateFiles.h"
#include<string.h>

char* TranslateBitWiseIntoString(Patient* Patient)
{
	char AllergiesString[500] = "";
	char AllergiesArray[8][20] = { "" }; // Initialize array to prevent uninitialized memory usage

	if (Patient->Allergies & NONE ) strcpy(AllergiesArray[0], "none");
	if (Patient->Allergies & PENICILLIN) strcpy(AllergiesArray[1], "Penicillin;");
	if (Patient->Allergies & SULFA) strcpy(AllergiesArray[2], "Sulfa;");
	if (Patient->Allergies & OPIOIDS) strcpy(AllergiesArray[3], "Opioids;");
	if (Patient->Allergies & ANESTHETICS) strcpy(AllergiesArray[4], "Anesthetics;");
	if (Patient->Allergies & EGGS) strcpy(AllergiesArray[5], "Eggs;");
	if (Patient->Allergies & LATEX) strcpy(AllergiesArray[6], "Latex;");
	if (Patient->Allergies & PRESERVATIVES) strcpy(AllergiesArray[7], "Preservatives;");

	for (int i = 0; i < 8; i++) {
		strcat(AllergiesString, AllergiesArray[i]);
	}

	// Remove trailing comma if present
	int len = strlen(AllergiesString);
	if (len > 0 && AllergiesString[len - 1] == ';') {
		AllergiesString[len - 1] = '\0';
	}

	return AllergiesString;
}

void InsertPatientsTreeToFile(FILE* file, pInTree* treeNode, int* index)
{
	if (!treeNode)
		return;

	InsertPatientsTreeToFile(file, treeNode->left, index);

	(*index)++;
	writePatientToFile(file, treeNode, index);

	InsertPatientsTreeToFile(file, treeNode->right, index);
}

void writePatientToFile(FILE* file, pInTree* treeNode, int* index)
{
	int Duration_Hours = 0;
	Patient Patient = treeNode->tpatient;

	fprintf(file, "%d.%s;%s;%s\n\n", *index, Patient.Name, Patient.ID, TranslateBitWiseIntoString(&Patient));

	Stack* PatientsStack = Patient.Visits;

	Stack* TempStack = malloc(sizeof(Stack));

	Visit TempVisit;

	if (checkPointer(TempStack, ALLOCATION_FAILED))
		return;

	initStack(TempStack);

	while (!isEmptyStack(PatientsStack)) {
		TempVisit = pop(PatientsStack);
		push(TempStack, TempVisit);
	}
	
	while (!isEmptyStack(TempStack))
	{
		TempVisit = pop(TempStack); //Popping from patients stack
		int Duration_Hours = (int)(TempVisit.Duration) - ((int)(TempVisit.Duration) % 60);

		fprintf(file, "Arrival:%02d/%02d/%04d %02d:%02d\n", TempVisit.tArrival.Day, TempVisit.tArrival.Month, TempVisit.tArrival.Year, TempVisit.tArrival.Hour, TempVisit.tArrival.Min);

		if (TempVisit.Duration != -1.0)
			fprintf(file, "Dismissed:%02d/%02d/%04d %02d:%02d\n", TempVisit.tDismissed.Day, TempVisit.tDismissed.Month, TempVisit.tDismissed.Year, TempVisit.tDismissed.Hour, TempVisit.tDismissed.Min);
		else
			fprintf(file, "Dismissed:\n");

		if (TempVisit.Duration != -1.0)
			
			fprintf(file, "Duration:%d:%.2d\n", Duration_Hours/60, (int)(TempVisit.Duration)%60);
		else
			fprintf(file, "Duration:\n");

		if (TempVisit.Doctor->Name != NULL)
			fprintf(file, "Doctor:%s\n", TempVisit.Doctor->Name);
		else
			fprintf(file, "Doctor:\n");

		if (TempVisit.vSummary != NULL)
			fprintf(file, "Summary:%s\n", TempVisit.vSummary);
		else
			fprintf(file, "Summary:\n");

		if(!isEmptyStack(TempStack))
		fprintf(file, "\n");

		push(PatientsStack, TempVisit); //pushing visit into temporary stack

	}
	fprintf(file, "========================\n");
	free(TempStack);
}

void updateFiles(char* DoctorsFile, char* PatientsFile, char* LineFile, List* DoctorsList, pLine* PatientsLine, pTree* PatientsTree)
{
	int index_line = 1;
	int index = 0;

	// Patient Line To File
	FILE* LineFilePtr = fopen(LineFile, "w");
	if (checkPointer(LineFilePtr, CANNOT_OPEN_FILE))
		return;

	pInLine* PatientsInLine = PatientsLine->head;

	fprintf(LineFilePtr, "Patients' IDs in line\n");
	fprintf(LineFilePtr, "=====================\n");

	while (PatientsInLine)
	{
		fprintf(LineFilePtr, "%d.%s\n", index_line++, PatientsInLine->lpatient->ID);
		PatientsInLine = PatientsInLine->next;
	}

	fclose(LineFilePtr);

	// Patient BST To File
	FILE* PatientFilePtr = fopen(PatientsFile, "w");
	if (checkPointer(PatientFilePtr, CANNOT_OPEN_FILE))
		return;

	fprintf(PatientFilePtr, "Name; ID; Allergies\n");
	fprintf(PatientFilePtr, "========================\n");
	
	InsertPatientsTreeToFile(PatientFilePtr, PatientsTree->root, &index);
	fprintf(PatientFilePtr, "\n");
	fprintf(PatientFilePtr, "\t");
	fclose(PatientFilePtr);

	// Doctors List Into File
	FILE* DoctorsFilePtr = fopen(DoctorsFile, "w");
	if (checkPointer(DoctorsFilePtr, CANNOT_OPEN_FILE))
		return;

	Node* TempDoctorInSLL = DoctorsList->head;

	fprintf(DoctorsFilePtr, "Full Name; License Number; Number of Patients\n");
	fprintf(DoctorsFilePtr, "=================================================\n");

	while (TempDoctorInSLL != NULL)
	{
		fprintf(DoctorsFilePtr, "%s; %s; %d\n", TempDoctorInSLL->Doctor.Name, TempDoctorInSLL->Doctor.nLicense, TempDoctorInSLL->Doctor.nPatients);
		TempDoctorInSLL = TempDoctorInSLL->next;
	}
	fclose(DoctorsFilePtr);
}

