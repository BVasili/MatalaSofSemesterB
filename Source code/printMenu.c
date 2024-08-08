#define _CRT_SECURE_NO_WARNINGS
#include "printMenu.h"
#include <stdio.h>
#include<stdlib.h>
#include "removeVisit.h"

// Prints menu and returns an integer between 0 - 12
int printMenu(void)
{
	char action[3] = {0};
	do
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
		printf("\n\nplease enter the number of the wanted action:\t");
		fseek(stdin, 0, SEEK_END);
		fgets(action, 3, stdin);
		if (atoi(action) < 0 || atoi(action) > 12 || is_all_digits(action) == 0)
		{
			printf("\n\nERROR:\tplease enter a number between 0 and 12 include\n\n");
		}

	} while (atoi(action) < 0 || atoi(action) > 12|| is_all_digits(action) == 0);

	return atoi(action);
}