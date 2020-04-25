#include "stack.h"
#include "variable.h"

STACK *Push(STACK *phead, char v)
{
    STACK *pnew = calloc(1, sizeof(STACK));
    pnew->pnext = phead;
    pnew->value = v;
    return pnew;
}

STACK *Pop(STACK *phead)
{
    STACK *pnew = phead->pnext;
    free(phead);
    return pnew;
}

int IsEmpty(STACK *phead)
{
    if(phead)
        return 0;
    return 1;
}

STACK *NewAddTOStack(STACK *phead, VARIABLE* pvar, char v)
{
    STACK *temp = (STACK *)malloc(sizeof(STACK));
    if(v>='a'&& v<='z')
    {
        temp->isInt = 1;
        temp->valueInt = FindValue(pvar, v);
    }
    else
    {
        temp->value = v;
        temp->isInt = 0;
    }
    temp->pnext=phead;
    return temp;
}