#include"assignDoctor2case.h"

Node* removeNode(Node* head, Node* node) {
    if (head == NULL) {
        return NULL;
    }

    if (head == node) {
        return head->next;
    }

    Node* current = head;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
    }

    return head;
}

// Function to insert a node in sorted order based on nPatients
Node* insertSorted(Node* head, Node* newNode) {
    if (head == NULL || newNode->Doctor.nPatients <= head->Doctor.nPatients) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->Doctor.nPatients < newNode->Doctor.nPatients) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Function to assign a doctor to a case
Node* assignDoc2Case(List* DoctorsList) {
    if (DoctorsList == NULL || DoctorsList->head == NULL) {
        printf("List of doctors is empty\n");
        return NULL;
    }

    Node* temp = DoctorsList->head;
    Node* selectedDoctor = NULL;

    // Find the first doctor with fewer than 4 patients
    while (temp != NULL) {
        if (temp->Doctor.nPatients < 4) {
            selectedDoctor = temp;
            break;
        }
        temp = temp->next;
    }

    if (selectedDoctor == NULL) {
        printf("\t### THERE ARE NO AVAILABLE DOCTORS ###\n");
        return NULL;
    }

    // Print available doctors and their patient count
    temp = DoctorsList->head;
    while (temp != NULL) {
        if (temp->Doctor.nPatients < 4) {
            printf("NAME: %s is available and has %d active patients\n", temp->Doctor.Name, temp->Doctor.nPatients);
        }
        temp = temp->next;
    }
    printf("\n\n");

    // Increment the patient count of the selected doctor
    selectedDoctor->Doctor.nPatients++;

    // Remove the selected doctor from its current position
    DoctorsList->head = removeNode(DoctorsList->head, selectedDoctor);

    // Re-insert the doctor into the list in sorted order
    DoctorsList->head = insertSorted(DoctorsList->head, selectedDoctor);

    return selectedDoctor;
}
