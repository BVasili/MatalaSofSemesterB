#include"goToFunction.h"

void goToFunc(int choice, List* DoctorsList)
{
	switch (choice) {
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
		break;
	case 3:
		printf("You chose to display all patients\n\n");
		// Your code for option 3 goes here
		break;
	case 4:
		printf("You chose to display all patient's admissions\n\n");
		// Your code for option 4 goes here
		break;
	case 5:
		printf("You chose to display all patients in line\n\n");
		// Your code for option 5 goes here
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