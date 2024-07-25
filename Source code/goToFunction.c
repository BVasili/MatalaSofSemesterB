#include"goToFunction.h"

void goToFunc(int choice, List* DoctorsList,pLine* PatientsLine,pTree* PatientsTree)
{
	char ID[ID_SIZE];
	pInLine* temp;
	Patient* ptrPatient;
	switch (choice){
	case 0:
		printf("You chose option to exit the program\n\n");
		updateFiles("DoctorsTest.txt", "PatientsTest.txt", "LineTest.txt", DoctorsList, PatientsLine, PatientsTree);
		destroyLine(PatientsLine);
		destroyPTree(PatientsTree);
		Doc_destroyList(DoctorsList);
		break;
	case 1:
		printf("You chose option to admit a patient\n\n");
		
		break;
	case 2:
		printf("You chose to check for patients allergies \n\n");
		

		{
			printLine(PatientsLine);

			do {
				printf("Enter an ID:");
				fgets(ID, 10, stdin);
				temp = searchPatientInLine(PatientsLine, ID);

				if (strcmp(ID, "XXX\n") == 0) {
					printf("\n\n");
					return;
				}

				if (temp == NULL)
					printf("Enter a valid ID!! or enter \"XXX\" to return to menu");

			} while (temp == NULL);

			ptrPatient = temp->lpatient;
			printf("Name:%s ID:%s \n", ptrPatient->Name, ptrPatient->ID);
			printf(" Allergies: ");
			if (ptrPatient->Allergies & NONE) printf("None ");
			if (ptrPatient->Allergies & PENICILLIN) printf("Penicillin ");
			if (ptrPatient->Allergies & SULFA) printf("Sulfa ");
			if (ptrPatient->Allergies & OPIOIDS) printf("Opioids ");
			if (ptrPatient->Allergies & ANESTHETICS) printf("Anesthetics ");
			if (ptrPatient->Allergies & EGGS) printf("Eggs ");
			if (ptrPatient->Allergies & LATEX) printf("Latex ");
			if (ptrPatient->Allergies & PRESERVATIVES) printf("Preservatives ");
			printf("\n\n\n");
			break;
		}

	case 3:
		printf("You chose to display all patients\n\n");
		printPTree(PatientsTree);
		break;
	case 4:
		printf("You chose to display all patient's admissions\n\n");
	

		do {
			printf("Enter an ID:");
			fgets(ID, 10, stdin);
			printf("\n");
			temp = searchPatientInLine(PatientsLine, ID);

			if (strcmp(ID, "XXX\n") == 0) {
				printf("\n\n");
				return;
			}

			if (temp == NULL)
				printf("Enter a valid ID!! or enter \"XXX\"  to return to menu");

		} while (temp == NULL);
		ptrPatient = temp->lpatient;
		printf("Name:%s ID:%s \n\n", ptrPatient->Name, ptrPatient->ID);
		printStack(ptrPatient->Visits);
		break;
	case 5:
		printf("You chose to display all patients in line\n\n");
		
		printLineWithVisit(PatientsLine);
		break;
	case 6:
		printf("You chose to advance patient in line\n\n");
	
		break;
	case 7:
		printf("You chose to display list of all doctors\n\n");
		Doc_printList(&DoctorsList);
		
		break;
	case 8:
		printf("You chose to dispaly all patients assigned to a doctor\n\n");
		
		break;
	case 9:
		printf("You chose to discharge patient\n\n");
	
		break;
	case 10:
		printf("You chose to remove a visit\n\n");
		
		break;
	case 11:
		printf("You chose to remove patient\n\n");
		
		break;
	case 12:
		printf("You chose to close the hospital\n\n");
		
		break;
	}
}

