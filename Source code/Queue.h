#pragma once
#ifndef QUEUE_HEADER__
#define QUEUE_HEADER__

#include "SLL.h"

typedef struct Queue
{
	List qList;
	int size;
}Queue;


void initQueue(Queue* q);
void destroyQueue(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peekQueue(const Queue* q);
int isEmptyQueue(const Queue* q);
void printQueue(const Queue* q);
int getQueueSize(const Queue* q);

void Line_initQueue(Queue* q);
void Line_destroyQueue(Queue* q);
void Line_enqueue(Queue* q, Patient Patient);
Patient  Line_dequeue(Queue* q);
Patient Line_peekQueue(const Queue* q);
int  Line_isEmptyQueue(const Queue* q);
void Line_printQueue(const Queue* q);
int  Line_getQueueSize(const Queue* q);

#endif // QUEUE_HEADER__
