#pragma once
#define CRT_SECURE_NO_WARNINGS
#include "SLL.h"
#include "assignDoctor2case.h"
#include "pLine.h"

void insertNewPatientInfo(char*, List*, pLine*, pTree*);
void insertExisPatient(char* id_str, List* doctors, pLine* PatientsLine, pTree* PatientsTree);
int validInput(char* , char* );
void admitPatient(List*, pLine*, pTree*);

