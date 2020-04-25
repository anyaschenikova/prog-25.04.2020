#ifndef VARIABLE_H
#define VARIABLE_H


typedef struct variable {
    char vname;
    int value;
    struct variable * vnext;
}VARIABLE;

VARIABLE *AddVariable(VARIABLE * head, char vname, int value);

int FindValue(VARIABLE * head, char vname);

#endif