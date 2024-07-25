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
#define TESTVISIT__
#define PTREE_ //test for loadPatients + initializePTree + printPTree + searchPatient + destroyPTree + isPTreeEmpty
#define TEST_LOADPATIETS_DOC__
#define DOCTORS_FUNC_TEST_ // test for loadDoctors + assignDoctor2case + sortDocList + initList + Doc_printList
#define GOTOFUNC_PRINTMENU_TEST // test for print menu + gotofunc + actions in the menu (0,2,3,4,5,7) + load patients + load line

int main()
{

#ifdef DOCTORS_FUNC_TEST


	List doctors;
	initList(&doctors);
	if (doctors.head == NULL) //checking if the initializing the doctors list func worked
	{
		printf("INITIALIZED DOCTORS LIST\n\n");
	}
	loadDoctors( &doctors, DOCSFILE);
	Doc_printList(&doctors);//checking if the print is the same as the list and sorted by npatients
	while (1)
	{
		if (assignDoc2Case(&doctors) == NULL)
		{
			printf("reached max capity in the active patients\n");
			break;
		}
		Doc_printList(&doctors);//prints the list of the doctors after assigned a case and checks the print of the doctor's list
	}
	

#endif // DOCTORS_FUNC_TEST

#ifdef GOTOFUNC_PRINTMENU_TEST
	pTree PatientsTree;
	initializePTree(&PatientsTree);
	loadPatients(&PatientsTree, "Patients.txt");
	/*printPTree(&PatientsTree);*/// testing if the patients tree has been copied 
	

	pLine PatientsLine;
	initLine(&PatientsLine);
	loadLine(&PatientsLine, "Line.txt", &PatientsTree);
	/*printLine(&PatientsLine);*/


	
	List doctors;
	initList(&doctors);
	if (doctors.head == NULL) 
	{
		printf("INITIALIZED DOCTORS LIST\n\n");
	}
	loadDoctors(&doctors, DOCSFILE);
	int choice = -1;
	while (1)//calling for print menu which 
	{
		choice = printMenu();
		goToFunc(choice, &doctors, &PatientsLine, &PatientsTree);
		if (choice == 12 || choice == 0)
		{
			exit(1);//we need to free all memory
			break;
		}
	}
#endif // GOTOFUNC_PRINTMENU_TEST


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
	printf("test isPTreeEmpty before loading : %d ----> 1 means yes\n\n", isPTreeEmpty(&PatientTree));
	loadPatients(&PatientTree, "Patients.txt");
	printf("test isPTreeEmpty after loading : %d ----> 0 means no\n\n", isPTreeEmpty(&PatientTree));
	printf("prints ptree:\n\n");
	printPTree(&PatientTree);
	pInTree* testNode = NULL;
	printf("\n\ntestNode address before using \"searchPatient\" : %p \n",testNode);
	testNode = searchPatient(&PatientTree, "123456789");
	printf("testNode address after using \"searchPatient\" : %p \n\n", testNode);
	printf("searched for:%s and got %s\n\n", "123456789", testNode->tpatient.ID);

	destroyPTree(&PatientTree);
	printf("print tree after destoryPTree----->\n");
	printPTree(&PatientTree);
	printf("\ntest isPTreeEmpty : %d ----> 1 means yes\n", isPTreeEmpty(&PatientTree));
#endif // PTREE
	

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
	Test.vSummary = "please give us 100";
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
	printf("test pop---> name %s\n", testVisit2.Doctor->Name);
	printStack(VisitList);
	push(VisitList, testVisit2);
	printStack(VisitList);
	printf(" stack size: %d\n", getStackSize(VisitList));
	destroyStack(VisitList);
	printf(" stack size: %d\n", getStackSize(VisitList));
#endif // TESTVISIT


	return 0;
}
