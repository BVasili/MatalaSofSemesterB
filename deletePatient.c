#include "source code/deletePatient.h"


void deletePatient(pLine* PatientsLine, pTree* PatientsTree, List* DoctorsList)
{
	/// getting the id input from the user
	char id_temp[ID_SIZE] = { 0 };
	Patient* temp_pat = NULL;
	Node* temp_visit = NULL;
	while (1)
	{
		printf("\nplease enter the id of the patient:");
		fseek(stdin, 0, SEEK_END);
		fgets(id_temp, ID_SIZE, stdin);
		printf("\n");
		if (validInput(id_temp, "id") == 1)
		{
			if (searchPatient(PatientsTree, id_temp) == NULL)
			{
				printf("the ID isnt in the list of patients please try again\n");
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("INVALID ID INPUT TRY AGAIN\n");
		}
	}

	///check if the patient is in the line and if so discharge the patient
	if (searchPatientLine(&PatientsLine, id_temp) != NULL)
	{
		printf("patient is currently inline\nwe need to discharge the patient before we remove the patient\n\
we will ask for the ID again to remove the patient from the line\n");
		DischargePatient(PatientsLine, PatientsTree, DoctorsList);
	}
	
	/// we need to remove this patient from the tree
	

}
