#include"DischargePatient.h"
#include <time.h>
#include<string.h>


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
		printf("\nEnter an ID:");
		fgets(Patients_ID, 10, stdin);
		fgets(Patients_ID, 10, stdin);
		PatientToDischarge = searchPatient(PatientsTree, Patients_ID);

		if (strcmp(Patients_ID, "XXX\n") == 0) {
			printf("\n\n");
			return;
		}

		if (PatientToDischarge == NULL)
			printf("Enter a valid ID!! or enter \"XXX\" to return to menu");

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

	//Asks User to input summary for visit
	printf("Enter summary for visit:");
	fgets(TempSummary, SUMMARY_SIZE, stdin);
	fgets(TempSummary, SUMMARY_SIZE, stdin);

	char* VisitSummary = (char*)malloc(strlen(TempSummary));
	if (checkPointer(VisitSummary, ALLOCATION_FAILED))
		return;

	TempSummary[strlen(TempSummary) - 1] = '\0';
	strcpy(VisitSummary, TempSummary);
	
	VisistToDischarge.vSummary = VisitSummary;

	//Adjusts doctor's number of patients 
	--(VisistToDischarge.Doctor->nPatients);

	//Gets current time and duration and stores in Visit
	Arrival.tm_year = VisistToDischarge.tArrival.Year - 1900;
	Arrival.tm_mon = VisistToDischarge.tArrival.Month - 1;
	Arrival.tm_mday = VisistToDischarge.tArrival.Day;
	Arrival.tm_hour = VisistToDischarge.tArrival.Hour;
	Arrival.tm_min = VisistToDischarge.tArrival.Min;

	ArrivalTime = mktime(&Arrival);

	VisistToDischarge.tDismissed.Day = Dismissed.tm_mday;
	VisistToDischarge.tDismissed.Month = Dismissed.tm_mon +1;
	VisistToDischarge.tDismissed.Year = Dismissed.tm_year+1900;
	VisistToDischarge.tDismissed.Hour = Dismissed.tm_hour;
	VisistToDischarge.tDismissed.Min = Dismissed.tm_min;

	VisitDuration = (float)(difftime(DismissedTime,ArrivalTime)/60);
	VisistToDischarge.Duration = VisitDuration;

	//pushes the visit into the patients stack and prints it
	push(PatientToDischarge->tpatient.Visits,VisistToDischarge);
	printVisit(PatientToDischarge->tpatient.Visits->sList.head->Visit);
}
