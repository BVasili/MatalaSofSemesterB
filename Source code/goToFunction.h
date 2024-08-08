#pragma once

#ifndef GOTOFUNCTION__
#define GOTOFUNCTION__
#define _CRT_SECURE_NO_WARNINGS

#include"SLL.h"
#include"pLine.h"
#include"pTree.h"
#include"Stack.h"
#include"updateFiles.h"
#include "admitPatient.h"
#include "removeVisit.h"
#include "DischargePatient.h"

void goToFunc(int, List*, pLine*, pTree*);
void CheckForPatientsAllergies(pLine*);
void DisplayAllPatientsAdmissions(pLine*);
void AdvancePatientInLine(pLine*);
void DisplayAllPatientsAssignedToADoctor(List*, pLine*);
void deletePatient(List*, pLine*, pTree*);
#endif // !GOTOFUNCTION__

