#include"displayError.h"
#include <stdio.h>

void displayError(int error)
{
	if (ALLOCATION_FAILED)
		printf("Error: Cannot allocate memory.\n");

	if (CANNOT_OPEN_FILE)
		printf("Error: Cannot open the desired file.\n");

	if (NULL_POINTER)
		printf("Error: Cannot accses NULL pointer.\n");

	return;
}
int checkPointer(void* ptr, int error) {
	int flag = 0;
	
	if (!ptr) {
		displayError(error);
		flag = 1;
	}
	//return 1 if there is a problem
	return flag;
}