#include "updateFiles.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 

void updateFiles(char* DoctorsFile, char* PatientsFile, char* LineFile, List* DoctorsList, pLine* PatientsLine, pTree* PatientsTree)
{
	char ID[10] = "123456789";
	int index = 1;
	Stack* tempStack1;
	pInTree* tempTree;
	Stack* PatientsVisitStack;
	Visit TempVisit;
	Patient* ptrTempPatient = NULL;
	FILE* ptr2PatientsFile = fopen(PatientsFile, "w");

	if (checkPointer(ptr2PatientsFile, CANNOT_OPEN_FILE))
		return;

	// Write header for patient file
	fprintf(ptr2PatientsFile, "Name;ID;Allergies\n");
	fprintf(ptr2PatientsFile, "=============================\n");
	/*for (int i = 0; i < 999999999; i++)
	{*/
		//_itoa(i, ID, 10);
		tempTree =searchPatient(PatientsTree, ID);
		ptrTempPatient = &tempTree->tpatient;

	/*	if (!ptrTempPatient)
			continue;*/

		fprintf(ptr2PatientsFile, "%d.%s;%s;\n", index, ptrTempPatient->Name, ptrTempPatient->ID);

		tempStack1 = malloc(sizeof(Stack));
		if (checkPointer(tempStack1, CANNOT_OPEN_FILE))
			return;

		initStack(tempStack1);

		PatientsVisitStack = ptrTempPatient->Visits;

		while (!isEmptyStack(PatientsVisitStack)) {

			TempVisit = pop(PatientsVisitStack);
			push(tempStack1, TempVisit);

			fprintf(ptr2PatientsFile, "Arrival:%02d/%02d/%04d %02d:%02d\n", TempVisit.tArrival.Day, TempVisit.tArrival.Month, TempVisit.tArrival.Year, TempVisit.tArrival.Hour, TempVisit.tArrival.Min);


			if (TempVisit.Duration != -1)
				fprintf(ptr2PatientsFile, "Dismissed:%02d/%02d/%04d %02d:%02d\n", TempVisit.tDismissed.Day, TempVisit.tDismissed.Month, TempVisit.tDismissed.Year, TempVisit.tDismissed.Hour, TempVisit.tDismissed.Min);
			else
				fprintf(ptr2PatientsFile, "Dismissed:\n");

			if (TempVisit.Duration != -1)
				fprintf(ptr2PatientsFile, "Duration: %.2f\n", TempVisit.Duration);
			else
				fprintf(ptr2PatientsFile, "Duration:\n");

            }
    }
    fclose(ptr2PatientsFile);

    // Open  doctor file for writing
    FILE* doctorsFile = fopen(doctorsTxt, "w");
    // Check if the file was opened successfully
    if (!doctorsFile)
    {
        // Return if the file could not be opened
        printf("Error opening doctors file for writing.\n");
        return;
    }
    // Write doctors to file
    writeDoctorsToFile(doctorsFile, doctorList);
    // Close the doctors file
    fclose(doctorsFile);

    // Open line file for writing
    FILE* lineFile = fopen(lineTxt, "w");
    // Check if the file was opened successfully
    if (!lineFile)
    {
        // Return if the file could not be opened
        printf("Error opening line file for writing.\n");
        return;
    }
    // Write header for line file
    fprintf(lineFile, "Patients' IDs in line\n");
    fprintf(lineFile, "=====================\n");
    // Write patient queue to file
    writePatientQueueToFile(lineFile, queue);
    // Close the line file
    fclose(lineFile);
}

			if (TempVisit.vSummary != NULL)
				fprintf(ptr2PatientsFile, "Summary:%s\n", TempVisit.vSummary);
			else
				fprintf(ptr2PatientsFile, "Summary:\n");

			fprintf(ptr2PatientsFile, "\n");

			fclose(ptr2PatientsFile);
		/*}*/
		fprintf(ptr2PatientsFile, "=============================\n");
		index++;

		while (!isEmptyStack(tempStack1))
			TempVisit = pop(tempStack1);
		push(PatientsVisitStack, TempVisit);

// Function to write the list of doctors to file
void writeDoctorsToFile(FILE* file, DoctorList* doctorList)
{
    // Print header for doctors file
    fprintf(file, "Full Name; License Number; Number of Patients\n");
    fprintf(file, "=================================================\n");
    // Initialize current node
    docListNode* current = doctorList->head;
    // Write doctors details to file
    while (current != NULL)
    {
        fprintf(file, "%s;%s;%d\n", current->doctor.Name, current->doctor.nLicense, current->doctor.nPatients);
        // Move to the next doctor
        current = current->next;
    }
}

	fclose(ptr2PatientsFile);

// Function to write the patient queue to file
void writePatientQueueToFile(FILE* file, PatientQueue* queue)
{
    // Initialize current node
    pInLine* current = queue->head;
    // Initialize position counter
    int position = 1;
    // Write patient queue details to file
    while (current != NULL)
    {
        fprintf(file, "%d.%s\n", position, current->patient->ID);
        // Move to the next patient in line
        current = current->next;
        // Increment position counter
        position++;
    }
}