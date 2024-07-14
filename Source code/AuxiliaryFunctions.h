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
#define AllergiesSize 8
char getAllergyBit(const char* allergy);
//loadDoctors
//loadLine
//updatefiles
//searchPatient
//displayError
//case2assignDoctor
int printMenu(void);
pInTree* loadPatients();

#endif // AUXILIARY_FUNCTIONS_HEADER__