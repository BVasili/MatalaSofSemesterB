#include "loadDoctors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortDocList.h"

void loadDoctors(List* ListADT, char* FileName) {

	char DocName[NAME_SIZE] = { 0 }, nLicense[LICENSE_SIZE] = { 0 }, nPatientsRead[3] = { 0 }, Line[LINE_SIZE] = { 0 };
	int nPatients = 0, firstRead = 0;

	Doc tempDoctor = { 0 };

	FILE* DocsFile = fopen(FileName, "r");
	if (checkPointer(DocsFile, CANNOT_OPEN_FILE))
		return;
	/*if (!DocsFile) {
		displayError(CANNOT_OPEN_FILE);
		return;
	}*/

	fseek(DocsFile, 98, SEEK_CUR); // Adjust to the first letter

	while (fgets(Line, sizeof(Line), DocsFile)) {


		if (sscanf(Line, "%[^;]; %[^;]; %[^;]", DocName, nLicense, nPatientsRead) != 3) {
			printf("Error reading line: %s\n", Line);
			continue;
		}

		nPatients = atoi(nPatientsRead);

		tempDoctor.Name = (char*)malloc(strlen(DocName) + 1);
		if (!tempDoctor.Name) {
			displayError(ALLOCATION_FAILED);
			return;
		}

		strcpy(tempDoctor.Name, DocName);
		strcpy(tempDoctor.nLicense, nLicense);
		tempDoctor.nPatients = nPatients;
		if (firstRead == 0) 
		{
		Doc_addToHead(ListADT, tempDoctor);
		firstRead++;
		}
		else
		{
			ListADT->head = docsSortList(ListADT, tempDoctor);
		}
		// Clear the tempDoctororary line and name buffers
		strcpy(DocName, "\0");
		strcpy(nLicense, "\0");
		strcpy(nPatientsRead, "\0");
		nPatients = 0;
		Line[0] = '\0';

	}
	//sort list func
	fclose(DocsFile);
	return;
}