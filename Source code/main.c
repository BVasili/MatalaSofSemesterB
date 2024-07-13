#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include"BST.h"
#include "Structure.h"
#include"Stack.h"

int main() {
    loadPatients();
    
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
    VisitinitStack(VisitList);
    Visitpush(VisitList, Test);
    VisitprintStack(VisitList);
    printf("%d",VisitgetStackSize(VisitList));
#endif // TESTVISIT

#ifdef PATIENTTEST
    Patient inna = { 0 };
    inna.Name = "inna gefen";
    strcpy(&inna.ID, "12345678");
    inna.Allergies = 0x0;

    pTree* tree = malloc(sizeof(pTree));
    PatientinitBST(tree);
    PatientinsertBST(tree, inna);
    PatientprintBST(tree);
#endif // PATIENTTEST

    //this is a testcc
}
