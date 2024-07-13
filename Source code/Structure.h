#pragma once
#ifndef STRUCTURE_HEADER__
#define STRUCTURE_HEADER__

#define ID_SIZE 8
#define AllergiesSize 8

//Define for allergies
#define none           0x0
#define Penicillin     0x1
#define Sulfa          0x2
#define Opioids        0x3
#define Anesthetics    0x4
#define Eggs           0x5
#define Latex          0x6
#define Preservatives  0x7

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