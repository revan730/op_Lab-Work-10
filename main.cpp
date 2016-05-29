#include <iostream>
#include "stack.h"
#include <string.h>

using namespace std;

void inputText();
void pushStack(char);
int popStack(char*);
void outputText();

SNode *top = NULL;
int main()
{
    inputText();
    outputText();
    return 0;
}

void inputText()
{
    char s[1000];
    printf("Input text\n");
    while ((fgets(s,1000,stdin) != NULL) && s[0] !='\7')
    {
        for (unsigned int i = 0;i < strlen(s);i++)
            pushStack(s[i]);
    }
}

void outputText()
{
    char c;
    while (popStack(&c) == 1)
    {
        printf("%c",c);
    }
}

void pushStack(char c)
{
    if (top == NULL)
    {
        top = new SNode;
        top->next = NULL;
        top->data = c;
    }
    else
    {
        SNode *temp = new SNode;
        temp->next = top;
        temp->data = c;
        top = temp;
    }
}

int popStack(char *c)
{
 if (top == NULL)
        return 0;
 else
 {
     SNode *temp = top;
     *c = top->data;
     temp = temp->next;
     delete top;
     top = temp;
     return 1;
 }
}
