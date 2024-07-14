#pragma once
#ifndef STRUCTURE_HEADER__
#define STRUCTURE_HEADER__

#define ID_SIZE 10
#define AllergiesSize 8

//Define for allergies
#define NONE           0b0000
#define PENICILLIN     0b0001
#define SULFA          0b0010
#define OPIOIDS        0b0011
#define ANESTHETICS    0b0100
#define EGGS           0b0101
#define LATEX          0b0110
#define PRESERVATIVES  0b0111



typedef struct Date
{
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	unsigned int Hour;
	unsigned int Min;
} Date;

typedef struct Doc
{
	char* Name;
	char nLicense[ID_SIZE];
	int nPatients;
} Doc;


typedef struct Visit
{
	Date tArrival;
	Date tDismissed;
	float Duration;
	Doc* Doctor;
	char* vSummary;
} Visit;


typedef struct Node
{
	int data;
	Visit Visit;
	struct Node* next;
}Node;


typedef struct List
{
	Node* head;
	Node* tail;
} List;

typedef struct Stack
{
	List sList;
	int size;
}Stack;

typedef struct Patient
{
	char* Name;
	char ID[ID_SIZE];
	char Allergies;
	Stack* Visits;
	int nVisits;
}Patient;

#endif // STRUCTURE_HEADER__