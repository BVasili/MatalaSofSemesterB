#pragma once
#ifndef AUXILIARY_FUNCTIONS_HEADER__
#define AUXILIARY_FUNCTIONS_HEADER__
#include "BST.h"
#include "Structure.h"
#define _CRT_SECURE_NO_WARNINGS
#define NAME_SIZE 100
#define LINE_SIZE 100
#define SUMAMRY_SIZE 100
#define ALLERGY_SIZE 8
#define ALLERGY_MAX_NAME_SIZE 15
#define LISENSE_SIZE 7

//#define ID_SIZE 10


//loadLine
//updatefiles
//searchPatient
//displayError
//case2assignDoctor
int printMenu(void);
pInTree* loadPatients();
NodeDoc* loadDoctors();//return the head of the list of the doctors
#endif // AUXILIARY_FUNCTIONS_HEADER__