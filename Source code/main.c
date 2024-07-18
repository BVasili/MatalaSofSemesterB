#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include"BST.h"
#include "Structure.h"
#include"Stack.h"
#include"loadPatients.h"
#include "loadDoctors.h"
#include"printMenu.h"
#include"searchPatient.h"
#include"loadLine.h"


//Debug
#define TESTBST
#define TESTVISIT_

int main() {
	Queue hello = { 0 };
	Line_initQueue(&hello);
	//printMenu();
	//loadDoctors();

#ifdef TESTBST
	pTree PatientBST = { 0 };
	//printf("address %p\n", PatientBST);
	loadPatients(&PatientBST,"Patients.txt");
	//printf("is empty: %d\n", Patient_BstEmpty(&PatientBST));
	//printf("address %p\n", PatientBST);
	//Patient_initializeBST -works --->its inside loadPatients()
	//void Patient_insertBST -works
	//printf("is %s in tree? :%d\n", "203389445", Patient_find(&PatientBST, "203389445"));
	//Patient_PrintTree(&PatientBST);
	//Patient_destroyBST(&PatientBST);
	//printf("address %p\n", PatientBST);
	//pTree* Patient_adress = searchPatient(&PatientBST, "123456789");
	//printf("patient id  \"123456789\" adress is: %p\n", Patient_adress);
	loadLine(&hello, "Line.txt", &PatientBST);
	Line_printQueue(&hello);

	Patient* test= Line_dequeue(&hello);
	List DoctorList = { 0 };
	loadDoctors(&DoctorList, "Doctors.txt");
	Doc_printList(&DoctorList, "s");
#endif // TESTBST

#ifdef TESTVISIT
	Visit Test = { 0 };
	Test.tArrival.Day = 1;
	Test.tArrival.Month = 2;
	Test.tArrival.Year = 2024;
	Test.tArrival.Min = 20;
	Test.tArrival.Hour = 10;

	Test.tDismissed.Day = 1;
	Test.tDismissed.Month = 2;
	Test.tDismissed.Year = 2024;
	Test.tDismissed.Min = 20;
	Test.tDismissed.Hour = 10;

	Test.Duration = 40;

	Test.Doctor = malloc(sizeof(Doc));
	Test.Doctor->Name = "Boris";
	Stack* VisitList = malloc(sizeof(Stack));
	Visit_initStack(VisitList);
	Visit_push(VisitList, Test);
	Visit_printStack(VisitList);
	Visit testVisit = Visit_peekStack(VisitList);
	printf(" name %s\n", testVisit.Doctor->Name);
	Visit testVisit2 = Visit_pop(VisitList);
	printf(" name %s\n", testVisit2.Doctor->Name);
	Visit_printStack(VisitList);
	Visit_push(VisitList, testVisit2);
	Visit_printStack(VisitList);
	printf(" stack size: %d\n", Visit_getStackSize(VisitList));
	Visit_destroyStack(VisitList);
	printf(" stack size: %d\n", Visit_getStackSize(VisitList));
#endif // TESTVISIT


	return 0;
}
