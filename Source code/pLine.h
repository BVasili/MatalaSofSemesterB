#pragma once
#ifndef PLINE_HEADER__
#define PLINE_HEADER__
#include "pTree.h"

typedef struct pInLine pInLine;

typedef struct pInLine
{
    Patient* lpatient;
    pInLine* next;
}pInLine;

typedef struct pLine
{
    pInLine* head;
    pInLine* tail;
    int size;
}pLine;



void deletePLine(pLine* ToBeDeleted);

void AddToTailLine(pLine* q, char* ID, pTree* tree);

Patient* RemoveHeadFromLine(pLine* q);

Patient GetFromHead(const pLine* q);

int CheckLineHead(const pLine* q);

void printLineADT(const pLine* q);

void initLine(pLine* q);

void enLine(pLine* q, char* ID, pTree* tree);

Patient* deLine(pLine* q);

void destroyLine(pLine* q);

Patient peekLine(const pLine* q);

int isEmptyLine(const pLine* q);

void printLine(const pLine* q);

int getLineSize(const pLine* q);

#endif //PLINE_HEADER__