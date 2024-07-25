#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include"BST.h"
#include "Structure.h"
#include"Stack.h"
#include"loadPatients.h"
#include "loadDoctors.h"
#include"printMenu.h"
#include"pTree.h"
#include"loadLine.h"
#include"assignDoctor2case.h"
#include"updateFiles.h"
#include"goToFunction.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 

#define DOCSFILE "Doctors.txt"


//Debug
#define TESTVISIT_
#define PTREE
#define TEST_LOADPATIETS_DOC


int main()
{ 
	//List doctors;
	//initList(&doctors);
	//loadDoctors(1,&doctors, DOCSFILE);
	//int choice = -1;
	//while (1)
	//{
	//	choice = printMenu();
	//	goToFunc(choice, &doctors );
	//	if (choice == 12 || choice == 0)
	//	{
	//		exit(1);//we need to free all memory
	//		break;
	//	}
	//}
#ifdef TEST_LOADPATIETS_DOC
	pTree PatientsTree;
	initializePTree(&PatientsTree);
	loadPatients(&PatientsTree, "Patients.txt");
	List DoctorsList;
	pLine PatientsLine;
	initLine(&PatientsLine);
	loadLine(&PatientsLine, "Line.txt", &PatientsTree);
	Doc TestDoc = { 0 };
	//printf("DoctorsList head address before initializing: %p\n", DoctorsList.head);
	initList(&DoctorsList);
	loadDoctors(&DoctorsList, "Doctors.txt");
	//printf("DoctorsList head address after initializing and loading doctors: %p\n\n\n", DoctorsList.head);
	//TestDoc = Doc_peekList(&DoctorsList);
	//printf("Test peekList : name is %s\n", TestDoc.Name);
	//TestDoc = Doc_removeFromHead(&DoctorsList);
	//TestDoc = Doc_peekList(&DoctorsList);
	//printf("Test removeFromHead : name is %s\n\n", TestDoc.Name);
	//printf("test printlist :\n\n");
	//Doc_printList(&DoctorsList);
	//printf("\n\ntest isEmptyList: %d\n", Doc_isEmptyList(&DoctorsList));
	//Doc_destroyList(&DoctorsList);
	//printf("test after destroyList isEmptyList: %d\n", Doc_isEmptyList(&DoctorsList));
	//int answer = 5;
	//goToFunc(answer, &DoctorsList, &PatientsLine,&PatientsTree);
	//Node* testnode = assignDoc2Case(&DoctorsList);
	//works for now
#endif // TEST_LOADPATIETS_DOC


#ifdef PTREE
	pTree PatientTree = { 0 };
	initializePTree(&PatientTree);
	printf("test isPTreeEmpty : %d\n", isPTreeEmpty(&PatientTree));
	loadPatients(&PatientTree, "Patients.txt");
	printf("test isPTreeEmpty : %d\n", isPTreeEmpty(&PatientTree));
	printPTree(&PatientTree);
	pInTree* testNode = NULL;
	testNode = searchPatient(&PatientTree, "123456789");
	destroyPTree(&PatientTree);
	printPTree(&PatientTree);
	printf("test isPTreeEmpty : %d\n", isPTreeEmpty(&PatientTree));
#endif // PTREE
	goToFunc(0, &DoctorsList, &PatientsLine, &PatientsTree);
	//updateFiles("DoctorsDemo.txt", "PatientsDemo.txt", "LineDemo.txt", &DoctorsList, &PatientsLine,&PatientsTree);

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
	initStack(VisitList);
	push(VisitList, Test);
	printStack(VisitList);
	Visit testVisit = peekStack(VisitList);
	printf(" name %s\n", testVisit.Doctor->Name);
	Visit testVisit2 = pop(VisitList);
	printf(" name %s\n", testVisit2.Doctor->Name);
	printStack(VisitList);
	push(VisitList, testVisit2);
	printStack(VisitList);
	printf(" stack size: %d\n", getStackSize(VisitList));
	destroyStack(VisitList);
	printf(" stack size: %d\n", getStackSize(VisitList));
#endif // TESTVISIT


	return 0;
}
