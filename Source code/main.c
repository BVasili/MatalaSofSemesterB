#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include"BST.h"
#include "Structure.h"
#include"Stack.h"
#define TESTBST
#define TESTVISIT
int main() {

#ifdef TESTBST
	pTree *PatientBST = malloc(sizeof(pTree));
	PatientBST->root = NULL;
	printf("address %p\n", PatientBST);
	printf("is empty: %d\n", Patient_BstEmpty(PatientBST));
	PatientBST = loadPatients();
	printf("is empty: %d\n", Patient_BstEmpty(PatientBST));
	printf("address %p\n", PatientBST);
	//Patient_initializeBST -works --->its inside loadPatients()
	//void Patient_insertBST -works
	printf("is %s in tree? :%d\n", "203389445", Patient_find(PatientBST, "203389445"));
	Patient_PrintTree(PatientBST);
	Patient_destroyBST(PatientBST);
	printf("address %p\n", PatientBST);

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
	printf("%d", Visit_getStackSize(VisitList));
#endif // TESTVISIT

#ifdef PATIENTTEST
	Patient inna = { 0 };
	inna.Name = "inna gefen";
	strcpy(&inna.ID, "12345678");
	inna.Allergies = 0x0;

	pTree* tree = malloc(sizeof(pTree));
	Patient_initializeBST(tree);
	Patient_insertBST(tree, inna);
	Patient_printBST(tree);
#endif // PATIENTTEST

	//this is a testcc
}
