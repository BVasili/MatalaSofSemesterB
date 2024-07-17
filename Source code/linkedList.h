#pragma once
#include "Structure.h"


void freeList(NodeDoc* head);
void PrintDocList(NodeDoc* head);

NodeDoc* createNode(Doc* doctor, NodeDoc* next);
NodeDoc* addFirst(Doc* doctor, NodeDoc* head);
NodeDoc* addSorted(Doc* doctor, NodeDoc* head);