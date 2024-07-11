#pragma once

#define ID_SIZE 8
#define AllergiesSize 8

//Define for allergies
#define NONE 00000000
#define PENICILLIN 00000001
#define SULFA 00000010
#define OPIOIDS 00000100
#define ANESTHETICS 00001000
#define EGGS 00010000
#define LATEX 00100000
#define PRESERVATIVES 01000000

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
	char Allergies[AllergiesSize];
	Stack* Visits;
	int nVisits;
}Patient;
