#pragma once
#include "Structure.h"

typedef struct pInLine
{
    Patient *patient;
    pInLine *next;

} pInLine;

typedef struct pLine
{
    pInLine *head;
} pLine;