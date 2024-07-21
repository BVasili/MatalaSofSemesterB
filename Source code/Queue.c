#include "Queue.h"

void initQueue(Queue *q)
{
	initList(&(q->qList));
	q->size = 0;
}

void destroyQueue(Queue *q)
{
	destroyList(&(q->qList));
	q->size = 0;
}

void enqueue(Queue *q, int data)
{
	addToTail(&(q->qList), data);
	q->size++;
}

int dequeue(Queue *q)
{
	q->size--;
	return removeFromHead(&(q->qList));
}

int peekQueue(const Queue *q)
{
	return peekList(&(q->qList));
}

int isEmptyQueue(const Queue *q)
{
	return isEmptyList(&(q->qList));
}

void printQueue(const Queue *q)
{
	printf("Head of Queue| ");
	printList(&(q->qList), " | ");
	printf(" |Tail of Queue\n\n");
}

int getQueueSize(const Queue *q)
{
	return q->size;
}


///////// line

void initLine(pLine* q)
{
	initList(&(q->qList));
	q->size = 0;
}

void destroyLine(pLine* q)
{
	destroyList(&(q->qList));
	q->size = 0;
}

void enLine(pLine* q, int data)
{
	addToTail(&(q->qList), data);
	q->size++;
}

int deLine(pLine* q)
{
	q->size--;
	return removeFromHead(&(q->qList));
}

int peekLine(const pLine* q)
{
	return peekList(&(q->qList));
}

int isEmptyLine(const pLine* q)
{
	return isEmptyList(&(q->qList));
}

void printLine(const pLine* q)
{
	printf("Head of Queue| ");
	printList(&(q->qList), " | ");
	printf(" |Tail of Queue\n\n");
}

int getLineSize(const pLine* q)
{
	return q->size;
}



