#include"DischargePatient.h"
#include <time.h>
#include<string.h>
#include"sortDocList.h"


void DischargePatient(pLine* PatientsLine, pTree* PatientsTree, List* DoctorsList)
{
	//Declaration of Variables
	time_t  DismissedTime = time(NULL);
	time_t ArrivalTime = { 0 };
	struct tm Arrival = { 0 };
	struct tm Dismissed = *localtime(&DismissedTime);
	float VisitDuration = 0;
	Visit VisistToDischarge;
	Date DischargeDate = { 0 };
	char Patients_ID[ID_SIZE];
	char TempSummary[SUMMARY_SIZE];
	pInTree* PatientToDischarge;
	Node* DoctorsNode;

	//Gets ID from user while search returns NULL pointer
	do { 
		printf("Enter an ID:");
		fseek(stdin, 0, SEEK_SET);
		fgets(Patients_ID, 10, stdin);
		PatientToDischarge = searchPatient(PatientsTree, Patients_ID);

		if (strcmp(Patients_ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (PatientToDischarge == NULL)
			printf("Enter a valid ID!! or enter \"XXX\" to return to menu\n");

	} while (PatientToDischarge == NULL);

	//If there are no visits or no ongoing visits - return to menu
	if (PatientToDischarge->tpatient.nVisits == 0 || PatientToDischarge->tpatient.Visits->sList.head->Visit.Duration != -1.0) {
		printf("No Active Visits, Returning to menu.\n");
		return;
	}
	//pop and print ongoing visit
	VisistToDischarge = pop(PatientToDischarge->tpatient.Visits);
	printf("\nPatients Ongoing visit:\n");
	printVisit(VisistToDischarge);

	/*moveToHead(PatientsLine, PatientToDischarge->tpatient.ID);
	deLine(PatientsLine);*/

	//Adjusts doctor's number of patients 
	DoctorsNode = searchDoctor(DoctorsList, VisistToDischarge.Doctor->Name); //------> needs to be in patients structure
	--(DoctorsNode->Doctor.nPatients);
	// Remove the selected doctor from its current position
	DoctorsList->head = removeNode(DoctorsList->head, DoctorsNode);

	// Re-insert the doctor into the list in sorted order
	DoctorsList->head = insertSorted(DoctorsList->head, DoctorsNode);

	//Gets current time and duration and stores in Visit
	Arrival.tm_year = VisistToDischarge.tArrival.Year - 1900;
	Arrival.tm_mon = VisistToDischarge.tArrival.Month - 1;
	Arrival.tm_mday = VisistToDischarge.tArrival.Day;
	Arrival.tm_hour = VisistToDischarge.tArrival.Hour-1;
	Arrival.tm_min = VisistToDischarge.tArrival.Min;

	ArrivalTime = mktime(&Arrival);

	VisistToDischarge.tDismissed.Day = Dismissed.tm_mday;
	VisistToDischarge.tDismissed.Month = Dismissed.tm_mon + 1;
	VisistToDischarge.tDismissed.Year = Dismissed.tm_year + 1900;
	VisistToDischarge.tDismissed.Hour = Dismissed.tm_hour;
	VisistToDischarge.tDismissed.Min = Dismissed.tm_min;

	VisitDuration = (float)(difftime(DismissedTime, ArrivalTime));
	VisistToDischarge.Duration = VisitDuration/60;

	//pushes the visit into the patients stack and prints it
	push(PatientToDischarge->tpatient.Visits, VisistToDischarge);
	printf("\n");
	printVisit(PatientToDischarge->tpatient.Visits->sList.head->Visit);
	moveToHead(PatientsLine, PatientToDischarge->tpatient.ID);
	deLine(PatientsLine);
}
