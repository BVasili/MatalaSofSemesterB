#pragma once
#ifndef PTREE_HEADER__
#define PTREE_HEADER__
#include"Structure.h"
#include"Stack.h"
struct pInTree;

// Typedef for tree node
typedef struct pInTree
{
	Patient tpatient;
	struct pInTree* left;
	struct pInTree* right;
} pInTree;

// Typedef for tree
typedef struct pTree
{
	pInTree* root;
} pTree;

//
void insertPInTree(pInTree* root, Patient PatientToBeInserted);
void freeTree(pInTree* root);
pInTree* createPInTree(pInTree* left, pInTree* right, Patient PatientToBeInserted);
pInTree* searchPatientInTree(pInTree*, char*);

//ADT functions
pInTree* searchPatient(pTree* tree, char* ID);
int searchInTree(pInTree* root, char*);
void initializePTree(pTree* tree);
void insertPTree(pTree* tree, Patient PatientToBeInserted);
void destroyPTree(pTree* tree);
int find(pTree* tree, char*);
int isPTreeEmpty(pTree* tree);
void printPInTree(pInTree* root);
void printPTree(pTree* tree);
void printDoctorsPatient(pInTree*, char*);
void printDoctorsPatientADT(pTree*, char*);
pInTree* searchPatientInTree(pInTree*, char*);


#endif //PTREE_HEADER__
