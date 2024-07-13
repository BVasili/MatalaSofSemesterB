#pragma once

#define NAME_SIZE 100
#define ID_SIZE 10
#define AllergiesSize 8

//Define for allergies
#define none           0b00000000
#define Penicillin     0b00000001
#define Sulfa          0b00000010
#define Opioids        0b00000100
#define Anesthetics    0b00001000
#define Eggs           0b00010000
#define Latex          0b00100000
#define Preservatives  0b01000000


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
	int number;//only for now until stack is in order
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
	char Allergies/*[AllergiesSize]*/;
	/*Stack* Visits;*/
	int nVisits;
} Patient;
