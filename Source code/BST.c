#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BST.h"
#include "TreePrintLibrary.h"


#define FALSE 0
#define TRUE 1

bst_node* createBstNode(bst_node* left, bst_node* right, int key)
{
	bst_node* newNode = calloc(1, sizeof(bst_node));
	if (newNode != NULL)
	{
		newNode->key = key;
		newNode->left = left;
		newNode->right = right;
		newNode->parent = NULL;
	}

	return newNode;
}

void insertNode(bst_node* root, int toInsert)
{
	if (toInsert == root->key) return;//no duplicates
	if (toInsert < root->key)
	{
		if (root->left == NULL)//no left child
		{
			root->left = createBstNode(NULL, NULL, toInsert);
			root->left->parent = root;
		}
		else insertNode(root->left, toInsert);
	}
	else
	{
		if (root->right == NULL)//no right child
		{
			root->right = createBstNode(NULL, NULL, toInsert);
			root->right->parent = root;
		}
		else insertNode(root->right, toInsert);
	}
}

void freeTree(bst_node* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

void initBST(BST* tree)
{
	tree->root = NULL;
}


void insertBST(BST* tree, int toInsert)
{
	if (isBstEmpty(tree))
	{
		tree->root = createBstNode(NULL, NULL, toInsert);
		return;
	}

	insertNode(tree->root, toInsert);
}

void destroyBST(BST* tree)
{
	freeTree(tree->root);
}

int find(BST* tree, int toFind);

int isBstEmpty(BST* tree)
{
	return tree->root == NULL;
}

void printBST(BST* tree)
{
	//print_ascii_tree(tree->root);
}

int find(BST* tree, int toFind)
{
	return searchInTree(tree->root, toFind);
}

int searchInTree(bst_node* root, int toFind)
{
	if (root == NULL) return FALSE;
	if (root->key == toFind) return TRUE;
	if (root->key < toFind) return searchInTree(root->right, toFind);
	else return searchInTree(root->left, toFind);
}
void printParent(BST* tree, int child)
{
	BST* temp = tree;
	if (temp->root->parent == NULL && temp->root->key == child)
	{
		printf("%d's father is NULL\n", child);
	}
	if (temp->root->key > child)//left
	{
		printParent(&temp->root->left, child);
	}
	if (temp->root->key < child)//right 
	{
		printParent(&temp->root->right, child);
	}
	if (temp->root->key == child && temp->root->parent != NULL)
	{
		printf("%d's father is %d\n", child, temp->root->parent->key);//print
	}
}

 //functions for Patient 

pInTree* Patient_createBstNode(pInTree* left, pInTree* right, Patient PatientToBeInserted)
{
	pInTree* newNode = calloc(1, sizeof(pInTree));
	if (newNode != NULL)
	{
		newNode->tpatient = PatientToBeInserted;
		newNode->left = left;
		newNode->right = right;
	}
	return newNode;
}

void Patient_insertNode(pInTree* root, Patient PatientToBeInserted)
{
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) == 0) return;//no duplicates
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) < 0)
	{
		if (root->left == NULL)//no left child
			root->left = Patient_createBstNode(NULL, NULL, PatientToBeInserted);
		else Patient_insertNode(root->left, PatientToBeInserted);
	}
	else
	{
		if (root->right == NULL)//no right child
			root->right = Patient_createBstNode(NULL, NULL, PatientToBeInserted);
		else Patient_insertNode(root->right, PatientToBeInserted);
	}
}

void Patient_freeTree(pInTree* root)
{
	if (root == NULL) return;
	Patient_freeTree(root->left);
	Patient_freeTree(root->right);
	free(root);
}

void Patient_initializeBST(pTree* tree)
{
	tree->root = NULL;
}

void Patient_insertBST(pTree* tree, Patient PatientToBeInserted)
{
	if (Patient_BstEmpty(tree))
	{
		tree->root = Patient_createBstNode(NULL, NULL, PatientToBeInserted);
		return;
	}

	Patient_insertNode(tree->root, PatientToBeInserted);
}

void Patient_destroyBST(pTree* tree)
{
	Patient_freeTree(tree->root);
}

int Patient_BstEmpty(pTree* tree)
{
	return tree->root == NULL;
}

void Patient_printBST(pInTree* node) {
	if (node != NULL) {
		// Traverse the left subtree
		Patient_printBST(node->left);

		// Print the root node's id
		printf("%s\n", node->tpatient.ID);

		// Traverse the right subtree
		Patient_printBST(node->right);
	}
}


void Patient_PrintTree(pTree* tree) {
	if (tree != NULL) {
		Patient_printBST(tree->root);
	}
}

int Patient_find(pTree* tree, char* ID)
{
	return Patient_searchInTree(tree->root, ID);
}

int Patient_searchInTree(pInTree* root,char* ID)
{
	if (root == NULL) return FALSE;
	if (strcmp(root->tpatient.ID, ID) == 0) return TRUE;
	if (strcmp(root->tpatient.ID, ID) <0) return Patient_searchInTree(root->right, ID);
	else return Patient_searchInTree(root->left, ID);
}

pInTree* searchPatientInTree(pInTree* root, char* ID)
{
	if (root == NULL) return NULL;
	if (strcmp(root->tpatient.ID, ID) == 0) return root;
	if (strcmp(root->tpatient.ID, ID) < 0)
		return searchPatientInTree(root->right, ID);
	else return searchPatientInTree(root->left, ID);
}
