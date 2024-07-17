#pragma once
#include "Structure.h"
#include "Structure.h"

void freeList(NodeDoc* head);
void printList(NodeDoc* head);

NodeDoc* createNode(Doc* doctor, NodeDoc* next);
NodeDoc* addFirst(Doc* doctor, NodeDoc* head);
NodeDoc* addLast(Doc* doctor, NodeDoc* head);

