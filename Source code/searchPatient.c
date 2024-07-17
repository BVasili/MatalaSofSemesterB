#include"searchPatient.h"

// This is in bst.c
//pInTree* searchPatientInTree(pInTree* root, char* ID)
//{
//	if (root == NULL) return NULL;
//	if (strcmp(root->tpatient.ID, ID) == 0) return root;
//	if (strcmp(root->tpatient.ID, ID) < 0)
//		return searchPatientInTree(root->right, ID);
//	else return searchPatientInTree(root->left, ID);
//}

pInTree* searchPatient(pTree* tree, char* ID)
{
	return searchPatientInTree(tree->root, ID);
}