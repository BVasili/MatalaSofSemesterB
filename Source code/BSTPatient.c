#include"BSTPatient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
	tree->root = NULL;
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

int Patient_searchInTree(pInTree* root, char* ID)
{
	if (root == NULL) return FALSE;
	if (strcmp(root->tpatient.ID, ID) == 0) return TRUE;
	if (strcmp(root->tpatient.ID, ID) < 0) return Patient_searchInTree(root->right, ID);
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
