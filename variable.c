#include "variable.h"
#include <stdlib.h>

VARIABLE *AddVariable(VARIABLE *head, char vname, int value)
{
    VARIABLE *temp = (VARIABLE *)malloc(sizeof(VARIABLE));
    temp->vname = vname;
    temp->value = value;
    temp->vnext = head;
    return temp;
}

int FindValue(VARIABLE *head, char vname)
{
    if (head)
    {
        VARIABLE *p = head;
        while (p->vnext)
        {
            if (p->vname == vname)
                return p->value;
            p = p->vnext;
        }
        if (p->vname == vname)
            return p->value;
        return -1000;
    }
    else
    {
        return -1000;
    }
    
}
