#pragma once
#ifndef AUXILIARY_FUNCTIONS_HEADER__
#define AUXILIARY_FUNCTIONS_HEADER__
#include "BST.h"
#define _CRT_SECURE_NO_WARNINGS
#define NAME_SIZE 100
#define LINE_SIZE 100
#define SUMAMRY_SIZE 100
#define ALLERGY_SIZE 8
#define ALLERGY_MAX_NAME_SIZE 15

//#define ID_SIZE 10

//loadDoctors
//loadLine
//updatefiles

//displayError
//case2assignDoctor
int printMenu(void);
pTree* loadPatients();
pInTree* searchPatient(pTree*, char*);
#endif // AUXILIARY_FUNCTIONS_HEADER__