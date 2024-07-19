#pragma once
#ifndef AUXILIARY_FUNCTIONS_HEADER__
#define AUXILIARY_FUNCTIONS_HEADER__
#include "BST.h"
#include "Structure.h"
#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"

#define NAME_SIZE 100
#define LINE_SIZE 100
#define SUMAMRY_SIZE 100
#define ALLERGY_SIZE 8
#define ALLERGY_MAX_NAME_SIZE 15
#define ALLOCATION_FAILED 1
#define CANNOT_OPEN_FILE 2
#define LICENSE_SIZE 7
//#define ID_SIZE 10


//loadLine
//updatefiles
//case2assignDoctor

pInTree* searchPatient(pTree*, char*);
void displayError(int);
int printMenu(void);
pTree* loadPatients();
NodeDoc* loadDoctors();
NodeDoc* assignDoc2Case(NodeDoc*);
NodeDoc* removeNode(NodeDoc* head, NodeDoc* node);
NodeDoc* insertSorted(NodeDoc* head, NodeDoc* node);
void goToFunc(int choice, NodeDoc* head);
//return the head of the list of the doctors
#endif // AUXILIARY_FUNCTIONS_HEADER__