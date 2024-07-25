#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#include"Structure.h"
#include"SLL.h"
#include"Stack.h"
#include"pLine.h"
#include"pTree.h"
#include"displayError.h"
char* TranslateBitWiseIntoString(Patient*);
void InsertPatientsTreeToFile(FILE*, pInTree*, int*);
void writePatientToFile(FILE*, pInTree*, int*);
void updateFiles(char*, char*, char*, List*, pLine*, pTree*);
