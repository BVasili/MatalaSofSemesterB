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

pInTree* PatientcreateBstNode(pInTree* left, pInTree* right, Patient PatientToBeInserted)
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

void PatientinsertNode(pInTree* root, Patient PatientToBeInserted)
{
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) == 0) return;//no duplicates
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) < 0)
	{
		if (root->left == NULL)//no left child
			root->left = PatientcreateBstNode(NULL, NULL, PatientToBeInserted);
		else PatientinsertNode(root->left, PatientToBeInserted);
	}
	else
	{
		if (root->right == NULL)//no right child
			root->right = PatientcreateBstNode(NULL, NULL, PatientToBeInserted);
		else PatientinsertNode(root->right, PatientToBeInserted);
	}
}

void PatientfreeTree(pInTree* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

void PatientinitBST(pTree* tree)
{
	tree->root = NULL;
}

void PatientinsertBST(pTree* tree, Patient PatientToBeInserted)
{
	if (PatientisBstEmpty(tree))
	{
		tree->root = PatientcreateBstNode(NULL, NULL, PatientToBeInserted);
		return;
	}

	PatientinsertNode(tree->root, PatientToBeInserted);
}

void PatientdestroyBST(pTree* tree)
{
	freeTree(tree->root);
}

int PatientisBstEmpty(pTree* tree)
{
	return tree->root == NULL;
}

void PatientprintBST(pTree* tree)
{
	if (tree != NULL) {
		// Traverse the left subtree
		PatientprintBST(tree->root->left);

		// Print the root node's id
		printf("%s\n", tree->root->tpatient.ID);

		// Traverse the right subtree
		PatientprintBST(tree->root->right);
	}
}

int Patientfind(pTree* tree, char* ID)
{
	return PatientsearchInTree(tree->root, ID);
}

int PatientsearchInTree(pInTree* root,char* ID)
{
	if (root == NULL) return FALSE;
	if (strcmp(root->tpatient.ID, ID) == 0) return TRUE;
	if (strcmp(root->tpatient.ID, ID) <0) return PatientsearchInTree(root->right, ID);
	else return PatientsearchInTree(root->left, ID);
}

