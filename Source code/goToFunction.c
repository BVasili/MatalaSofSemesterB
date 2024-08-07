#include"goToFunction.h"
#include <string.h>


void goToFunc(int choice, List* DoctorsList,pLine* PatientsLine,pTree* PatientsTree)
{
	char ID[ID_SIZE];
	char DoctorsName[NAME_SIZE];
	pInLine* temp;
	Node* tempNode;
	Patient* PtrPatient;
	switch (choice){
	case 0:
		printf("You chose option to exit the program\n\n");
		updateFiles("DoctorsTest.txt", "PatientsTest.txt", "LineTest.txt", DoctorsList, PatientsLine, PatientsTree);
		destroyLine(PatientsLine);
		destroyPTree(PatientsTree);
		destroyList(DoctorsList);
		printf("memory has been freed\n\n\t\t#EXITING PROGRAM\n\n");
		break;

	case 1:
		printf("You chose option to admit a patient\n\n");
		admitPatient(DoctorsList, PatientsLine, PatientsTree);
		break;

	case 2:
		printf("You chose to check for patients allergies \n\n");

			printLine(PatientsLine);
			Function2(PatientsLine);
			break;
		
	case 3:
		printf("You chose to display all patients\n\n");
		printPTree(PatientsTree);
		break;

	case 4:
		printf("You chose to display all patient's admissions\n\n");
		printPTree(PatientsTree);
		printf("\n");
		Function4(PatientsLine);
		break;

	case 5:
		printf("You chose to display all patients in line\n\n");
		printLineWithVisit(PatientsLine);
		break;

	case 6:
		printf("You chose to advance patient in line\n\n");
		printLineADT(PatientsLine);
		Function6(PatientsLine);
		break;

	case 7:
		printf("You chose to display list of all doctors\n\n");
		Doc_printList(DoctorsList);
		break;

	case 8:
		printf("You chose to dispaly all patients assigned to a doctor\n\n");
		Doc_printList(DoctorsList);
		Function8(DoctorsList, PatientsLine);
		break;

	case 9:
		printf("You chose to discharge patient\n\n");
		printPTree(PatientsTree);
		DischargePatient(PatientsLine, PatientsTree,DoctorsList);
		break;

	case 10:
		printf("You chose to remove a visit\n\n");
		removeVisit(PatientsTree);
		break;

	case 11:
		printf("You chose to remove patient\n\n");
		///////////////////
		///////////////////
		///////////////////
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

void Function2(pLine* PatientsLine)
{
	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;
	
	do {
		printf("Enter an ID:");
		fgets(ID, 10, stdin);
		fgets(ID, 10, stdin);
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\" to return to menu");

	} while (Ptr2PatientsNode == NULL);

	PtrPatient = Ptr2PatientsNode->lpatient;
	printf("Name:%s ID:%s \n",PtrPatient->Name,PtrPatient->ID);
	printf(" Allergies: ");
	if (PtrPatient->Allergies & NONE) printf("None ");
	if (PtrPatient->Allergies & PENICILLIN) printf("Penicillin ");
	if (PtrPatient->Allergies & SULFA) printf("Sulfa ");
	if (PtrPatient->Allergies & OPIOIDS) printf("Opioids ");
	if (PtrPatient->Allergies & ANESTHETICS) printf("Anesthetics ");
	if (PtrPatient->Allergies & EGGS) printf("Eggs ");
	if (PtrPatient->Allergies & LATEX) printf("Latex ");
	if (PtrPatient->Allergies & PRESERVATIVES) printf("Preservatives ");
	printf("\n\n\n");
}

void Function4(pLine* PatientsLine) {

	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;
	do {
		printf("Enter an ID:");
		fgets(ID, 10, stdin);
		fgets(ID, 10, stdin);
		printf("\n");
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu");

	} while (Ptr2PatientsNode == NULL);
	PtrPatient = Ptr2PatientsNode->lpatient;
	printf("Name:%s ID:%s \n\n", PtrPatient->Name, PtrPatient->ID);
	printStack(PtrPatient->Visits);
}

void Function6(pLine* PatientsLine)
{
	char ID[ID_SIZE];
	pInLine* Ptr2PatientsNode;
	Patient* PtrPatient;
	do {
		printf("\nEnter an ID:");
		fgets(ID, 10, stdin);
		fgets(ID, 10, stdin);
		printf("\n");
		Ptr2PatientsNode = searchPatientInLine(PatientsLine, ID);

		if (strcmp(ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (Ptr2PatientsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu");

	} while (Ptr2PatientsNode == NULL);
	moveToHead(PatientsLine, ID);
	printLineADT(PatientsLine);
	printf("\n");
}

void Function8(List* DoctorsList,pLine* PatientsLine)
{
	char DoctorsName[100];
	Node* DoctorsNode;
	pInLine* TempLineNode;
	do {

		printf("Enter an Doctors Name:");
		fseek(stdin, 0, SEEK_SET);
		fgets(DoctorsName, 100, stdin);
		DoctorsName[(strlen(DoctorsName) - 1)] = '\0';
		printf("\n");
		DoctorsNode = searchDoctor(DoctorsList, DoctorsName);

		if (strcmp(DoctorsName, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (DoctorsNode == NULL)
			printf("Enter a valid ID!! or enter \"XXX\"  to return to menu");

	} while (DoctorsNode == NULL);
	TempLineNode = PatientsLine->head;
	while (TempLineNode) {
		if (strcmp(TempLineNode->lpatient->Visits->sList.head->Visit.Doctor->Name, DoctorsNode->Doctor.Name) == 0) {
			printf("Name: %s ID %s\n", TempLineNode->lpatient->Name, TempLineNode->lpatient->ID);
			printVisit(TempLineNode->lpatient->Visits->sList.head->Visit);
		}
		TempLineNode = TempLineNode->next;
	}
}
