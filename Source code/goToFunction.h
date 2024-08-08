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
void Function2(pLine*);
void Function4(pLine*);
void Function6(pLine*);
void Function8(List*, pLine*);
void deletePatient(List* , pLine* , pTree* );
#endif // !GOTOFUNCTION__

