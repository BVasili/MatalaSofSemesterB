#include"displayError.h"
#include <stdio.h>

void displayError(int error)
{
	if (ALLOCATION_FAILED)
		printf("Error: Cannot allocate memory.\n");

	if (CANNOT_OPEN_FILE)
		printf("Error: Cannot open the desired file.\n");

	return;
}