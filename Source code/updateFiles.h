#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#include"Structure.h"
#include"SLL.h"
#include"Stack.h"
#include"pLine.h"
#include"pTree.h"
#include"displayError.h"

void updateFiles(char*, char*, char*, List*, pLine*, pTree*);
void writePatientQueueToFile(FILE* file, pLine* queue);
void writeDoctorsToFile(FILE* file, List* doctorList);
void writePatientToFile(FILE* file, Patient* patient, int index);
void writePatientsFromTree(FILE* file, pInTree* node, int* index);
