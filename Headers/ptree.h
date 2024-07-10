#include "Structure.h"

typedef struct pInTree
{
    Patient tpatient;
    pInTree *left;
    pInTree *right;
} pInTree;
typedef struct pTree
{
    pInTree *root;
} pTree;
