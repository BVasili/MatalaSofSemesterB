#pragma once
#ifndef DISLPAYERROR_HEADER__
#define DISLPAYERROR_HEADER__

#define ALLOCATION_FAILED 1
#define CANNOT_OPEN_FILE 2
#define NULL_POINTER 3

void displayError(int);
int checkPointer(void*, int);

#endif // DISLPAYERROR_HEADER__