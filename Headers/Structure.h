#define ID_SIZE 8
#define AllergiesSize 8
typedef struct Date
{
    unsigned int Year;
    unsigned int Month;
    unsigned int Day;
    unsigned int Hour;
    unsigned int Min;
} Date;

typedef struct Doc
{
    char *Name;
    char nLicense[ID_SIZE];
    int nPatients;
} Doc;

typedef struct Visit
{
    Date tArrival;
    Date tDismissed;
    float Duration;
    Doc *Doctor;
    char *vSummary;
} Visit;

// to be changed
typedef struct Node
{
    Visit VisitData;
    struct Node* next;
}Node;


typedef struct List
{
    Node* head;
} List;

typedef struct Stack
{
    List sList;
    int size;
}Stack;

// until here

typedef struct Patient
{
    char *Name;
    char ID[ID_SIZE];
    char Allergies[AllergiesSize];
    Stack* Visits;
    int nVisits;
} Patient;
