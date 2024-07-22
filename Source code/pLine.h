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

#endif //PLINE_HEADER__