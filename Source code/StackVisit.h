#include"Structure.h"
#include"Stack.h"


//Function declaration for visit

void Visit_initStack(Stack* s);
void Visit_destroyStack(Stack* s);
void Visit_push(Stack* s, Visit Visit);
Visit Visit_pop(Stack* s);
Visit Visit_peekStack(const Stack* s);
int Visit_isEmptyStack(const Stack* s);
void Visit_printStack(Stack* s);
int Visit_getStackSize(const Stack* s);
