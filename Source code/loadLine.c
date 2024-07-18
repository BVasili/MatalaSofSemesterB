#include "loadLine.h"
#include<string.h>

//void loadLine(Queue* PatientsQueue, char* FileName,pTree* tree)
//{
//	char ID[ID_SIZE] = { 0 };
//	char Line[100] = { 0 };
//
//	FILE* Ptr2File = fopen(FileName,"r");
//
//	if (!Ptr2File)
//	{
//		displayError(CANNOT_OPEN_FILE);
//		return;
//	}
//
//	fseek(Ptr2File, 46, SEEK_CUR);
//	fgets(Line, sizeof(Line), Ptr2File);
//
//	if (strcmp(Line, " ") == 0)
//		return;
//
//	while (!feof(Ptr2File))
//	{
//
//		printf("%s", Line);
//		sscanf(Line, "%*d.%[^\n]",ID);
//
//		Line_enqueue(PatientsQueue, searchPatient(tree, ID));
//
//		//printf("%s", ID);
//		
//		if (strcmp(Line, " ") == 0)
//			break;
//		fgets(Line, sizeof(Line), Ptr2File);
//		strcpy(ID, "\0");
//	}
//	fclose(Ptr2File);
//}
