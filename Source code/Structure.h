﻿#pragma once
#ifndef STRUCTURE_HEADER__
#define STRUCTURE_HEADER__

#define ID_SIZE 10
#define AllergiesSize 8

//Define for allergies
#define NONE           0b00000000
#define PENICILLIN     0b00000001
#define SULFA          0b00000010
#define OPIOIDS        0b00000100
#define ANESTHETICS    0b00001000
#define EGGS           0b00010000
#define LATEX          0b00100000
#define PRESERVATIVES  0b01000000



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


// i needed a linked list for the doctors so i had to add this sturct
typedef struct NodeDoc
{
	Doc doctor;
	struct NodeDoc* next;
}NodeDoc;


#endif // STRUCTURE_HEADER__