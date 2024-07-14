#include "CheckDynamicAllocation.h"

void CheckDynamicAllocation(void* ptr)
{
	if (!ptr) {
		printf("Cannot allocate memory");
		exit(CANNOT_ALLOCATE_MEMORY);
	}
}
