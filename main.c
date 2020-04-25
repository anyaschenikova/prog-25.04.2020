#include "stack.h"
#include "variable.h"
#include <stdio.h>
#include <string.h>
#define SIZE 100

int ReturnZnach(int first, int second, char oper)
{
    if (oper == '+')
        return first + second;
    if (oper == '-')
        return first - second;
    if (oper == '*')
        return first * second;
    if (oper == '/')
        return first / second;
}

int ReturnPriority(char a)
{
    if (a == '*' || a == '/')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else if (a == '(')
        return 1;
}

int main()
{
    char str[SIZE];
    scanf("%s", str);
    char *str_out = (char *)calloc(100, sizeof(char));
    STACK *s = 0;
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str_out[j++] = str[i];
        else if (str[i] == '(')
            s = Push(s, '(');
        else if (str[i] == ')')
        {
            while (s->value != '(')
            {
                str_out[j++] = s->value;
                s = Pop(s);
            }
            s = Pop(s);
        }
        else if (IsEmpty(s) || ReturnPriority(s->value) < ReturnPriority(str[i]))
            s = Push(s, str[i]);
        else if (ReturnPriority(s->value) >= ReturnPriority(str[i]))
        {
            while (!IsEmpty(s) && ReturnPriority(s->value) >= ReturnPriority(str[i]))
            {
                str_out[j++] = s->value;
                s = Pop(s);
            }
            s = Push(s, str[i]);
        }
    }
    while (!IsEmpty(s))
    {
        str_out[j++] = s->value;
        s = Pop(s);
    }
    printf("%s\n", str_out);
    VARIABLE *v = NULL;
    for (int i = 0; i < strlen(str_out); i++)
    {
        if (str_out[i] >= 'a' && str_out[i] <= 'z' && FindValue(v, str_out[i]) == -1000)
        {
            printf("Give value for %c\n", str_out[i]);
            int temp;
            scanf("%d", &temp);
            v = AddVariable(v, str_out[i], temp);
        }
    }
    STACK *new_s = NULL;
    for (int i = strlen(str_out) - 1; i >= 0; i--)
        new_s = NewAddTOStack(new_s, v, str_out[i]);
    while (new_s->pnext)
    {
        STACK *p = new_s;
        STACK *pprev = NULL;
        while (p->pnext->pnext->isInt)
        {
            pprev = p;
            p = p->pnext;
        }
        
        int first = p->valueInt;
        int second = p->pnext->valueInt;
        char oper = p->pnext->pnext->value;
        p = Pop(p);
        p = Pop(p);
        if(pprev)
            pprev->pnext = p;
        else
        {
            new_s = p;
        }
        
        p->valueInt = ReturnZnach(first, second, oper);
    }
    printf("%d\n", new_s->valueInt);
}
