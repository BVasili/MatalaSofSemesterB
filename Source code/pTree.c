#include "pTree.h"
#include<stdlib.h>

//inserts patients pInTree into tree according to ID value
void insertPInTree(pInTree* root, Patient PatientToBeInserted)
{
	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) == 0) return;// returns if there are duplicates

	if (strcmp(PatientToBeInserted.ID, root->tpatient.ID) < 0) //goes to left branch if ID value is smaller else it goes right
	{
		if (root->left == NULL)//no left child node
			root->left = createPInTree(NULL, NULL, PatientToBeInserted);
		else insertPInTree(root->left, PatientToBeInserted);
	}
	else
	{
		if (root->right == NULL)//no right child node
			root->right = createPInTree(NULL,NULL,PatientToBeInserted);
		else insertPInTree(root->right, PatientToBeInserted);
	}
}

//frees tree recursivly
void freeTree(pInTree* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	destroyStack(root->tpatient.Visits); //before it deletes the node is also destorys stack thats within the patients sturct
	free(root);
}

//create new pInTree*
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

//sets root to NULL
void initializePTree(pTree* tree)
{
	tree->root = NULL; //sets root to NULL
}

//ADT for insertPInTree
void insertPTree(pTree* tree, Patient PatientToBeInserted)
{
	if (isPTreeEmpty(tree)) 
	{ //if tree is empty then it has no children -- so sad
		tree->root = createPInTree(NULL, NULL, PatientToBeInserted); 
		return;
	}

	insertPInTree(tree->root, PatientToBeInserted); //else it inserts it regulary 
}
//destory tree
void destroyPTree(pTree* tree)
{  // frees tree - calls for recursive function and then sets root to NULL
	freeTree(tree->root);
	tree->root = NULL;
}

int searchInTree(pInTree* root, char* ID) // maybe will be deletd
{
	if (root == NULL) return 0;
	if (strcmp(root->tpatient.ID, ID) == 0) return 1;
	if (strcmp(root->tpatient.ID, ID) < 0) return searchInTree(root->right, ID);
	else return searchInTree(root->left, ID);
}


int find(pTree* tree, char* ID) // maybe delete?
{
	return searchInTree(tree->root, ID);
}
int isPTreeEmpty(pTree* tree)
{ // Return 1 if its empty, else 0
	return tree->root == NULL;
}

//prints patients recursivly
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

//ADT for function above
void printPTree(pTree* tree)
{
	printf("Patients in BST:\n");
	if (tree != NULL)
		return printPInTree(tree->root);
}


pInTree* searchPatientInTree(pInTree* root, char* ID)
{ // Returns a pointer to a node with the wanted patients structure, if not found  - returns NULL.
	if (root == NULL) return NULL;
	if (strcmp(root->tpatient.ID, ID) == 0) return root;
	if (strcmp(root->tpatient.ID, ID) < 0)
		return searchPatientInTree(root->right, ID);
	else return searchPatientInTree(root->left, ID);
}

pInTree* searchPatient(pTree* tree, char* ID)
{ // Just ADT to function above ^^^^
	return searchPatientInTree(tree->root, ID);
}

//
void printDoctorsPatient(pInTree* root,char* DoctorName)
{// Prints Patients info with ONGOING visit of a certain doctor
 
	if (root != NULL) {
		// Traverse the left subtree

		printDoctorsPatient(root->left, DoctorName);

		// Print the root node's id
		Patient TempPatient = root->tpatient;
		Visit TempVisit = peekStack(TempPatient.Visits);

		if (!strcmp(TempVisit.Doctor, DoctorName) && TempVisit.Duration == -1.0) {
			printf("Name: %s  ID: %s\n", root->tpatient.Name, root->tpatient.ID);
			printVisit(TempVisit);
		}
		
		// Traverse the right subtree
		printDoctorsPatient(root->right, DoctorName);
	}

}

void printDoctorsPatientADT(pTree* Tree, char* DoctorName)
{ //ADT for function above^^^
	return printDoctorsPatient(Tree->root, DoctorName);
}


// function to delete a node with a specific ID from the tree
pInTree* deletePInTree(pInTree* root, char* ID) {
	if (root == NULL) {
		return root;
	}

	// go through the tree to find the node to delete
	if (strcmp(ID, root->tpatient.ID) < 0) {
		root->left = deletePInTree(root->left, ID);
	}
	else if (strcmp(ID, root->tpatient.ID) > 0) {
		root->right = deletePInTree(root->right, ID);
	}
	else {
		// node found
		if (root->left == NULL) {
			pInTree* temp = root->right;
			destroyStack(root->tpatient.Visits); // destroy the patients visit stack
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			pInTree* temp = root->left;
			destroyStack(root->tpatient.Visits); // destroy the patients visit stack
			free(root);
			return temp;
		}

		// if node with two children  -- (:
		pInTree* temp = findMin(root->right);

		// copy to the node
		root->tpatient = temp->tpatient;

		// delete the node
		root->right = deletePInTree(root->right, temp->tpatient.ID);
	}
	return root;
}

// helper function to find the minimum value node in the tree
pInTree* findMin(pInTree* node) {
	pInTree* current = node;
	while (current && current->left != NULL) {
		current = current->left;
	}
	return current;
}

// ADT for delete function
void deletePTree(pTree* tree, char* ID) {
	tree->root = deletePInTree(tree->root, ID);
}
