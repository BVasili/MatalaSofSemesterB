#pragma once
#ifndef BST_HEADER__
#define BST_HEADER__

#include "Structure.h"

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

typedef struct bst_node
{
	struct bst_node* left;
	struct bst_node* right;
	int key;
	struct bst_node* parent;
}bst_node;

//Admin struct for a BST ADT
typedef struct binary_search_tree
{
	bst_node* root;
}BST;
//functions for int
void insertNode(bst_node* root, int toInsert);
void freeTree(bst_node* root);
bst_node* createBstNode(bst_node* left, bst_node* right, int key);
int searchInTree(bst_node* root, int toFind);
void initBST(BST* tree);
void insertBST(BST* tree, int toInsert);
void destroyBST(BST* tree);
int find(BST* tree, int toFind);
int isBstEmpty(BST* tree);
void printBST(BST* tree);
void printParent(BST* tree, int child);

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

#endif // !_BST_HEADER__
