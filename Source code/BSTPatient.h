#include "Structure.h"

#ifndef BSTPATIENT_H
#define BSTPATIENT_H

// Forward declaration
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


//functions for Patient
void Patient_insertNode(pInTree* root, Patient PatientToBeInserted);
void Patient_freeTree(pInTree* root);
pInTree* Patient_createBstNode(pInTree* left, pInTree* right, Patient PatientToBeInserted);

int Patient_searchInTree(pInTree* root, char*);
void Patient_initializeBST(pTree* tree);
void Patient_insertBST(pTree* tree, Patient PatientToBeInserted);
void Patient_destroyBST(pTree* tree);
int Patient_find(pTree* tree, char*);
int Patient_BstEmpty(pTree* tree);
void Patient_printBST(pInTree* root);
void Patient_PrintTree(pTree* tree);
pInTree* searchPatientInTree(pInTree*, char*);

#endif // BSTPATIENT_H
