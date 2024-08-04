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

	if (checkPointer(Ptr2File, CANNOT_OPEN_FILE)) // checks if file opened
		return;

	//get to first patients in file
	fseek(Ptr2File, 46, SEEK_CUR); 
	fgets(Line, sizeof(Line), Ptr2File);

	if (strcmp(Line, " ") == 0) //if file is empty it returns
		return;

	while (!feof(Ptr2File))
	{
		sscanf(Line, "%*d.%[^\n]",ID); //Copies ID from file to Temporary ID 
	
		enLine(PatientsLine,ID,tree); // Adds Temporary ID to Line queue

		if (strcmp(Line, " ") == 0) // If end of file it will break out of function
			break;

		fgets(Line, sizeof(Line), Ptr2File); //Gets next line from file
		strcpy(ID, "\0");  // resets temporary ID
	}

	fclose(Ptr2File);
}
