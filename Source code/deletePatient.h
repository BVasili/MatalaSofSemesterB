#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "displayError.h"
#include "goToFunction.h"
#include "pLine.h"
#include "SLL.h"
#include "Stack.h"
#include "Structure.h"
#ifndef DELETEPATIENTS__
#define DELETEPATIENTS__
void deletePatient(pLine* PatientsLine, pTree* PatientsTree, List* DoctorsList);
#endif //DELETEPATIENTS__