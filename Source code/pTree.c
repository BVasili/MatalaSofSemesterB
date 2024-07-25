#include "pTree.h"
#include<stdlib.h>

void insertPInTree(pInTree* root, Patient PatientToBeInserted)
{
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) == 0) return;//no duplicates
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) < 0)
	{
		if (root->left == NULL)//no left child
			root->left = createPInTree(NULL, NULL, PatientToBeInserted);
		else insertPInTree(root->left, PatientToBeInserted);
	}
	else
	{
		if (root->right == NULL)//no right child
			root->right = createPInTree(NULL,NULL,PatientToBeInserted);
		else insertPInTree(root->right, PatientToBeInserted);
	}
}

void freeTree(pInTree* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	destroyStack(root->tpatient.Visits);
	free(root);
}

pInTree* createPInTree(pInTree* left, pInTree* right, Patient PatientToBeInserted)
{
	pInTree* newPInTree = calloc(1, sizeof(pInTree));
	if (newPInTree != NULL)
	{
		newPInTree->tpatient = PatientToBeInserted;
		newPInTree->left = left;
		newPInTree->right = right;
	}
	return newPInTree;
}

int searchInTree(pInTree* root, char* ID)
{
	if (root == NULL) return 0;
	if (strcmp(root->tpatient.ID, ID) == 0) return 1;
	if (strcmp(root->tpatient.ID, ID) < 0) return searchInTree(root->right, ID);
	else return searchInTree(root->left, ID);
}

void initializePTree(pTree* tree)
{
	tree->root = NULL;
}

void insertPTree(pTree* tree, Patient PatientToBeInserted)
{
	if (isPTreeEmpty(tree))
	{
		tree->root = createPInTree(NULL, NULL, PatientToBeInserted);
		return;
	}

	insertPInTree(tree->root, PatientToBeInserted);
}

void destroyPTree(pTree* tree)
{
	freeTree(tree->root);
	tree->root = NULL;
}

int find(pTree* tree, char* ID)
{
	return searchInTree(tree->root, ID);
}

int isPTreeEmpty(pTree* tree)
{
	return tree->root == NULL;
}

void printPInTree(pInTree* root)
{
	
	if (root != NULL) {
		// Traverse the left subtree
		
		printPInTree(root->left);

		// Print the root node's id
		printf("Name: %s  ID: %s\n", root->tpatient.Name, root->tpatient.ID);

		// Traverse the right subtree
		printPInTree(root->right);
	}

}

void printPTree(pTree* tree)
{
	printf("Patients in BST:\n");
	if (tree != NULL)
		return printPInTree(tree->root);
}

pInTree* searchPatientInTree(pInTree* root, char* ID)
{
	if (root == NULL) return NULL;
	if (strcmp(root->tpatient.ID, ID) == 0) return root;
	if (strcmp(root->tpatient.ID, ID) < 0)
		return searchPatientInTree(root->right, ID);
	else return searchPatientInTree(root->left, ID);
}

pInTree* searchPatient(pTree* tree, char* ID)
{
	return searchPatientInTree(tree->root, ID);
}

