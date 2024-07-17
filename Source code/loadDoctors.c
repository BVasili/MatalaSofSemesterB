#include"loadDoctors.h"
#include<stdio.h>
#include<stdlib.h>
#include<string>

NodeDoc* loadDoctors() {
	char DocName[NAME_SIZE] = { 0 }, nLicense[LICENSE_SIZE] = { 0 }, nPatientsRead[3] = { 0 }, Line[LINE_SIZE] = { 0 };
	int nPatients = 0, firstRead = 0;

	FILE* DocsFile = fopen("Doctors.txt", "r");
	if (!DocsFile) {
		printf("FILE DIDN'T OPEN\n");
		exit(1);
	}

	fseek(DocsFile, 98, SEEK_CUR); // Adjust to the first letter

	NodeDoc* head = NULL;

	while (fgets(Line, sizeof(Line), DocsFile)) {
		if (sscanf(Line, "%[^;]; %[^;]; %[^;]", DocName, nLicense, nPatientsRead) != 3) {
			printf("Error reading line: %s\n", Line);
			continue;
		}

		nPatients = atoi(nPatientsRead);

		Doc temp = { 0 };
		temp.Name = (char*)malloc(strlen(DocName) + 1);
		if (!temp.Name) {
			printf("allocation failed\n");
			exit(1);
		}

		strcpy(temp.Name, DocName);
		strcpy(temp.nLicense, nLicense);
		temp.nPatients = nPatients;

		if (firstRead) {
			head = addSorted(&temp, head);
		}
		else {
			head = addFirst(&temp, head);
			firstRead = 1;
		}

		// Clear the temporary line and name buffers
		Line[0] = '\0';
	}

	fclose(DocsFile);
	PrintDocList(head);
	return head;
}