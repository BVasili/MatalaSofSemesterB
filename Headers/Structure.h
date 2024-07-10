#define ID_SIZE 8
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

typedef struct Patient
{
    char *Name;
    char ID[ID_SIZE];
    char Allergies[ID_SIZE];
} Patient;
