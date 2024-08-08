#include"goToFunction.h"
#include <string.h>


void goToFunc(int choice, List* DoctorsList, pLine* PatientsLine, pTree* PatientsTree)
{

	switch (choice) {
	case 0:
		printf("You chose option to exit the program\n\n");
		updateFiles("Doctors.txt", "Patients.txt", "Line.txt", DoctorsList, PatientsLine, PatientsTree);
		destroyLine(PatientsLine);
		destroyPTree(PatientsTree);
		destroyList(DoctorsList);
		printf("memory has been freed\n\n\t\t#EXITING PROGRAM\n\n");
		break;

	case 1:
		printf("You chose option to admit a patient\n\n");
		printPTree(PatientsTree);
		admitPatient(DoctorsList, PatientsLine, PatientsTree);
		break;

	case 2:
		printf("You chose to check for patients allergies \n\n");

		printLine(PatientsLine);
		CheckForPatientsAllergies(PatientsLine);
		break;

	case 3:
		printf("You chose to display all patients\n\n");
		printPTree(PatientsTree);
		break;

	case 4:
		printf("You chose to display all patient's admissions\n\n");
		printPTree(PatientsTree);
		printf("\n");
		DisplayAllPatientsAdmissions(PatientsLine);
		break;

	case 5:
		printf("You chose to display all patients in line\n\n");
		printLineWithVisit(PatientsLine);
		break;

	case 6:
		printf("You chose to advance patient in line\n\n");
		printLineForADT(PatientsLine);
		AdvancePatientInLine(PatientsLine);
		break;

	case 7:
		printf("You chose to display list of all doctors\n\n");
		Doc_printList(DoctorsList);
		printf("\n");
		break;

	case 8:
		printf("You chose to dispaly all patients assigned to a doctor\n\n");
		Doc_printList(DoctorsList);
		DisplayAllPatientsAssignedToADoctor(DoctorsList, PatientsLine);
		break;

	case 9:
		printf("You chose to discharge patient\n\n");
		printLine(PatientsLine);
		DischargePatient(PatientsLine, PatientsTree, DoctorsList);
		break;

	case 10:
		printf("You chose to remove a visit\n\n");
		removeVisit(PatientsTree);
		break;

	case 11:
		deletePatient(DoctorsList, PatientsLine, PatientsTree);
		break;

	case 12:
		printf("You chose to close the hospital\n\n");
		destroyLine(PatientsLine);
		destroyPTree(PatientsTree);
		destroyList(DoctorsList);
		updateFiles("DoctorsTest.txt", "PatientsTest.txt", "LineTest.txt", DoctorsList, PatientsLine, PatientsTree);
		break;
	}
}

void CheckForPatientsAllergies(pLine* PatientsLine)
{
	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;

	do {
		printf("Enter an ID:");
		fseek(stdin, 0, SEEK_SET);
		fgets(ID, 10, stdin);
		
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\" to return to menu\n");

	} while (Ptr2PatientsNode == NULL);

	PtrPatient = Ptr2PatientsNode->lpatient;
	printf("\nPatients Name:%s ID:%s \n", PtrPatient->Name, PtrPatient->ID);
	printf("Patients Allergies: ");
	if (PtrPatient->Allergies & NONE)  printf("None. ");
	if (PtrPatient->Allergies & PENICILLIN) printf("Penicillin ");
	if (PtrPatient->Allergies & SULFA)  printf("Sulfa ");
	if (PtrPatient->Allergies & OPIOIDS)  printf("Opioids ");
	if (PtrPatient->Allergies & ANESTHETICS) printf("Anesthetics ");
	if (PtrPatient->Allergies & EGGS) printf("Eggs ");
	if (PtrPatient->Allergies & LATEX) printf("Latex ");
	if (PtrPatient->Allergies & PRESERVATIVES) printf("Preservatives ");
	printf("\n\n\n");
}

void DisplayAllPatientsAdmissions(pLine* PatientsLine) {

	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;
	do {
		printf("Enter an ID:");
		fseek(stdin, 0, SEEK_SET);
		fgets(ID, 10, stdin);
		
		
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu\n");

	} while (Ptr2PatientsNode == NULL);
	PtrPatient = Ptr2PatientsNode->lpatient;
	printf("\nPatients information:\nName:%s ID:%s \n\n", PtrPatient->Name, PtrPatient->ID);
	printStack(PtrPatient->Visits);
}

void AdvancePatientInLine(pLine* PatientsLine)
{
	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;
	do {

		printf("\nEnter an ID:");
		fseek(stdin, 0, SEEK_SET);
		fgets(ID, 10, stdin);
		
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu\n");

	} while (Ptr2PatientsNode == NULL);
	moveToHead(PatientsLine, ID);
	printLineForADT(PatientsLine);
	printf("\n");
}

void DisplayAllPatientsAssignedToADoctor(List* DoctorsList, pLine* PatientsLine)
{
	int i = 0;
	int flag = 0;
	int capitalizeNext = 1;
	char DoctorsName[100];
	Node* DoctorsNode;
	pInLine* TempLineNode;
	do {

		printf("Enter an Doctors Name:");
		fseek(stdin, 0, SEEK_SET);
		fgets(DoctorsName, 100, stdin);
		DoctorsName[(strlen(DoctorsName) - 1)] = '\0';

		while (DoctorsName[i] != '\0') {
			if (isspace(DoctorsName[i])) {
				capitalizeNext = 1;  // Next character should be capitalized
			}
			else if (capitalizeNext && isalpha(DoctorsName[i])) {
				DoctorsName[i] = toupper(DoctorsName[i]);
				capitalizeNext = 0;  // Only capitalize the first letter of the word
			}
			else {
				DoctorsName[i] = tolower(DoctorsName[i]);
			}
			i++;
		}
	
		DoctorsNode = searchDoctor(DoctorsList, DoctorsName);

		if (strcmp(DoctorsName, "XXX") == 0) {
			printf("\n\n");
			return;
		}

		if (DoctorsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu\n");

	} while (DoctorsNode == NULL);
	TempLineNode = PatientsLine->head;
	printf("\n");
	while (TempLineNode) {
		if (strcmp(TempLineNode->lpatient->Visits->sList.head->Visit.Doctor->Name, DoctorsNode->Doctor.Name) == 0) {
			printf("Name: %s ID %s\n", TempLineNode->lpatient->Name, TempLineNode->lpatient->ID);
			printVisit(TempLineNode->lpatient->Visits->sList.head->Visit);
			flag = 1;
		}

		
		TempLineNode = TempLineNode->next;
	}
	if (flag == 0) {
		printf("No active visits!!\n");

	}
}

void deletePatient(List* DoctorsList, pLine* PatientsLine, pTree* PatientsTree)
{
	printf("You chose to remove patient\n\n");
	char id_temp[ID_SIZE] = { 0 };
	Patient* temp_pat = NULL;
	// Get the patient ID from the user
	while (1) {
		printf("\nPlease enter the ID of the patient: ");
		scanf("%s", id_temp);
		printf("\n");
		if (validInput(id_temp, "id") == 1) {
			if ((temp_pat = searchPatient(PatientsTree, id_temp)) == NULL) {
				printf("The ID isn't in the list of patients. Please try again.\n");
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("INVALID ID INPUT. TRY AGAIN.\n");
		}
	}
	if (searchPatientLine(PatientsLine, id_temp) != NULL)
	{
		printf("Discharge Patient before deleting records from system\n\n");
		return;
	}
	moveToHead(PatientsLine, temp_pat->ID);
	deLine(PatientsLine);
	deletePTree(PatientsTree, temp_pat->ID);
}