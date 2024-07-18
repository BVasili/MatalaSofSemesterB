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

///////////////////////////////////////////////

void Line_initQueue(Queue* q)
{
	initList(&(q->qList));
	q->size = 0;
}

void Line_destroyQueue(Queue* q)
{
	destroyList(&(q->qList));
	q->size = 0;
}

void Line_enqueue(Queue* q,Patient* Ptr2Patient)
{
	Line_addToTail(&(q->qList), Ptr2Patient);
	q->size++;
}

Patient* Line_dequeue(Queue* q)
{
	q->size--;
	return Line_removeFromHead(&(q->qList));
}

Patient* Line_peekQueue(const Queue* q)
{
	return Line_peekList(&(q->qList));
}

int Line_isEmptyQueue(const Queue* q)
{
	return Line_isEmptyList(&(q->qList));
}

void Line_printQueue(const Queue* q)
{
	printf("Head of Queue|\n ");
	Line_printList(&(q->qList), " | ");
	printf(" |Tail of Queue\n\n");
}

int Line_getQueueSize(const Queue* q)
{
	return q->size;
}


