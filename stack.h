#ifndef STACK_H
#define STACK_H

#include "stdlib.h"
#include "variable.h"

typedef struct stack
{
    char value;
    int valueInt;
    int isInt;
    struct stack *pnext;
} STACK;

STACK *Push(STACK *phead, char v);

STACK *Pop(STACK *phead);

int IsEmpty(STACK *phead);

STACK *NewAddTOStack(STACK *phead, VARIABLE *pvar, char v);

#endif