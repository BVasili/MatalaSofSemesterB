#include"goToFunction.h"

void goToFunc(int choice, List* DoctorsList,pLine* PatientsLine,pTree* PatientsTree)
{
	char ID[ID_SIZE];
	pInLine* temp;
	Patient* ptrPatient;
	switch (choice){
	case 0:
		printf("You chose option to exit the program\n\n");
		// Your code for option 0 goes here
		break;
	case 1:
		printf("You chose option to admit a patient\n\n");
		// Your code for option 1 goes here
		break;
	case 2:
		printf("You chose to check for patients allergies \n\n");
		
		// Your code for option 2 goes here

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
					printf("Enter a valid ID!! or enter \"XXX\" ");

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
		// Your code for option 4 goes here

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
				printf("Enter a valid ID!! or enter \"XXX\" ");

		} while (temp == NULL);
		ptrPatient = temp->lpatient;
		printf("Name:%s ID:%s \n\n", ptrPatient->Name, ptrPatient->ID);
		printStack(ptrPatient->Visits);
		break;
	case 5:
		printf("You chose to display all patients in line\n\n");
		// Your code for option 5 goes here
		printLineWithVisit(PatientsLine);
		break;
	case 6:
		printf("You chose to advance patient in line\n\n");
		// Your code for option 6 goes here
		break;
	case 7:
		printf("You chose to display list of all doctors\n\n");
		Doc_printList(&DoctorsList);
		// Your code for option 7 goes here
		break;
	case 8:
		printf("You chose to dispaly all patients assigned to a doctor\n\n");
		// Your code for option 8 goes here
		break;
	case 9:
		printf("You chose to discharge patient\n\n");
		// Your code for option 9 goes here
		break;
	case 10:
		printf("You chose to remove a visit\n\n");
		// Your code for option 10 goes here
		break;
	case 11:
		printf("You chose to remove patient\n\n");
		// Your code for option 11 goes here
		break;
	case 12:
		printf("You chose to close the hospital\n\n");
		// Your code for option 12 goes here
		break;
	}
}

