#pragma once
#ifndef BST_HEADER__
#define BST_HEADER__
#include"Structure.h"
// Forward declaration


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


#endif // !_BST_HEADER__
