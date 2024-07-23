#include"assignDoctor2case.h"

Node* assignDoc2Case( List* DoctorsList) {

	if(checkPointer(DoctorsList,NULL_POINTER))
		return NULL;
	if (checkPointer(DoctorsList->head, NULL_POINTER)) {
		printf("List of doctors is empty\n");
		return NULL;
	}
		

	Node* temp = DoctorsList->head;
	Node* selectedDoctor = NULL;
	int i = 0;
	int minNpatients = 0;
	int numberOfDoctors = 0;
	int nPatientsArray[MAX_PATIENTS+1] = { 0 };

	while (temp!= NULL) {
		i = temp->Doctor.nPatients;
		nPatientsArray[i]++;
		numberOfDoctors++;
		temp = temp->next;
	}
	
	for (int k = 0; k < MAX_PATIENTS+1; k++)
	{

		if (k == MAX_PATIENTS)
			break;
		if (nPatientsArray[k] > nPatientsArray[k + 1]) {
			minNpatients = k ;
			break;
		}
	}

	if (nPatientsArray[MAX_PATIENTS+1] == numberOfDoctors)
	{
		printf("\t###THERE ARE NO AVAILABLE DOCTORS###\n");
		return NULL;
	}

	temp = DoctorsList->head;

	// Find the first doctor with fewer than 4 patients
	while (temp != NULL) {
		if (temp->Doctor.nPatients == minNpatients) {
			selectedDoctor = temp;
			break;
		}
		temp = temp->next;
	}

	if (selectedDoctor == NULL) {
		printf("No available doctors.\n");
		return NULL;
	}

	// Print available doctors and their patient count
	temp = DoctorsList->head;
	while (temp != NULL) {
		if (temp->Doctor.nPatients < MAX_PATIENTS) {
			printf("NAME: %s is available and has %d active patients\n", temp->Doctor.Name, temp->Doctor.nPatients);
		}
		temp = temp->next;
	}
	printf("\n\n");

	// Increment the patient count of the selected doctor
	selectedDoctor->Doctor.nPatients++;


	return selectedDoctor;
}
