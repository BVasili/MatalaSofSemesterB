#include "updateFiles.h"
#include<string.h>

void updateFiles(char* DoctorsFile,char* PatientsFile,char* LineFile, List* DoctorsList, pLine* PatientsLine, pTree* PatientsTree)
{
    char ID[10] = { 0 };
    int index = 0;
    Stack* tempStack1;
    Stack* tempStack2;
    Stack* PatientsVisitStack;
    Visit TempVisit;
    Patient* ptrTempPatient = NULL;
    FILE* ptr2PatientsFile = fopen(PatientsFile, "w");
  
    if (checkPointer(ptr2PatientsFile, CANNOT_OPEN_FILE))
        return;
 
    // Write header for patient file
    fprintf(ptr2PatientsFile, "Name;ID;Allergies\n");
    fprintf(ptr2PatientsFile, "=============================\n");
    for (int i = 0; i <999999999; i++)// a while loop is needed if the amount of intertions is unknown
    {
        itoa(i, ID, 10);
        ptrTempPatient = searchPatient(PatientsTree, ID);

        if (!ptrTempPatient)
            continue;
        
        fprintf(ptr2PatientsFile, "%d.%s;%s;%s\n", index, ptrTempPatient->Name, ptrTempPatient->ID ,/* encodeAllergies(patient->Allergies)*/);

        tempStack1 = malloc(sizeof(Stack));
        if (checkPointer(tempStack1, CANNOT_OPEN_FILE))
            return;
        tempStack2 = malloc(sizeof(Stack));
        if (checkPointer(tempStack2, CANNOT_OPEN_FILE))
            return;
        initStack(tempStack1);
        initStack(tempStack2);

        PatientsVisitStack = ptrTempPatient->Visits;

        while (isEmptyStack(PatientsVisitStack)) {

            TempVisit = pop(PatientsVisitStack);
            push(tempStack1, TempVisit);

            fprintf(ptr2PatientsFile, "Arrival:%02d/%02d/%04d %02d:%02d\n", TempVisit.tArrival.Day, TempVisit.tArrival.Month, TempVisit.tArrival.Year, TempVisit.tArrival.Hour, TempVisit.tArrival.Min);
            // Write dismissed details
            if (visit->tDismissed.Year != -1)
                fprintf(file, "Dismissed:%02d/%02d/%04d %02d:%02d\n", visit->tDismissed.Day, visit->tDismissed.Month, visit->tDismissed.Year, visit->tDismissed.Hour, visit->tDismissed.Min);  
            else
                fprintf(file, "Dismissed:\n");

            // Write duration details
            if (visit->Duration != -1.0)
            {
                fprintf(file, "Duration: %.2f\n", visit->Duration);
            }
            else
            {
                fprintf(file, "Duration:\n");
            }
            // Write doctor details
            if (visit->Doctor != NULL)
            {
                fprintf(file, "Doctor:%s\n", visit->Doctor->Name);
            }
            else
            {
                fprintf(file, "Doctor:\n");
            }
            // Write summary details
            if (visit->vSummery != NULL) {
                fprintf(file, "Summary:%s\n", visit->vSummery);
            }
            else
            {
                fprintf(file, "Summary:\n");
            }
            // Print blank line between visits
            fprintf(file, "\n");
            // Move to the next visit
            currentVisit = currentVisit->next;
        }

            
    }
    fclose(ptr2PatientsFile);



    // Open  doctor file for writing
    FILE* doctorsFile = fopen(doctorsTxt, "w")

    // Check if the file was opened successfully
    if (!doctorsFile)
    {
        // Return if the file could not be opened
        printf("Error opening doctors file for writing.\n");
        return;
    }
    // Write doctors to file
    writeDoctorsToFile(doctorsFile, doctorList);
    // Close the doctors file
    fclose(doctorsFile);

    // Open line file for writing
    FILE* lineFile = fopen(lineTxt, "w");
    // Check if the file was opened successfully
    if (!lineFile)
    {
        // Return if the file could not be opened
        printf("Error opening line file for writing.\n");
        return;
    }
    // Write header for line file
    fprintf(lineFile, "Patients' IDs in line\n");
    fprintf(lineFile, "=====================\n");
    // Write patient queue to file
    writePatientQueueToFile(lineFile, queue);
    // Close the line file
    fclose(lineFile);
}


// Function to write patients from the binary search tree to file
void writePatientsFromTree(FILE* file, pInTree* node, int* index)
{
    // Return if the node is NULL
    if (node == NULL)
    {
        return;
    }
    // Recursively write left subtree
    writePatientsFromTree(file, node->left, index);
    // Write current patient
    writePatientToFile(file, &(node->tpatient), (*index)++);
    // Recursively write right subtree
    writePatientsFromTree(file, node->right, index);
}


// Function to write a single patient's details and visits to file
void writePatientToFile(FILE* file, Patient* patient, int index)
{
    // Write patient details
    fprintf(file, "%d.%s;%s;%s\n", index, patient->Name, patient->ID, encodeAllergies(patient->Allergies));
    // Initialize current visit node
    visitStackNode* currentVisit = patient->visits;
    // Initialize reversed visit stack
    visitStackNode* reversedVisits = NULL;
    // Reverse the visit stack
    while (currentVisit != NULL)
    {
        // Store next visit node
        visitStackNode* nextVisit = currentVisit->next;
        currentVisit->next = reversedVisits;
        // Update reversed visit stack
        reversedVisits = currentVisit;
        // Move to the next visit
        currentVisit = nextVisit;
    }
    // Write visits in the correct order
    // Set current visit to the reversed stack
    currentVisit = reversedVisits;
    while (currentVisit != NULL)
    {
        // Get visit details
        Visit* visit = currentVisit->visit;
        // Write arrival details
        fprintf(file, "Arrival:%02d/%02d/%04d %02d:%02d\n", visit->tArrival.Day, visit->tArrival.Month, visit->tArrival.Year, visit->tArrival.Hour, visit->tArrival.Min);
        // Write dismissed details
        if (visit->tDismissed.Year != -1)
        {
            fprintf(file, "Dismissed:%02d/%02d/%04d %02d:%02d\n", visit->tDismissed.Day, visit->tDismissed.Month, visit->tDismissed.Year, visit->tDismissed.Hour, visit->tDismissed.Min);
        }
        else
        {
            fprintf(file, "Dismissed:\n");
        }
        // Write duration details
        if (visit->Duration != -1.0)
        {
            fprintf(file, "Duration: %.2f\n", visit->Duration);
        }
        else
        {
            fprintf(file, "Duration:\n");
        }
        // Write doctor details
        if (visit->Doctor != NULL)
        {
            fprintf(file, "Doctor:%s\n", visit->Doctor->Name);
        }
        else
        {
            fprintf(file, "Doctor:\n");
        }
        // Write summary details
        if (visit->vSummery != NULL) {
            fprintf(file, "Summary:%s\n", visit->vSummery);
        }
        else
        {
            fprintf(file, "Summary:\n");
        }
        // Print blank line between visits
        fprintf(file, "\n");
        // Move to the next visit
        currentVisit = currentVisit->next;
    }
    // Print separator line
    fprintf(file, "=============================\n");
    // Increment index
    index++;
}

// Function to write the list of doctors to file
void writeDoctorsToFile(FILE* file, List* doctorList)
{
    // Print header for doctors file
    fprintf(file, "Full Name; License Number; Number of Patients\n");
    fprintf(file, "=================================================\n");
    // Initialize current node
    Node* current = doctorList->head;
    // Write doctors details to file
    while (current != NULL)
    {
        fprintf(file, "%s;%s;%d\n", current->Doctor.Name, current->Doctor.nLicense, current->Doctor.nPatients);
        // Move to the next doctor
        current = current->next;
    }
}


// Function to write the patient queue to file
void writePatientQueueToFile(FILE* file, pLine* queue)
{
    // Initialize current node
    pInLine* current = queue->head;
    // Initialize position counter
    int position = 1;
    // Write patient queue details to file
    while (current != NULL)
    {
        fprintf(file, "%d.%s\n", position, current->lpatient->ID);
        // Move to the next patient in line
        current = current->next;
        // Increment position counter
        position++;
    }
}