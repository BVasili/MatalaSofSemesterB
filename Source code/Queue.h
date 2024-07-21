#pragma once
#ifndef QUEUE_HEADER__
#define QUEUE_HEADER__

#include "SLL.h"

typedef struct Queue
{
	List qList;
	int size;
}Queue;

typedef struct pInLine {
	Patient* lpatient;
	pInLine* next;
}pInLine;

typedef struct pLine {
	pInLine* head;
	int size;
};

void initQueue(Queue* q);
void destroyQueue(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peekQueue(const Queue* q);
int isEmptyQueue(const Queue* q);
void printQueue(const Queue* q);
int getQueueSize(const Queue* q);


#endif // QUEUE_HEADER__
