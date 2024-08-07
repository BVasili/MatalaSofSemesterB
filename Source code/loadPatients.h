#pragma once
#include "Structure.h"
#include "displayError.h"
#include "Stack.h"
#include "pTree.h"

#define ID_SIZE 10
#define NAME_SIZE 100
#define LINE_SIZE 100
#define SUMAMRY_SIZE 100
#define ALLERGY_SIZE 8
#define ALLERGY_MAX_NAME_SIZE 15

void loadPatients(pTree*,char*,List*);