#pragma once
#ifndef __MY_QUEUE_HEADER_
#define __MY_QUEUE_HEADER_

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

#endif // !__MY_QUEUE_HEADER_
