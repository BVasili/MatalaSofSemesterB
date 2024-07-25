#include "loadLine.h"
#include "pLine.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void loadLine(pLine* PatientsLine, char* FileName,pTree* tree)
{
	char ID[ID_SIZE] = { 0 };
	char Line[100] = { 0 };

	FILE* Ptr2File = fopen(FileName,"r");

	if (!Ptr2File)
	{
		displayError(CANNOT_OPEN_FILE);
		return;
	}

	//get to first patients in file
	fseek(Ptr2File, 46, SEEK_CUR); 
	fgets(Line, sizeof(Line), Ptr2File);

	if (strcmp(Line, " ") == 0)
		return;

	while (!feof(Ptr2File))
	{
		sscanf(Line, "%*d.%[^\n]",ID);
	
		enLine(PatientsLine,ID,tree);

		if (strcmp(Line, " ") == 0)
			break;

		fgets(Line, sizeof(Line), Ptr2File);
		strcpy(ID, "\0");
	}
	fclose(Ptr2File);
}
