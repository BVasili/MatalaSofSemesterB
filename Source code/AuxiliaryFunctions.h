#pragma once
#ifndef AUXILIARY_FUNCTIONS_HEADER__
#define AUXILIARY_FUNCTIONS_HEADER__

#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"

#define NAME_SIZE 100
#define LINE_SIZE 100
#define SUMAMRY_SIZE 100
#define ALLERGY_SIZE 8
#define ALLERGY_MAX_NAME_SIZE 15
#define ALLOCATION_FAILED 1
#define CANNOT_OPEN_FILE 2

//#define ID_SIZE 10

//loadDoctors
//loadLine
//updatefiles
//case2assignDoctor

pInTree* searchPatient(pTree*, char*);
void displayError(int);
int printMenu(void);
pTree* loadPatients();

#endif // AUXILIARY_FUNCTIONS_HEADER__